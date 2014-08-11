#ifndef LACROSSE_BOT_BALLTRACKER_H
#define LACROSSE_BOT_BALLTRACKER_H


#include <deque>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


namespace nurc {

using namespace cv;
using namespace std;

class Tracker
{
public:
	Tracker();
	
	bool setVideoCapture(unsigned int capture);
	bool setVideoCapture(const char* capture);

	cv::VideoCapture& getVideoCapture() { return video_capture_; }
	cv::Mat& getImage() { return image_; }

	bool captureImageFrame() { if(video_capture_.isOpened()) video_capture_ >> image_; return image_.data; }
	double getRuntime() { return (1/getTickFrequency())*double(total_tick_count_); }
	unsigned int getTotalTicks() { return total_tick_count_; }

protected:
	cv::VideoCapture video_capture_;
	cv::Mat image_;

	// Time Management	
	unsigned int current_tick_count_;
	unsigned int previous_tick_count_;
	unsigned int total_tick_count_;
};

} // namespace nurc


#endif // LACROSSE_BOT_BALLTRACKER_H
