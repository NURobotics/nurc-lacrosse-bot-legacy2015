#ifndef LACROSSE_BOT_TRANSFORM_H
#define LACROSSE_BOT_TRANSFORM_H


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
	
private:
	Transform(const Transform& copy);
	Transform& operator=(const Transform& copy);
};

} // namespace nurc


#endif
