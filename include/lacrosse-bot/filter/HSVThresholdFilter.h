#include <lacrosse_bot/transform/Filter.h>

namespace nurc {

using namespace cv;
using namespace std;

class HSVThresholdFilter : public class Filter
{
public:
	HSVThresholdFilter(int threshold=0);
protected:
	int threshold_;
};

} // namespace
