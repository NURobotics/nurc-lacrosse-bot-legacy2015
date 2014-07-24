#include <lacrosse_bot/filter/Filter.h>

namespace nurc {

using namespace cv;
using namespace std;

class ThresholdFilter : public class Filter
{
public:
	enum class Mode 
	{
		CUTOFF,
		DISTANCE
	};

	ThresholdFilter(Mode mode, Vec3b cmp, double threshold=0.0);
	ThresholdFilter(Vec3b cutoff);
	
	void setCutoff(Vec3b cutoff) { cutoff_ = cutoff; }
	Vec3b getCutoff() { return cutoff_; }

	void setMode(Mode mode) { mode_ = mode; }

protected:
	Vec3b 
	Vec3b cutoff_;
	double threshold_;
	Mode mode_;	
	int channel_;
};

} // namespace
