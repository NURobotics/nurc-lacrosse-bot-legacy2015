#ifndef LACROSSE_BOT_FILTER_H
#define LACROSSE_BOT_FILTER_H


#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>


namespace nurc {

using namespace cv;
using namespace std;

template<typename I, typename O> class Filter
{
public:
	Filter() {}
	virtual O& filter(I& output) = 0;
	O& operator()(I& input) { return filter(input); }
private:
	Filter(const Filter& copy);
	Filter& operator=(const Filter& copy);
};

} // namespace nurc


#endif
