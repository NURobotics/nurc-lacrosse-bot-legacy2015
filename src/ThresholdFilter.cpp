#include <lacrosse-bot/filter/ThresholdFilter.hpp>


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

