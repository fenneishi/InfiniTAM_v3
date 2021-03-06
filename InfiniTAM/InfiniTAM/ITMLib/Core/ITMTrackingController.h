// Copyright 2014-2017 Oxford University Innovation Limited and the authors of InfiniTAM

#pragma once

#include <stdexcept>

#include "../Engines/Visualisation/Interface/ITMSurfelVisualisationEngine.h"
#include "../Engines/Visualisation/Interface/ITMVisualisationEngine.h"
#include "../Trackers/Interface/ITMTracker.h"
#include "../Utils/ITMLibSettings.h"

/*--------------------------------------------------------------------------------------------------------------------------------------------
VO所需的头文件*/
// 各种头文件
// C++标准库
#include <fstream>
#include <vector>
#include <map>
using namespace std;

// Eigen
//#include <Eigen/Core>
//#include <Eigen/Geometry>

// OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>


// PCL
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/common/transforms.h>
//#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/voxel_grid.h>

#include "../Utils/ITMImageTypes.h"
#include "../../ORUtils/MemoryDeviceType.h" // 调用T GetElement(int n, MemoryDeviceType memoryType)接口所需。
//------------------------------------------------------------------------------------------------------------------------------------------




namespace ITMLib
{
	/** \brief
	*/


	class ITMTrackingController
	{
	private:
		const ITMLibSettings *settings;
		ITMTracker *tracker;
	public:


        void ITMUChar4Image_to_Mat(const ITMUChar4Image *rgb,cv::Mat &rgb_Mat)
        {
            std::cout<<"size.x:"<<rgb->noDims.x<<",size.y:"<<rgb->noDims.y<<std::endl;
            for (int m = 0; m < rgb->noDims.y; m++)
            {
                for (int n=0; n < rgb->noDims.x; n++)
                {
                    rgb_Mat.ptr<uchar>(m)[n*3+2]=rgb->GetElement(m*(rgb->noDims.x)+n,MEMORYDEVICE_CPU).r;
                    rgb_Mat.ptr<uchar>(m)[n*3+1]=rgb->GetElement(m*(rgb->noDims.x)+n,MEMORYDEVICE_CPU).g;
                    rgb_Mat.ptr<uchar>(m)[n*3]  =rgb->GetElement(m*(rgb->noDims.x)+n,MEMORYDEVICE_CPU).b;
//                    std::cout<<"r"<<(int)rgb->GetElement(m*(rgb->noDims.x)+n,MEMORYDEVICE_CPU).r;
//                    std::cout<<"g"<<(int)rgb->GetElement(m*(rgb->noDims.x)+n,MEMORYDEVICE_CPU).g;
//                    std::cout<<"b"<<(int)rgb->GetElement(m*(rgb->noDims.x)+n,MEMORYDEVICE_CPU).b<<" ";
                }
//                std::cout<<std::endl;
            }


        }


	    void VO_initialize(ITMTrackingState *trackingState, const ITMView *view)
        {
            // 建立特征提取器与描述子提取器(ORB)
            cv::Ptr<cv::FeatureDetector> detector;
            cv::Ptr<cv::DescriptorExtractor> descriptor;
            detector = cv::ORB::create();
            descriptor = cv::ORB::create();
//            detector = cv::FeatureDetector::create("ROB");
//            descriptor = cv::DescriptorExtractor::create("ORB");


            //格式转换：ITMUChar4Image--->cv:Mat(int rows, int cols, int type);
            cv::Mat rgb_prev_Mat(view->rgb_prev->noDims.y,view->rgb_prev->noDims.x,CV_8UC3);
            ITMUChar4Image_to_Mat(view->rgb_prev,rgb_prev_Mat);
            cv::Mat rgb_curr_Mat(view->rgb->noDims.y,view->rgb->noDims.x,CV_8UC3);
            ITMUChar4Image_to_Mat(view->rgb,rgb_curr_Mat);

            // 显示转换结果rgb_prev_Mat;
            cv::namedWindow("rgb_prev", cv::WINDOW_AUTOSIZE);
            cv::imshow("rgb_prev", rgb_prev_Mat);
            cv::waitKey(0);
            cv::destroyWindow("rgb_prev");

            // 提取关键点
            vector< cv::KeyPoint > kp_pre, kp_curr;
            detector->detect( rgb_prev_Mat, kp_pre );
            detector->detect( rgb_curr_Mat, kp_curr );

            // 计算描述子
            cv::Mat desp_pre, desp_curr;
            descriptor->compute( rgb_prev_Mat, kp_pre, desp_pre );
            descriptor->compute( rgb_curr_Mat, kp_curr, desp_curr );

            // 匹配描述子
            vector< cv::DMatch > matches;
            cv::FlannBasedMatcher matcher;
            // https://stackoverflow.com/questions/11565255/opencv-flann-with-orb-descriptors?answertab=votes#tab-top
            if(desp_pre.type()!=CV_32F) {
                desp_pre.convertTo(desp_pre, CV_32F);
            }
            if(desp_curr.type()!=CV_32F) {
                desp_curr.convertTo(desp_curr, CV_32F);
            }
            if(desp_pre.empty()||desp_curr.empty())
            {
                std::cout<<"descriptor empty"<<std::endl;
            } else
            {
                matcher.match( desp_pre, desp_curr, matches );
            }
            cout<<"Find total "<<matches.size()<<" matches."<<endl;

            // 可视化：显示匹配的特征
            cv::Mat imgMatches;
            cv::drawMatches( rgb_prev_Mat, kp_pre,rgb_curr_Mat,kp_curr, matches, imgMatches );
            cv::imshow( "matches", imgMatches );
            cv::imwrite( "../../matches.png", imgMatches );
            cv::waitKey( 0 );

            // 筛选匹配，把距离太大的去掉
            // 这里使用的准则是去掉大于四倍最小距离的匹配
            vector< cv::DMatch > goodMatches;
            double minDis = 9999;
            for ( size_t i=0; i<matches.size(); i++ )
            {
                if ( matches[i].distance < minDis )
                    minDis = matches[i].distance;
            }
            for ( size_t i=0; i<matches.size(); i++ )
            {
                if (matches[i].distance < 2*minDis)
                    goodMatches.push_back( matches[i] );
            }

            // 可视化：显示筛选后的结果。
            cout<<"good matches="<<goodMatches.size()<<endl;

            cv::drawMatches( rgb_prev_Mat, kp_pre,rgb_curr_Mat,kp_curr, goodMatches, imgMatches );
            cv::imshow( "goodmatches", imgMatches );
            cv::imwrite( "../../goodmatches.png", imgMatches );
            cv::waitKey( 0 );

        }






