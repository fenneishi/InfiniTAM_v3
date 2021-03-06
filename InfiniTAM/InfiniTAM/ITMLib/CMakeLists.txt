#############################
# CMakeLists.txt for ITMLib #
#############################

###########################
# Specify the target name #
###########################

SET(targetname ITMLib)

################################
# Specify the libraries to use #
################################

INCLUDE(${PROJECT_SOURCE_DIR}/cmake/UseCUDA.cmake)
INCLUDE(${PROJECT_SOURCE_DIR}/cmake/UseOpenMP.cmake)








#############################
# Specify the project files #
#############################

## toplevel
SET(ITMLIB_TOPLEVEL_CPU_SOURCES
CPUInstantiations.cpp
)

SET(ITMLIB_TOPLEVEL_CUDA_SOURCES
CUDAInstantiations.cu
)

SET(ITMLIB_TOPLEVEL_HEADERS
ITMLibDefines.h
)

## core
SET(ITMLIB_CORE_SOURCES
Core/ITMBasicEngine.tpp
Core/ITMBasicSurfelEngine.tpp
Core/ITMDenseMapper.tpp
Core/ITMDenseSurfelMapper.tpp
Core/ITMMultiEngine.tpp
)

SET(ITMLIB_CORE_HEADERS
Core/ITMBasicEngine.h
Core/ITMBasicSurfelEngine.h
Core/ITMDenseMapper.h
Core/ITMDenseSurfelMapper.h
Core/ITMMainEngine.h
Core/ITMMultiEngine.h
Core/ITMTrackingController.h
)

## lowlevel
SET(ITMLIB_ENGINES_LOWLEVEL_SOURCES
Engines/LowLevel/ITMLowLevelEngineFactory.cpp
)

SET(ITMLIB_ENGINES_LOWLEVEL_HEADERS
Engines/LowLevel/ITMLowLevelEngineFactory.h
)

##
SET(ITMLIB_ENGINES_LOWLEVEL_CPU_SOURCES
Engines/LowLevel/CPU/ITMLowLevelEngine_CPU.cpp
)

SET(ITMLIB_ENGINES_LOWLEVEL_CPU_HEADERS
Engines/LowLevel/CPU/ITMLowLevelEngine_CPU.h
)

##
SET(ITMLIB_ENGINES_LOWLEVEL_CUDA_SOURCES
Engines/LowLevel/CUDA/ITMLowLevelEngine_CUDA.cu
)

SET(ITMLIB_ENGINES_LOWLEVEL_CUDA_HEADERS
Engines/LowLevel/CUDA/ITMLowLevelEngine_CUDA.h
)

##
SET(ITMLIB_ENGINES_LOWLEVEL_INTERFACE_HEADERS
Engines/LowLevel/Interface/ITMLowLevelEngine.h
)

##
SET(ITMLIB_ENGINES_LOWLEVEL_SHARED_HEADERS
Engines/LowLevel/Shared/ITMLowLevelEngine_Shared.h
)

## meshing
SET(ITMLIB_ENGINES_MESHING_HEADERS
Engines/Meshing/ITMMeshingEngineFactory.h
Engines/Meshing/ITMMultiMeshingEngineFactory.h
)

##
SET(ITMLIB_ENGINES_MESHING_CPU_SOURCES
Engines/Meshing/CPU/ITMMeshingEngine_CPU.tpp
Engines/Meshing/CPU/ITMMultiMeshingEngine_CPU.tpp
)

SET(ITMLIB_ENGINES_MESHING_CPU_HEADERS
Engines/Meshing/CPU/ITMMeshingEngine_CPU.h
Engines/Meshing/CPU/ITMMultiMeshingEngine_CPU.h
)

##
SET(ITMLIB_ENGINES_MESHING_CUDA_SOURCES
Engines/Meshing/CUDA/ITMMeshingEngine_CUDA.tcu
Engines/Meshing/CUDA/ITMMultiMeshingEngine_CUDA.tcu
)

SET(ITMLIB_ENGINES_MESHING_CUDA_HEADERS
Engines/Meshing/CUDA/ITMMeshingEngine_CUDA.h
Engines/Meshing/CUDA/ITMMultiMeshingEngine_CUDA.h
)

