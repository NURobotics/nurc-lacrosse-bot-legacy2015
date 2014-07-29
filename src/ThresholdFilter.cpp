#include <lacrosse-bot/filter/ThresholdFilter.h>
#include <iostream>
#include <memory>

namespace nurc {

ThresholdFilter::ThresholdFilter(Mode mode, Vec3b cmp, double tolerance) :
	mode_(mode),
	tolerance_(tolerance),
	comparison_(cmp)
{
}

ThresholdFilter::ThresholdFilter(Vec3b cutoff) :
	mode_(Mode::CUTOFF),
	comparison_(cutoff),
	tolerance_(0.0)
{
}

Mat& ThresholdFilter::filter(Mat& image)
{
	if(mode_ == Mode::CUTOFF) {
		// Implement simple cutoff filter
		
	}
	else if(mode_ == Mode::TARGET) {
		// Implement simple distance filter
		
	}
	else {
		return image;
	}
	return image;
}

} // namespace

int main(int argc, char **argv)
{
	std::cout << "ThresholdFilter main test initialized..." << std::endl;
	
	nurc::Filter *filter_set = new nurc::ThresholdFilter[10];
	nurc::ThresholdFilter t1(cv::Vec3b(0,0,0));
	for(int i = 0; i < 10; i++)
		std::cout << filter_set[0].debug() << std::endl;
	
	std::cout << t1.debug() << std::endl;
		
	return 0;
}
