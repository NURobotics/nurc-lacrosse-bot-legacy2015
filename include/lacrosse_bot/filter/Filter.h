#include <opencv2/core/core.hpp>

namespace nurc {

using namespace cv;
using namespace std;

class Filter
{
public:
	Mat& filter(Mat& image) = 0;
	Mat& operator(Mat& image) { return filter(image); }
private:
	Filter& Filter();
	Filter& operator=():
};

} // namespace