		void Track(ITMTrackingState *trackingState, const ITMView *view)
		{
			std::cout<<"view state(noReSet)"<<view->rgb_prev->NoReSet<<std::endl;
			if(view->rgb_prev->NoReSet==0)
            {
			    VO_initialize(trackingState,view);
            }

		    tracker->TrackCamera(trackingState, view);
		}

		template <typename TSurfel>
		void Prepare(ITMTrackingState *trackingState, const ITMSurfelScene<TSurfel> *scene, const ITMView *view,
			const ITMSurfelVisualisationEngine<TSurfel> *visualisationEngine, ITMSurfelRenderState *renderState)
		{
			if (!tracker->requiresPointCloudRendering())
				return;

			//render for tracking
			bool requiresColourRendering = tracker->requiresColourRendering();
			bool requiresFullRendering = trackingState->TrackerFarFromPointCloud() || !settings->useApproximateRaycast;

			if(requiresColourRendering)
			{
				// TODO: This should be implemented at some point.
				throw std::runtime_error("The surfel engine doesn't yet support colour trackers");
			}
			else
			{
				const bool useRadii = true;
				visualisationEngine->FindSurface(scene, trackingState->pose_d, &view->calib.intrinsics_d, useRadii, USR_FAUTEDEMIEUX, renderState);
				trackingState->pose_pointCloud->SetFrom(trackingState->pose_d);

				if(requiresFullRendering)
				{
					visualisationEngine->CreateICPMaps(scene, renderState, trackingState);
					trackingState->pose_pointCloud->SetFrom(trackingState->pose_d);
					if (trackingState->age_pointCloud==-1) trackingState->age_pointCloud=-2;
					else trackingState->age_pointCloud = 0;
				}
				else
				{
					trackingState->age_pointCloud++;
				}
			}
		}

		template <typename TVoxel, typename TIndex>
		void Prepare(ITMTrackingState *trackingState, const ITMScene<TVoxel,TIndex> *scene, const ITMView *view,
			const ITMVisualisationEngine<TVoxel,TIndex> *visualisationEngine, ITMRenderState *renderState)
		{
			if (!tracker->requiresPointCloudRendering())
				return;

			//render for tracking
			bool requiresColourRendering = tracker->requiresColourRendering();
			bool requiresFullRendering = trackingState->TrackerFarFromPointCloud() || !settings->useApproximateRaycast;

			if (requiresColourRendering)
			{
				ORUtils::SE3Pose pose_rgb(view->calib.trafo_rgb_to_depth.calib_inv * trackingState->pose_d->GetM());
				visualisationEngine->CreateExpectedDepths(scene, &pose_rgb, &(view->calib.intrinsics_rgb), renderState);
				visualisationEngine->CreatePointCloud(scene, view, trackingState, renderState, settings->skipPoints);
				trackingState->age_pointCloud = 0;
			}
			else
			{
				visualisationEngine->CreateExpectedDepths(scene, trackingState->pose_d, &(view->calib.intrinsics_d), renderState);

				if (requiresFullRendering)
				{
					visualisationEngine->CreateICPMaps(scene, view, trackingState, renderState);
					trackingState->pose_pointCloud->SetFrom(trackingState->pose_d);
					if (trackingState->age_pointCloud==-1) trackingState->age_pointCloud=-2;
					else trackingState->age_pointCloud = 0;
				}
				else
				{
					visualisationEngine->ForwardRender(scene, view, trackingState, renderState);
					trackingState->age_pointCloud++;
				}
			}
		}

		ITMTrackingController(ITMTracker *tracker, const ITMLibSettings *settings)
		{
			this->tracker = tracker;
			this->settings = settings;
		}

		const Vector2i& GetTrackedImageSize(const Vector2i& imgSize_rgb, const Vector2i& imgSize_d) const
		{
			return tracker->requiresColourRendering() ? imgSize_rgb : imgSize_d;
		}

		// Suppress the default copy constructor and assignment operator
		ITMTrackingController(const ITMTrackingController&);
		ITMTrackingController& operator=(const ITMTrackingController&);
	};












}
