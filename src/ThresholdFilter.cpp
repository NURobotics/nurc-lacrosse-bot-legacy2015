#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <lacrosse-bot/filter/ThresholdFilter.h>
#include <iostream>

namespace nurc {

Mat& ThresholdFilter::filter(Mat& image)
{
	if(mode_ == Mode::RANGE) {
		inRange(image, Scalar(lower_bound_[0],lower_bound_[1], lower_bound_[2]), Scalar(upper_bound_[0],upper_bound_[1],upper_bound_[2]), image);
	}
	else if(mode_ == Mode::TARGET) {
		// Implement simple distance filter
		
	}
	else {
		return image;
	}
	return image;
}

} // namespace nurc

int main(int argc, char **argv)
{
	std::cout << "ThresholdFilter main test initialized..." << std::endl;

	cv::VideoCapture video_capture(0);
	cv::Mat image(video_capture.get(CV_CAP_PROP_FRAME_HEIGHT),
						 video_capture.get(CV_CAP_PROP_FRAME_WIDTH),
						 CV_8UC3);
	cv::namedWindow("Output", CV_WINDOW_AUTOSIZE);
	
	nurc::ThresholdFilter t1(cv::Vec3b(150,50,50), cv::Vec3b(175,255,255));
	std::cout << t1.debug() << std::endl;
	
	while(cv::waitKey(1) == -1 && video_capture.isOpened()) {
		video_capture >> image;
		cv::cvtColor(image, image, cv::COLOR_BGR2HSV);
		cv::imshow("Output", t1(image));
	}
	
	return 0;
}
