#include "../include/BallTracker.h"

namespace nurc
{

using namespace cv;

BallTracker::BallTracker()
{
	video_cap_ = VideoCapture(0);
	if(!video_cap_.isOpened()) {
		camera_frame_ = Mat( video_cap_.get(CV_CAP_PROP_FRAME_HEIGHT), 
												 video_cap_.get(CV_CAP_PROP_FRAME_WIDTH),
												 CV_8UC3 );
	}
	else {
		camera_frame_ = Mat( 600, 800, CV_8UC3 );
	}
}

Point_<unsigned int> BallTracker::calculateBallImageCenter()
{
	return calculateBallImageCenter(camera_frame_);
}

Point_<unsigned int> BallTracker::calculateBallImageCenter(Mat& image)
{
	if(image.depth() == 3 && video_cap_.isOpened()) {
		Mat hsv_frame = Mat( image.rows, camera_frame_.cols, CV_8UC3 );
		Mat threshold_frame = Mat( image.rows, camera_frame_.cols, CV_8U);

		cvtColor(image, hsv_frame, COLOR_BGR2HSV);
		
		for(int i = 0; i < hsv_frame.rows; i++) {
			uchar *hsv_row = hsv_frame.ptr<uchar>(i);
			uchar *threshold_row = threshold_frame.ptr<uchar>(i);

			for(int j = 0; j < hsv_frame.cols; j++) {
				if(hsv_row[hsv_frame.channels()*j] < 10 || hsv_row[hsv_frame.channels()*j] >= 345) threshold_row[j] = 255;
				else threshold_row[j] = 0;
			}
		
		}
		
		// Given the threshold image find circles or use histogram
		return Point_<unsigned int>(0,0);
	}
	else return Point_<unsigned int>(0,0);
}

Point3_<double> calculatePosition(Point_<unsigned int>& image)
{
	//No implementation yet
	return Point3_<double>(0.0, 0.0, 0.0);
}

bool BallTracker::setVideoCapture(unsigned int capture)
{
	video_cap_.open(capture);
	return video_cap_.isOpened();
}

bool BallTracker::setVideoCapture(const char* capture)
{
	video_cap_.open(capture);
	if(video_cap_.isOpened()) {
		camera_frame_.create( video_cap_.get(CV_CAP_PROP_FRAME_HEIGHT), 
												  video_cap_.get(CV_CAP_PROP_FRAME_WIDTH),
												  CV_8UC3 );
	}
	else {
		camera_frame_.create( 600, 800, CV_8UC3 );
	}
	return video_cap_.isOpened();
}

}

int main(int argc, char *argv[])
{
	nurc::BallTracker sample_tracker;
	
	// Add functionality

	return 0;
}
