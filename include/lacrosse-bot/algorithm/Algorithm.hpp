#ifndef LACROSSE_BOT_ALGORITHM_H
#define LACROSSE_BOT_ALGORITHM_H

#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>


namespace nurc {

using namespace cv;
using namespace std;

template<typename I, typename O> class Algorithm
{
public:
	Algorithm() {}
	virtual O algorithm(I input) = 0;
	O operator()(I input) { return algorithm(input); }
private:
	Algorithm(const Algorithm& copy);
	Algorithm& operator=(Algorithm& copy);	
};

class Centroid : public Algorithm<Mat&, Point>
{
public:
	Point algorithm(Mat& image);
	Point operator()(Mat& image) { return algorithm(image); }
};

} //namespace nurc


#endif
