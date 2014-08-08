cmake_minimum_required(VERSION 2.6)
project(lacrosse-bot)

find_package(OpenCV)

include_directories(include)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_definitions(
	-std=c++0x
)

add_executable(BallTracker src/BallTracker.cpp)
target_link_libraries(BallTracker
	${OpenCV_LIBRARIES}
)

add_library(Algorithms
	src/Algorithm.cpp
)

add_library(Filters
	src/ThresholdFilter.cpp
)

add_library(Trackers
	src/BallTracker.cpp
)

add_executable(ThresholdFilter src/ThresholdFilter.cpp)
target_link_libraries(ThresholdFilter
	${OpenCV_LIBRARIES}
	Algorithms
)
