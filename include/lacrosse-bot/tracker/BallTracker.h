#ifndef LACROSSE_BOT_BALLTRACKER_H
#define LACROSSE_BOT_BALLTRACKER_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <deque>
#include <stdio.h>
#include <stdlib.h>

namespace nurc 
{

class BallTracker
{
public:
	BallTracker();
	
	bool setVideoCapture(unsigned int capture);
	bool setVideoCapture(const char* capture);
	cv::VideoCapture& getVideoCapture() { return video_cap_; }
	cv::Mat& getCameraFrame() { return camera_frame_; }
	cv::Mat& getHsvFrame() { return hsv_frame_; }
	cv::Mat& getThresholdFrame() { return threshold_frame_; }
	bool fetchImageFrame() { if(video_cap_.isOpened()) video_cap_ >> camera_frame_; return camera_frame_.data; }

	cv::Point_<unsigned int> calculateBallImageCenter(cv::Mat& image);
	cv::Point_<unsigned int> calculateBallImageCenter();
	cv::Point3_<double> calculateBallPosition(cv::Point_<unsigned int>& image_center);

	// Visualization
	
	
	// Filters/Interpolation
	
	
protected:
	cv::VideoCapture video_cap_;
	cv::Mat camera_frame_;
	cv::Mat hsv_frame_;
	cv::Mat threshold_frame_;
	std::deque< std::pair< unsigned int, cv::Point3_<double> > > ball_track_;
	
	cv::Point3_<double> ball_rgb_;
	cv::Point3_<double> ball_hsv_;
};

} // namespace nurc

#endif
