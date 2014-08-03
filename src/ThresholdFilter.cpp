#include <iostream>
#include <sstream>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <lacrosse-bot/filter/ThresholdFilter.hpp>
#include <lacrosse-bot/algorithm/Algorithm.hpp>


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
	std::cout << "ThresholdFilter main test initialized..." << std::endl << std::endl;

	char type = 'i';
	std::cout << "What type of test would you like to run ([i]mage|[v]ideo): ";
	std::cin >> type;
	nurc::ThresholdFilter t1(cv::Vec3b(150,0,0), cv::Vec3b(175,255,255));
	nurc::Centroid a1;
	cv::namedWindow("Test Output", CV_WINDOW_AUTOSIZE);

	if(type != 'i' && type != 'v') type = 'i';

	if(type == 'i') {
		int num_tests = 0;
		std::cout << "How many images are there: ";
		std::cin >> num_tests;
		for(int i = 0; i < num_tests; i++) {
			std::stringstream ss;
			ss << "../images/ball_test_" << i << ".jpg";
			std::string image_path = ss.str();
			std::cout << image_path << std::endl;
			cv::Mat image = cv::imread(image_path);
			
			if(image.data) {
				cv::cvtColor(image, image, cv::COLOR_BGR2HSV);
				cv::resize(image, image, cv::Size(0,0), 0.5, 0.5, cv::INTER_LANCZOS4);
				cv::GaussianBlur(image, image, cv::Size(9,9), 2, 2);
				cv::imshow("Test Output", t1(image));
				cv::waitKey(0);
			}
			else {
				std::cout << "Encountered an error..." << std::endl;
			}
		}
	}
	else if(type == 'v') {
		cv::VideoCapture video_capture(0);
		cv::Mat image(video_capture.get(CV_CAP_PROP_FRAME_HEIGHT),
							 video_capture.get(CV_CAP_PROP_FRAME_WIDTH),
							 CV_8UC3);
		
		while(cv::waitKey(1) == -1 && video_capture.isOpened()) {
			video_capture >> image;

			cv::cvtColor(image, image, cv::COLOR_BGR2HSV);
			cv::resize(image, image, cv::Size(0,0), 0.5, 0.5, cv::INTER_LANCZOS4);
			cv::GaussianBlur(image, image, cv::Size(9,9), 2, 2);
			cv::imshow("Test Output", t1(image));
			
			cv::Point centroid = a1(image);
			std::cout << "The centroid was calcualted at: (" << centroid.x << ", " << centroid.y << ")" << std::endl;
			
		}
	}

	std::cout << std::endl << "ThresholdFilter main test completed." << std::endl;
	
	return 0;
}