##
SET(ITMLIB_ENGINES_MESHING_INTERFACE_HEADERS
Engines/Meshing/Interface/ITMMeshingEngine.h
Engines/Meshing/Interface/ITMMultiMeshingEngine.h
)

##
SET(ITMLIB_ENGINES_MESHING_SHARED_HEADERS
Engines/Meshing/Shared/ITMMeshingEngine_Shared.h
Engines/Meshing/Shared/ITMMultiMeshingEngine_Shared.h
)

##multiscene
SET(ITMLIB_ENGINES_MULTISCENE_SOURCES
Engines/MultiScene/ITMActiveMapManager.cpp
Engines/MultiScene/ITMGlobalAdjustmentEngine.cpp
Engines/MultiScene/ITMMapGraphManager.tpp
)

SET(ITMLIB_ENGINES_MULTISCENE_HEADERS
Engines/MultiScene/ITMActiveMapManager.h
Engines/MultiScene/ITMGlobalAdjustmentEngine.h
Engines/MultiScene/ITMMapGraphManager.h
)

##reconstruction
SET(ITMLIB_ENGINES_RECONSTRUCTION_SOURCES
Engines/Reconstruction/ITMSurfelSceneReconstructionEngineFactory.tpp
)

SET(ITMLIB_ENGINES_RECONSTRUCTION_HEADERS
Engines/Reconstruction/ITMSceneReconstructionEngineFactory.h
Engines/Reconstruction/ITMSurfelSceneReconstructionEngineFactory.h
)

##
SET(ITMLIB_ENGINES_RECONSTRUCTION_CPU_SOURCES
Engines/Reconstruction/CPU/ITMSceneReconstructionEngine_CPU.tpp
Engines/Reconstruction/CPU/ITMSurfelSceneReconstructionEngine_CPU.tpp
)

SET(ITMLIB_ENGINES_RECONSTRUCTION_CPU_HEADERS
Engines/Reconstruction/CPU/ITMSceneReconstructionEngine_CPU.h
Engines/Reconstruction/CPU/ITMSurfelSceneReconstructionEngine_CPU.h
)

##
SET(ITMLIB_ENGINES_RECONSTRUCTION_CUDA_SOURCES
Engines/Reconstruction/CUDA/ITMSceneReconstructionEngine_CUDA.tcu
Engines/Reconstruction/CUDA/ITMSurfelSceneReconstructionEngine_CUDA.tcu
)

SET(ITMLIB_ENGINES_RECONSTRUCTION_CUDA_HEADERS
Engines/Reconstruction/CUDA/ITMSceneReconstructionEngine_CUDA.h
Engines/Reconstruction/CUDA/ITMSurfelSceneReconstructionEngine_CUDA.h
)

##
SET(ITMLIB_ENGINES_RECONSTRUCTION_INTERFACE_SOURCES
Engines/Reconstruction/Interface/ITMSurfelSceneReconstructionEngine.tpp
)

SET(ITMLIB_ENGINES_RECONSTRUCTION_INTERFACE_HEADERS
Engines/Reconstruction/Interface/ITMSceneReconstructionEngine.h
Engines/Reconstruction/Interface/ITMSurfelSceneReconstructionEngine.h
)

##
SET(ITMLIB_ENGINES_RECONSTRUCTION_SHARED_HEADERS
Engines/Reconstruction/Shared/ITMSceneReconstructionEngine_Shared.h
Engines/Reconstruction/Shared/ITMSurfelSceneReconstructionEngine_Shared.h
)

##swapping
SET(ITMLIB_ENGINES_SWAPPING_HEADERS
Engines/Swapping/ITMSwappingEngineFactory.h
)

##
SET(ITMLIB_ENGINES_SWAPPING_CPU_SOURCES
Engines/Swapping/CPU/ITMSwappingEngine_CPU.tpp
)

SET(ITMLIB_ENGINES_SWAPPING_CPU_HEADERS
Engines/Swapping/CPU/ITMSwappingEngine_CPU.h
)

##
SET(ITMLIB_ENGINES_SWAPPING_CUDA_SOURCES
Engines/Swapping/CUDA/ITMSwappingEngine_CUDA.tcu
)

SET(ITMLIB_ENGINES_SWAPPING_CUDA_HEADERS
Engines/Swapping/CUDA/ITMSwappingEngine_CUDA.h
)

