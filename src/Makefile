CXX = g++
CV_INCL_LOCATION = -I/usr/local/include/opencv -I/usr/local/include/opencv2
CV_LIB_LOCATION =  -L/usr/local/lib/
CV_LIB = -lopencv_core \
				-lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video \
				-lopencv_features2d -lopencv_calib3d -lopencv_objdetect \
				-lopencv_contrib -lopencv_legacy -lopencv_stitching

default: BallTracker.cpp
	${CXX} ${CV_INCL_LOCATION} ${CV_LIB_LOCATION} -g -o ../bin/BallTracker BallTracker.cpp ${CV_LIB}

all: default

clean:
	( cd ../bin; rm -f *; )
