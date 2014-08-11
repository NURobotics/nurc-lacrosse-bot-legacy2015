cmake_minimum_required(VERSION 2.6)
project(lacrosse-bot)

find_package(OpenCV REQUIRED)
find_package(Eigen REQUIRED)

include_directories(
	"include"
	"/usr/include/eigen3"
	"/usr/local/include/opencv2"
#	"/usr/local/include/opnecv"
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_definitions(
	-std=c++0x
)


add_library(Algorithms
	src/Algorithm.cpp
)

add_library(Filters
	src/ThresholdFilter.cpp
	src/KalmanFilter.cpp
)

add_library(Trackers
	src/Tracker.cpp
	src/Ball2DTracker.cpp
)

add_executable(ThresholdFilter src/ThresholdFilter.cpp)
target_link_libraries(ThresholdFilter
	${OpenCV_LIBRARIES}
	Algorithms
)

add_executable(Ball2DTracker src/Ball2DTracker.cpp)
target_link_libraries(Ball2DTracker
#	${OpenCV_LIBRARIES}
	
	opencv_core
	opencv_imgproc
	opencv_highgui
	opencv_ml
	opencv_video
	opencv_features2d
	opencv_calib3d
	opencv_objdetect
	opencv_contrib
	opencv_legacy
	opencv_stitching	

	${Eigen_LIBRARIES}
	Filters
	Algorithms
	Trackers
)