##
SET(ITMLIB_ENGINES_SWAPPING_INTERFACE_HEADERS
Engines/Swapping/Interface/ITMSwappingEngine.h
)

##
SET(ITMLIB_ENGINES_SWAPPING_SHARED_HEADERS
Engines/Swapping/Shared/ITMSwappingEngine_Shared.h
)

##viewbuilding
SET(ITMLIB_ENGINES_VIEWBUILDING_SOURCES
Engines/ViewBuilding/ITMViewBuilderFactory.cpp
)

SET(ITMLIB_ENGINES_VIEWBUILDING_HEADERS
Engines/ViewBuilding/ITMViewBuilderFactory.h
)

##
SET(ITMLIB_ENGINES_VIEWBUILDING_CPU_SOURCES
Engines/ViewBuilding/CPU/ITMViewBuilder_CPU.cpp
)

SET(ITMLIB_ENGINES_VIEWBUILDING_CPU_HEADERS
Engines/ViewBuilding/CPU/ITMViewBuilder_CPU.h
)

##
SET(ITMLIB_ENGINES_VIEWBUILDING_CUDA_SOURCES
Engines/ViewBuilding/CUDA/ITMViewBuilder_CUDA.cu
)

SET(ITMLIB_ENGINES_VIEWBUILDING_CUDA_HEADERS
Engines/ViewBuilding/CUDA/ITMViewBuilder_CUDA.h
)

##
SET(ITMLIB_ENGINES_VIEWBUILDING_INTERFACE_HEADERS
Engines/ViewBuilding/Interface/ITMViewBuilder.h
)

##
SET(ITMLIB_ENGINES_VIEWBUILDING_SHARED_HEADERS
Engines/ViewBuilding/Shared/ITMViewBuilder_Shared.h
)

##visualisation
SET(ITMLIB_ENGINES_VISUALISATION_SOURCES
Engines/Visualisation/ITMSurfelVisualisationEngineFactory.tpp
)

SET(ITMLIB_ENGINES_VISUALISATION_HEADERS
Engines/Visualisation/ITMMultiVisualisationEngineFactory.h
Engines/Visualisation/ITMSurfelVisualisationEngineFactory.h
Engines/Visualisation/ITMVisualisationEngineFactory.h
)

##
SET(ITMLIB_ENGINES_VISUALISATION_CPU_SOURCES
Engines/Visualisation/CPU/ITMMultiVisualisationEngine_CPU.tpp
Engines/Visualisation/CPU/ITMSurfelVisualisationEngine_CPU.tpp
Engines/Visualisation/CPU/ITMVisualisationEngine_CPU.tpp
)

SET(ITMLIB_ENGINES_VISUALISATION_CPU_HEADERS
Engines/Visualisation/CPU/ITMMultiVisualisationEngine_CPU.h
Engines/Visualisation/CPU/ITMSurfelVisualisationEngine_CPU.h
Engines/Visualisation/CPU/ITMVisualisationEngine_CPU.h
)

##
SET(ITMLIB_ENGINES_VISUALISATION_CUDA_SOURCES
Engines/Visualisation/CUDA/ITMMultiVisualisationEngine_CUDA.tcu
Engines/Visualisation/CUDA/ITMSurfelVisualisationEngine_CUDA.tcu
Engines/Visualisation/CUDA/ITMVisualisationEngine_CUDA.tcu
Engines/Visualisation/CUDA/ITMVisualisationHelpers_CUDA.cu
)

SET(ITMLIB_ENGINES_VISUALISATION_CUDA_HEADERS
Engines/Visualisation/CUDA/ITMMultiVisualisationEngine_CUDA.h
Engines/Visualisation/CUDA/ITMSurfelVisualisationEngine_CUDA.h
Engines/Visualisation/CUDA/ITMVisualisationEngine_CUDA.h
Engines/Visualisation/CUDA/ITMVisualisationHelpers_CUDA.h
)

##
SET(ITMLIB_ENGINES_VISUALISATION_INTERFACE_SOURCES
Engines/Visualisation/Interface/ITMSurfelVisualisationEngine.tpp
Engines/Visualisation/Interface/ITMVisualisationEngine.cpp
)

SET(ITMLIB_ENGINES_VISUALISATION_INTERFACE_HEADERS
Engines/Visualisation/Interface/ITMMultiVisualisationEngine.h
Engines/Visualisation/Interface/ITMSurfelVisualisationEngine.h
Engines/Visualisation/Interface/ITMVisualisationEngine.h
)

