#include <lacrosse_bot/filter/Filter.h>

namespace nurc {

using namespace cv;
using namespace std;

class ThresholdFilter : public Filter
{
public:
	enum class Mode 
	{
		CUTOFF,
		TARGET
	};

	ThresholdFilter() : mode_(Mode::CUTOFF), comparison_(Vec3b(0,0,0)), tolerance_(0) {}
	ThresholdFilter(Mode mode, Vec3b cmp, double threshold=0.0);
	ThresholdFilter(Vec3b cutoff);
	
	virtual Mat& filter(Mat& image);

	void setMode(Mode mode) { mode_ = mode; }
	Mode getMode() { return mode_; }
	
	// Allow further encapsulation
	void setCutoff(Vec3b cutoff) { comparison_ = cutoff; }
	void setTarget(Vec3b target) { comparison_ = target; }
	Vec3b getCutoff() { return comparison_; }
	Vec3b getTarget() { return comparison_; }

	const char *debug() { return "THRESHOLDFILTER DEBUGGING"; }	
	
protected:
	Vec3b comparison_;
	double tolerance_;
	Mode mode_;	
};

} // namespace
