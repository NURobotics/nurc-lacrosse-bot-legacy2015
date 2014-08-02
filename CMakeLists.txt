cmake_minimum_required(VERSION 2.6)
project(lacrosse-bot)

message("${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR}")

set(OpenCV_LIBRARIES
	opencv_core
	opencv_imgproc
	opencv_highgui
	opencv_video
	opencv_features2d
	opencv_calib3d
	opencv_objdetect
	opencv_contrib
	opencv_legacy
	opencv_stitching
)

include_directories(include)
link_directories(/usr/local/lib)

add_definitions(
	-std=c++0x
)

add_executable(BallTracker src/BallTracker.cpp)
target_link_libraries(BallTracker
	${OpenCV_LIBRARIES}
)

add_executable(ThresholdFilter src/ThresholdFilter.cpp)
target_link_libraries(ThresholdFilter
	${OpenCV_LIBRARIES}
)