##
SET(ITMLIB_ENGINES_VISUALISATION_SHARED_HEADERS
Engines/Visualisation/Shared/ITMSurfelVisualisationEngine_Settings.h
Engines/Visualisation/Shared/ITMSurfelVisualisationEngine_Shared.h
Engines/Visualisation/Shared/ITMVisualisationEngine_Shared.h
)

##object_camera
SET(ITMLIB_OBJECTS_CAMERA_SOURCES
Objects/Camera/ITMCalibIO.cpp
)

SET(ITMLIB_OBJECTS_CAMERA_HEADERS
Objects/Camera/ITMCalibIO.h
Objects/Camera/ITMDisparityCalib.h
Objects/Camera/ITMExtrinsics.h
Objects/Camera/ITMIntrinsics.h
Objects/Camera/ITMRGBDCalib.h
)

##objec_meshing
SET(ITMLIB_OBJECTS_MESHING_HEADERS
Objects/Meshing/ITMMesh.h
)

##object_misc
SET(ITMLIB_OBJECTS_MISC_HEADERS
Objects/Misc/ITMIMUCalibrator.h
Objects/Misc/ITMIMUMeasurement.h
Objects/Misc/ITMPointCloud.h
)

##object_renderstates
SET(ITMLIB_OBJECTS_RENDERSTATES_SOURCES
Objects/RenderStates/ITMSurfelRenderState.cpp
)
## object_rendstates
SET(ITMLIB_OBJECTS_RENDERSTATES_HEADERS
Objects/RenderStates/ITMRenderState.h
Objects/RenderStates/ITMRenderStateMultiScene.h
Objects/RenderStates/ITMRenderState_VH.h
Objects/RenderStates/ITMRenderStateFactory.h
Objects/RenderStates/ITMSurfelRenderState.h
)

##object_scene
SET(ITMLIB_OBJECTS_SCENE_HEADERS
Objects/Scene/ITMGlobalCache.h
Objects/Scene/ITMLocalMap.h
Objects/Scene/ITMLocalVBA.h
Objects/Scene/ITMMultiSceneAccess.h
Objects/Scene/ITMPlainVoxelArray.h
Objects/Scene/ITMRepresentationAccess.h
Objects/Scene/ITMScene.h
Objects/Scene/ITMSurfelScene.h
Objects/Scene/ITMSurfelTypes.h
Objects/Scene/ITMVoxelBlockHash.h
Objects/Scene/ITMVoxelTypes.h
)

##object_tracking
SET(ITMLIB_OBJECTS_TRACKING_HEADERS
Objects/Tracking/ITMDepthHierarchyLevel.h
Objects/Tracking/ITMImageHierarchy.h
Objects/Tracking/ITMIntensityHierarchyLevel.h
Objects/Tracking/ITMRGBHierarchyLevel.h
Objects/Tracking/ITMSceneHierarchyLevel.h
Objects/Tracking/ITMTemplatedHierarchyLevel.h
Objects/Tracking/ITMTrackingState.h
Objects/Tracking/ITMViewHierarchyLevel.h
Objects/Tracking/TrackerIterationType.h
)

##object_views
SET(ITMLIB_OBJECTS_VIEWS_HEADERS
Objects/Views/ITMView.h
Objects/Views/ITMViewIMU.h
)



##trackers
SET(ITMLIB_TRACKERS_HEADERS
Trackers/ITMTrackerFactory.h
)

##
SET(ITMLIB_TRACKERS_CPU_SOURCES
Trackers/CPU/ITMColorTracker_CPU.cpp
Trackers/CPU/ITMDepthTracker_CPU.cpp
Trackers/CPU/ITMExtendedTracker_CPU.cpp
)

SET(ITMLIB_TRACKERS_CPU_HEADERS
Trackers/CPU/ITMColorTracker_CPU.h
Trackers/CPU/ITMDepthTracker_CPU.h
Trackers/CPU/ITMExtendedTracker_CPU.h
)

##
SET(ITMLIB_TRACKERS_CUDA_SOURCES
Trackers/CUDA/ITMColorTracker_CUDA.cu
Trackers/CUDA/ITMDepthTracker_CUDA.cu
Trackers/CUDA/ITMExtendedTracker_CUDA.cu

)

