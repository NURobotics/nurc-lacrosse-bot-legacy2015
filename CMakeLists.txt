cmake_minimum_required(VERSION 2.6)
project(lacrosse-bot)

find_package(OpenCV REQUIRED)
find_package(Eigen REQUIRED)

include_directories(
	include
	${OpenCV_INCLUDE_DIRS}
	${Eigen_INCLUDE_DIRS}
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
target_link_libraries(Algorithms ${OpenCV_LIBRARIES})

add_library(Filters
	src/ThresholdFilter.cpp
	src/KalmanFilter.cpp
)
target_link_libraries(Filters Algorithms ${OpenCV_LIBRARIES} ${Eigen_LIBRARIES})

add_library(Trackers
	src/Tracker.cpp
	src/Ball2DTracker.cpp
)
target_link_libraries(Trackers Algorithms Filters ${OpenCV_LIBRARIES} ${Eigen_LIBRARIES})

add_executable(ThresholdFilterTest src/ThresholdFilterTest.cpp)
target_link_libraries(ThresholdFilterTest
	${OpenCV_LIBRARIES}
	${Eigen_LIBRARIES}
	Filters
	Algorithms
)

add_executable(Ball2DTrackerTest src/Ball2DTrackerTest.cpp)
target_link_libraries(Ball2DTrackerTest
	${OpenCV_LIBRARIES}
	${Eigen_LIBRARIES}
	Filters
	Algorithms
	Trackers
)
