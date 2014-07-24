#include <lacrosse_bot/filter/ThresholdFilter.h>

namespace nurc {

ThresholdFilter::ThresholdFilter(Mode mode, Vec3b cmp, double threshold)
	:	mode_(mode)
		threshold_(threshold)
{
	// Initialization Code
	if(mode == Mode::CUTOFF) {
		
	}
	else if(mode == Mode::DISTANCE) {
		
	}
	else {
		
	}
}

Mat& ThresholdFilter::filter(Mat& image)
{
	if(mode == Mode::CUTOFF) {
		// Implement simple cutoff filter
	}
	else if(mode == Mode::DISTANCE) {
		// Implement simple distance filter
	}
	else {
		return image;
	}
}

} // namespace