SET(ITMLIB_TRACKERS_CUDA_HEADERS
Trackers/CUDA/ITMColorTracker_CUDA.h
Trackers/CUDA/ITMDepthTracker_CUDA.h
Trackers/CUDA/ITMExtendedTracker_CUDA.h
)

##
SET(ITMLIB_TRACKERS_INTERFACE_SOURCES
Trackers/Interface/ITMColorTracker.cpp
Trackers/Interface/ITMDepthTracker.cpp
Trackers/Interface/ITMExtendedTracker.cpp
Trackers/Interface/ITMFileBasedTracker.cpp
Trackers/Interface/ITMForceFailTracker.cpp
Trackers/Interface/ITMIMUTracker.cpp
)

SET(ITMLIB_TRACKERS_INTERFACE_HEADERS
Trackers/Interface/ITMColorTracker.h
Trackers/Interface/ITMCompositeTracker.h
Trackers/Interface/ITMDepthTracker.h
Trackers/Interface/ITMExtendedTracker.h
Trackers/Interface/ITMFileBasedTracker.h
Trackers/Interface/ITMForceFailTracker.h
Trackers/Interface/ITMIMUTracker.h
Trackers/Interface/ITMTracker.h
)

##
SET(ITMLIB_TRACKERS_SHARED_HEADERS
Trackers/Shared/ITMColorTracker_Shared.h
Trackers/Shared/ITMDepthTracker_Shared.h
Trackers/Shared/ITMExtendedTracker_Shared.h
)

##utils
SET(ITMLIB_UTILS_SOURCES
Utils/ITMLibSettings.cpp
)

SET(ITMLIB_UTILS_HEADERS
Utils/ITMCUDAUtils.h
Utils/ITMImageTypes.h
Utils/ITMLibSettings.h
Utils/ITMMath.h
Utils/ITMMemoryBlockTypes.h
Utils/ITMPixelUtils.h
Utils/ITMProjectionUtils.h
Utils/ITMSceneParams.h
Utils/ITMSurfelSceneParams.h
)

#################################################################
# Collect the project files into sources, headers and templates #
#################################################################

SET(sources
${ITMLIB_TOPLEVEL_CPU_SOURCES}
${ITMLIB_TOPLEVEL_CUDA_SOURCES}
${ITMLIB_CORE_SOURCES}
${ITMLIB_ENGINES_LOWLEVEL_SOURCES}
${ITMLIB_ENGINES_LOWLEVEL_CPU_SOURCES}
${ITMLIB_ENGINES_LOWLEVEL_CUDA_SOURCES}
${ITMLIB_ENGINES_MESHING_CPU_SOURCES}
${ITMLIB_ENGINES_MESHING_CUDA_SOURCES}
${ITMLIB_ENGINES_MULTISCENE_SOURCES}
${ITMLIB_ENGINES_RECONSTRUCTION_SOURCES}
${ITMLIB_ENGINES_RECONSTRUCTION_CPU_SOURCES}
${ITMLIB_ENGINES_RECONSTRUCTION_CUDA_SOURCES}
${ITMLIB_ENGINES_RECONSTRUCTION_INTERFACE_SOURCES}
${ITMLIB_ENGINES_SWAPPING_CPU_SOURCES}
${ITMLIB_ENGINES_SWAPPING_CUDA_SOURCES}
${ITMLIB_ENGINES_VIEWBUILDING_SOURCES}
${ITMLIB_ENGINES_VIEWBUILDING_CPU_SOURCES}
${ITMLIB_ENGINES_VIEWBUILDING_CUDA_SOURCES}
${ITMLIB_ENGINES_VISUALISATION_SOURCES}
${ITMLIB_ENGINES_VISUALISATION_CPU_SOURCES}
${ITMLIB_ENGINES_VISUALISATION_CUDA_SOURCES}
${ITMLIB_ENGINES_VISUALISATION_INTERFACE_SOURCES}
${ITMLIB_OBJECTS_CAMERA_SOURCES}
${ITMLIB_OBJECTS_RENDERSTATES_SOURCES}
${ITMLIB_TRACKERS_CPU_SOURCES}
${ITMLIB_TRACKERS_CUDA_SOURCES}
${ITMLIB_TRACKERS_INTERFACE_SOURCES}
${ITMLIB_UTILS_SOURCES}
)

