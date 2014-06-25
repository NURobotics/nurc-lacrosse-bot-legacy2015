#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <deque>

namespace nurc 
{

class BallTracker
{
public:
	BallTracker();
	
	bool setVideoCapture(unsigned int capture);
	bool setVideoCapture(const char* capture);
	cv::VideoCapture& getVideoCapture() { return video_cap_; }

	cv::Point_<unsigned int> calculateBallImageCenter(cv::Mat& image);
	cv::Point_<unsigned int> calculateBallImageCenter();
	cv::Point3_<double> calculateBallPosition(cv::Point_<unsigned int>& image_center);
	
	// Filters/Interpolation
	
	
protected:
	cv::VideoCapture video_cap_;
	cv::Mat camera_frame_;
	cv::Mat threshold_frame_;
	std::deque< std::pair< unsigned int, cv::Point3_<double> > > ball_track_;
	
	cv::Point3_<double> ball_rgb_;
	cv::Point3_<double> ball_hsv_;
};

}
