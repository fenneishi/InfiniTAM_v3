// Copyright 2014-2017 Oxford University Innovation Limited and the authors of InfiniTAM

#pragma once

#include <stdexcept>

#include "../Engines/Visualisation/Interface/ITMSurfelVisualisationEngine.h"
#include "../Engines/Visualisation/Interface/ITMVisualisationEngine.h"
#include "../Trackers/Interface/ITMTracker.h"
#include "../Utils/ITMLibSettings.h"

/*--------------------------------------------------------------------------------------------------------------------------------------------long
VO所需的头文件*/
// 各种头文件
// C++标准库
#include <fstream>
#include <vector>
#include <map>
using namespace std;

// Eigen
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>

// OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>


// PCL
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
//#include <pcl/common/transforms.h>
//#include <pcl/visualization/cloud_viewer.h> 在mac上，这个玩意一include进来，就会导致大量报错
#include <pcl/filters/voxel_grid.h>

//Sophus
//#include <sophus/so3.h>
//#include <sophus/se3.h>

// InfiniTAM 内部头文件
#include "../Utils/ITMImageTypes.h"
#include "../../ORUtils/MemoryDeviceType.h" // 调用T GetElement(int n, MemoryDeviceType memoryType)接口所需。
#include "../Utils/ITMMath.h"
#include "../../ORUtils/SE3Pose.h"
//------------------------------------------------------------------------------------------------------------------------------------------long




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







		void Track(ITMTrackingState *trackingState, const ITMView *view)
		{
			static int long_count=0;
            std::cout<<"--------------------------------process:"<<long_count<<"-------------------------------------"<<endl;
            std::cout<<"view state(noReSet)"<<view->rgb_prev->NoReSet<<std::endl;
			if(view->rgb_prev->NoReSet==false)
            {
//			    VO_initialize(trackingState,view);
            }
		    tracker->TrackCamera(trackingState, view);
            long_count++;
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






//            显示pts_obj
//            pcl::PointCloud<pcl::PointXYZ>::Ptr pts_obj_pcl(new pcl::PointCloud<pcl::PointXYZ>);
//            pcl::PCDWriter writer;
//            int index_pcl=0;
//            for(auto point:pts_obj)
//            {
//                pts_obj_pcl->points[index_pcl].x=point.x;
//                pts_obj_pcl->points[index_pcl].y=point.y;
//                pts_obj_pcl->points[index_pcl].z=point.z;
//                index_pcl++;
//            }
//           writer.write<pcl::PointXYZ> ("../../../pts_obj_pcl", *pts_obj_pcl, false);
//          detector = cv::FeatureDetector::create("ROB");
//          descriptor = cv::DescriptorExtractor::create("ORB");







}
