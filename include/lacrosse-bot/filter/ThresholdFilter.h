#include <lacrosse-bot/filter/Filter.h>

namespace nurc {

using namespace cv;
using namespace std;

class ThresholdFilter : public Filter
{
public:
	enum class Mode 
	{
		RANGE,
		TARGET
	};

	ThresholdFilter() : 
		mode_(Mode::TARGET), 
		target_(Vec3b(0,0,0)), 
		lower_bound_(Vec3b(0,0,0)), 
		upper_bound_(Vec3b(0,0,0)), 
		tolerance_(0.0) {}
	ThresholdFilter(Mode mode) :
		mode_(mode),
		target_(Vec3b(0,0,0)),
		lower_bound_(Vec3b(0,0,0)),
		upper_bound_(Vec3b(0,0,0)),
		tolerance_(0.0) {}
	ThresholdFilter(Vec3b lower_bound, Vec3b upper_bound) :
		mode_(Mode::RANGE),
		target_(Vec3b(0,0,0)),
		lower_bound_(lower_bound),
		upper_bound_(upper_bound),
		tolerance_(0.0) {};
	ThresholdFilter(Vec3b target, double tolerance=0.0) :
		mode_(Mode::TARGET),
		target_(target),
		lower_bound_(Vec3b(0,0,0)),
		upper_bound_(Vec3b(0,0,0)),
		tolerance_(tolerance) {};
	
	virtual Mat& filter(Mat& image);

	void setMode(Mode mode) { mode_ = mode; }
	Mode getMode() { return mode_; }
	
	// Allow further encapsulation
	void setTarget(Vec3b target) { target_ = target; }
	void setRange(Vec3b lower_bound, Vec3b upper_bound) { lower_bound_ = lower_bound; upper_bound_ = upper_bound; }
	void setUpperBound(Vec3b upper_bound) { upper_bound_ = upper_bound; }
	void setLowerBound(Vec3b lower_bound) { lower_bound_ = lower_bound; }
	Vec3b getLowerBound() { return lower_bound_; }
	Vec3b getUpperBound() { return upper_bound_; }
	Vec3b getTarget() { return target_; }

	const char *debug() { return "THRESHOLDFILTER DEBUGGING"; }	
	
protected:
	Vec3b target_, lower_bound_, upper_bound_;
	double tolerance_;
	Mode mode_;	
};

} // namespace nurc
