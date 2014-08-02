#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

namespace nurc {

using namespace cv;
using namespace std;

class Transform
{
public:
	Transform() {}
	virtual Mat& transform(Mat& image) = 0;
	Mat& operator()(Mat& image) { return transform(image); }
	
	const char *debug() { return "FILTER DEBUGGING"; }

private:
	Transform(const Transform& copy);
	Transform& operator=(const Transform& copy);
};

} // namespace