SET(headers
${ITMLIB_TOPLEVEL_HEADERS}
${ITMLIB_CORE_HEADERS}
${ITMLIB_ENGINES_LOWLEVEL_HEADERS}
${ITMLIB_ENGINES_LOWLEVEL_CPU_HEADERS}
${ITMLIB_ENGINES_LOWLEVEL_CUDA_HEADERS}
${ITMLIB_ENGINES_LOWLEVEL_INTERFACE_HEADERS}
${ITMLIB_ENGINES_LOWLEVEL_SHARED_HEADERS}
${ITMLIB_ENGINES_MESHING_HEADERS}
${ITMLIB_ENGINES_MESHING_CPU_HEADERS}
${ITMLIB_ENGINES_MESHING_CUDA_HEADERS}
${ITMLIB_ENGINES_MESHING_INTERFACE_HEADERS}
${ITMLIB_ENGINES_MESHING_SHARED_HEADERS}
${ITMLIB_ENGINES_MULTISCENE_HEADERS}
${ITMLIB_ENGINES_RECONSTRUCTION_HEADERS}
${ITMLIB_ENGINES_RECONSTRUCTION_CPU_HEADERS}
${ITMLIB_ENGINES_RECONSTRUCTION_CUDA_HEADERS}
${ITMLIB_ENGINES_RECONSTRUCTION_INTERFACE_HEADERS}
${ITMLIB_ENGINES_RECONSTRUCTION_SHARED_HEADERS}
${ITMLIB_ENGINES_SWAPPING_HEADERS}
${ITMLIB_ENGINES_SWAPPING_CPU_HEADERS}
${ITMLIB_ENGINES_SWAPPING_CUDA_HEADERS}
${ITMLIB_ENGINES_SWAPPING_INTERFACE_HEADERS}
${ITMLIB_ENGINES_SWAPPING_SHARED_HEADERS}
${ITMLIB_ENGINES_VIEWBUILDING_HEADERS}
${ITMLIB_ENGINES_VIEWBUILDING_CPU_HEADERS}
${ITMLIB_ENGINES_VIEWBUILDING_CUDA_HEADERS}
${ITMLIB_ENGINES_VIEWBUILDING_INTERFACE_HEADERS}
${ITMLIB_ENGINES_VIEWBUILDING_SHARED_HEADERS}
${ITMLIB_ENGINES_VISUALISATION_HEADERS}
${ITMLIB_ENGINES_VISUALISATION_CPU_HEADERS}
${ITMLIB_ENGINES_VISUALISATION_CUDA_HEADERS}
${ITMLIB_ENGINES_VISUALISATION_INTERFACE_HEADERS}
${ITMLIB_ENGINES_VISUALISATION_SHARED_HEADERS}
${ITMLIB_OBJECTS_CAMERA_HEADERS}
${ITMLIB_OBJECTS_MESHING_HEADERS}
${ITMLIB_OBJECTS_MISC_HEADERS}
${ITMLIB_OBJECTS_RENDERSTATES_HEADERS}
${ITMLIB_OBJECTS_SCENE_HEADERS}
${ITMLIB_OBJECTS_TRACKING_HEADERS}
${ITMLIB_OBJECTS_VIEWS_HEADERS}
${ITMLIB_TRACKERS_HEADERS}
${ITMLIB_TRACKERS_CPU_HEADERS}
${ITMLIB_TRACKERS_CUDA_HEADERS}
${ITMLIB_TRACKERS_INTERFACE_HEADERS}
${ITMLIB_TRACKERS_SHARED_HEADERS}
${ITMLIB_UTILS_HEADERS}
)

#############################
# Specify the source groups #
#############################

