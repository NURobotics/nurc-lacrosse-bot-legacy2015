#include <lacrosse_bot/BallTracker.h>

using namespace cv;
using namespace std;

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
		hsv_frame_ = Mat( video_cap_.get(CV_CAP_PROP_FRAME_HEIGHT), 
												 video_cap_.get(CV_CAP_PROP_FRAME_WIDTH),
												 CV_8UC3 );
		threshold_frame_ = Mat( video_cap_.get(CV_CAP_PROP_FRAME_HEIGHT), 
												 video_cap_.get(CV_CAP_PROP_FRAME_WIDTH),
												 CV_8UC1 );
	}
	else {
		camera_frame_ = Mat( 600, 800, CV_8UC3 );
		hsv_frame_ = Mat( 600, 800, CV_8UC3 );
		threshold_frame_ = Mat( 600, 800, CV_8UC1 );
	}
}

Point_<unsigned int> BallTracker::calculateBallImageCenter()
{
	return calculateBallImageCenter(camera_frame_);
}

Point_<unsigned int> BallTracker::calculateBallImageCenter(Mat& image)
{
	if(image.channels() == 3 && video_cap_.isOpened()) {
		hsv_frame_.create( image.rows, image.cols, CV_8UC3 );
		threshold_frame_.create( image.rows, image.cols, CV_8UC1);
		Mat temp_tf = Mat( image.rows, image.cols, CV_8UC1 );
		
		cvtColor(image, hsv_frame_, COLOR_BGR2HSV);
		inRange(hsv_frame_, Scalar(150,50,50), Scalar(175,255,255), threshold_frame_);
		
		GaussianBlur(threshold_frame_, threshold_frame_, Size(9,9),2,2);
		// Canny(threshold_frame_, threshold_frame_, 100, 100*3, 3);

		Point_<unsigned int> center;
		vector<Vec3f> balls;

		HoughCircles(threshold_frame_, balls, CV_HOUGH_GRADIENT, 1, threshold_frame_.rows/8, 200, 100, 0, 0);

		for( size_t i = 0; i < balls.size(); i++ ) {
			center.x = cvRound(balls[i][0]);
			center.y = cvRound(balls[i][1]);
			int radius = cvRound(balls[i][2]);

			circle(camera_frame_, center, 3, Scalar(0,255,0), -1, 8, 0);
			circle(camera_frame_, center, radius, Scalar(0,0,255), 3, 8, 0);
			cout << "Found circle at coordinates: (" << center.x << "," << center.y << ")." << endl;
		}
		
		// Given the threshold image find circles or use histogram
		return center;
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
	
	namedWindow("Ball Tracker", CV_WINDOW_AUTOSIZE);
	namedWindow("Threshold Tracker", CV_WINDOW_AUTOSIZE);
	while(waitKey(1) == -1 && sample_tracker.fetchImageFrame()) {
		Point_<unsigned> center = sample_tracker.calculateBallImageCenter();
		imshow("Ball Tracker", sample_tracker.getCameraFrame());
		imshow("Threshold Tracker", sample_tracker.getThresholdFrame());
	}
	
	// Add functionality
	
	return 0;
}
