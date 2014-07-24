CXX = g++
CXX_VERS = -std=c++0x
CV_INCL_LOCATION = -I/usr/local/include/opencv -I/usr/local/include/opencv2
CV_LIB_LOCATION =  -L/usr/local/lib/
INCL_LOCATION = -I/home/tgd/Code/nurobotics_ws/lacrosse_bot/include/
CV_LIB = -lopencv_core \
				-lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video \
				-lopencv_features2d -lopencv_calib3d -lopencv_objdetect \
				-lopencv_contrib -lopencv_legacy -lopencv_stitching

all: default

trackers:
	${CXX} ${CXX_VERS} ${CV_INCL_LOCATION} ${INCL_LOCATION} ${CV_LIB_LOCATION} -g -o ../bin/BallTracker BallTracker.cpp ${CV_LIB}

filters:
	${CXX} ${CXX_VERS} ${CV_INCL_LCOATION} ${INCL_LOCATION} ${CV_LIB_LOCATION} -o ../ThresholdFilter.o ThresholdFilter.cpp ${CV_LIB}

clean:
	( cd ../; rm *.o; )
	( cd ../bin; rm -f *; )