SOURCE_GROUP("" FILES ${ITMLIB_TOPLEVEL_CPU_SOURCES} ${ITMLIB_TOPLEVEL_CUDA_SOURCES} ${ITMLIB_TOPLEVEL_HEADERS})
SOURCE_GROUP(Core FILES ${ITMLIB_CORE_SOURCES} ${ITMLIB_CORE_HEADERS})
SOURCE_GROUP(Engines\\LowLevel FILES ${ITMLIB_ENGINES_LOWLEVEL_SOURCES} ${ITMLIB_ENGINES_LOWLEVEL_HEADERS})
SOURCE_GROUP(Engines\\LowLevel\\CPU FILES ${ITMLIB_ENGINES_LOWLEVEL_CPU_SOURCES} ${ITMLIB_ENGINES_LOWLEVEL_CPU_HEADERS})
SOURCE_GROUP(Engines\\LowLevel\\CUDA FILES ${ITMLIB_ENGINES_LOWLEVEL_CUDA_SOURCES} ${ITMLIB_ENGINES_LOWLEVEL_CUDA_HEADERS})
SOURCE_GROUP(Engines\\LowLevel\\Interface FILES ${ITMLIB_ENGINES_LOWLEVEL_INTERFACE_HEADERS})
SOURCE_GROUP(Engines\\LowLevel\\Shared FILES ${ITMLIB_ENGINES_LOWLEVEL_SHARED_HEADERS})
SOURCE_GROUP(Engines\\Meshing FILES ${ITMLIB_ENGINES_MESHING_HEADERS})
SOURCE_GROUP(Engines\\Meshing\\CPU FILES ${ITMLIB_ENGINES_MESHING_CPU_SOURCES} ${ITMLIB_ENGINES_MESHING_CPU_HEADERS})
SOURCE_GROUP(Engines\\Meshing\\CUDA FILES ${ITMLIB_ENGINES_MESHING_CUDA_SOURCES} ${ITMLIB_ENGINES_MESHING_CUDA_HEADERS})
SOURCE_GROUP(Engines\\Meshing\\Interface FILES ${ITMLIB_ENGINES_MESHING_INTERFACE_HEADERS})
SOURCE_GROUP(Engines\\Meshing\\Shared FILES ${ITMLIB_ENGINES_MESHING_SHARED_HEADERS})
SOURCE_GROUP(Engines\\MultiScene FILES ${ITMLIB_ENGINES_MULTISCENE_SOURCES} ${ITMLIB_ENGINES_MULTISCENE_HEADERS})
SOURCE_GROUP(Engines\\Reconstruction FILES ${ITMLIB_ENGINES_RECONSTRUCTION_SOURCES} ${ITMLIB_ENGINES_RECONSTRUCTION_HEADERS})
SOURCE_GROUP(Engines\\Reconstruction\\CPU FILES ${ITMLIB_ENGINES_RECONSTRUCTION_CPU_SOURCES} ${ITMLIB_ENGINES_RECONSTRUCTION_CPU_HEADERS})
SOURCE_GROUP(Engines\\Reconstruction\\CUDA FILES ${ITMLIB_ENGINES_RECONSTRUCTION_CUDA_SOURCES} ${ITMLIB_ENGINES_RECONSTRUCTION_CUDA_HEADERS})
SOURCE_GROUP(Engines\\Reconstruction\\Interface FILES ${ITMLIB_ENGINES_RECONSTRUCTION_INTERFACE_SOURCES} ${ITMLIB_ENGINES_RECONSTRUCTION_INTERFACE_HEADERS})
SOURCE_GROUP(Engines\\Reconstruction\\Shared FILES ${ITMLIB_ENGINES_RECONSTRUCTION_SHARED_HEADERS})
SOURCE_GROUP(Engines\\Swapping FILES ${ITMLIB_ENGINES_SWAPPING_HEADERS})
SOURCE_GROUP(Engines\\Swapping\\CPU FILES ${ITMLIB_ENGINES_SWAPPING_CPU_SOURCES} ${ITMLIB_ENGINES_SWAPPING_CPU_HEADERS})
SOURCE_GROUP(Engines\\Swapping\\CUDA FILES ${ITMLIB_ENGINES_SWAPPING_CUDA_SOURCES} ${ITMLIB_ENGINES_SWAPPING_CUDA_HEADERS})
SOURCE_GROUP(Engines\\Swapping\\Interface FILES ${ITMLIB_ENGINES_SWAPPING_INTERFACE_HEADERS})
SOURCE_GROUP(Engines\\Swapping\\Shared FILES ${ITMLIB_ENGINES_SWAPPING_SHARED_HEADERS})
SOURCE_GROUP(Engines\\ViewBuilding FILES ${ITMLIB_ENGINES_VIEWBUILDING_SOURCES} ${ITMLIB_ENGINES_VIEWBUILDING_HEADERS})
SOURCE_GROUP(Engines\\ViewBuilding\\CPU FILES ${ITMLIB_ENGINES_VIEWBUILDING_CPU_SOURCES} ${ITMLIB_ENGINES_VIEWBUILDING_CPU_HEADERS})
SOURCE_GROUP(Engines\\ViewBuilding\\CUDA FILES ${ITMLIB_ENGINES_VIEWBUILDING_CUDA_SOURCES} ${ITMLIB_ENGINES_VIEWBUILDING_CUDA_HEADERS})
SOURCE_GROUP(Engines\\ViewBuilding\\Interface FILES ${ITMLIB_ENGINES_VIEWBUILDING_INTERFACE_HEADERS})
SOURCE_GROUP(Engines\\ViewBuilding\\Shared FILES ${ITMLIB_ENGINES_VIEWBUILDING_SHARED_HEADERS})
SOURCE_GROUP(Engines\\Visualisation FILES ${ITMLIB_ENGINES_VISUALISATION_SOURCES} ${ITMLIB_ENGINES_VISUALISATION_HEADERS})
SOURCE_GROUP(Engines\\Visualisation\\CPU FILES ${ITMLIB_ENGINES_VISUALISATION_CPU_SOURCES} ${ITMLIB_ENGINES_VISUALISATION_CPU_HEADERS})
SOURCE_GROUP(Engines\\Visualisation\\CUDA FILES ${ITMLIB_ENGINES_VISUALISATION_CUDA_SOURCES} ${ITMLIB_ENGINES_VISUALISATION_CUDA_HEADERS})
SOURCE_GROUP(Engines\\Visualisation\\Interface FILES ${ITMLIB_ENGINES_VISUALISATION_INTERFACE_SOURCES} ${ITMLIB_ENGINES_VISUALISATION_INTERFACE_HEADERS})
SOURCE_GROUP(Engines\\Visualisation\\Shared FILES ${ITMLIB_ENGINES_VISUALISATION_SHARED_HEADERS})
SOURCE_GROUP(Objects\\Camera FILES ${ITMLIB_OBJECTS_CAMERA_SOURCES} ${ITMLIB_OBJECTS_CAMERA_HEADERS})
SOURCE_GROUP(Objects\\Meshing FILES ${ITMLIB_OBJECTS_MESHING_HEADERS})
SOURCE_GROUP(Objects\\Misc FILES ${ITMLIB_OBJECTS_MISC_HEADERS})
SOURCE_GROUP(Objects\\RenderStates FILES ${ITMLIB_OBJECTS_RENDERSTATES_SOURCES} ${ITMLIB_OBJECTS_RENDERSTATES_HEADERS})
SOURCE_GROUP(Objects\\Scene FILES ${ITMLIB_OBJECTS_SCENE_HEADERS})
SOURCE_GROUP(Objects\\Tracking FILES ${ITMLIB_OBJECTS_TRACKING_HEADERS})
SOURCE_GROUP(Objects\\Views FILES ${ITMLIB_OBJECTS_VIEWS_HEADERS})
SOURCE_GROUP(Trackers FILES ${ITMLIB_TRACKERS_HEADERS})
SOURCE_GROUP(Trackers\\CPU FILES ${ITMLIB_TRACKERS_CPU_SOURCES} ${ITMLIB_TRACKERS_CPU_HEADERS})
SOURCE_GROUP(Trackers\\CUDA FILES ${ITMLIB_TRACKERS_CUDA_SOURCES} ${ITMLIB_TRACKERS_CUDA_HEADERS})
SOURCE_GROUP(Trackers\\Interface FILES ${ITMLIB_TRACKERS_INTERFACE_SOURCES} ${ITMLIB_TRACKERS_INTERFACE_HEADERS})
SOURCE_GROUP(Trackers\\Shared FILES ${ITMLIB_TRACKERS_SHARED_HEADERS})
SOURCE_GROUP(Utils FILES ${ITMLIB_UTILS_SOURCES} ${ITMLIB_UTILS_HEADERS})

##########################################
# Specify the target and where to put it #
##########################################

INCLUDE(${PROJECT_SOURCE_DIR}/cmake/SetCUDALibTarget.cmake)

TARGET_LINK_LIBRARIES(${targetname} ${PCL_LIBS} ${OpenCV_LIBS})






