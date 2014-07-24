#include <opencv2/core/core.hpp>

namespace nurc {

using namespace cv;
using namespace std;

class Transform
{
public:
	Mat transform(Mat& image) = 0;
	Mat operator(Mat& image) { return transform(image); }
private:
	Transform& Transform();
	Transform& operator=():
};

} // namespace
