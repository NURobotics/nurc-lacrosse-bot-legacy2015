#include <lacrosse-bot/algorithm/Algorithm.hpp>

namespace nurc {

Point Centroid::algorithm(Mat& image)
{
  cv::Moments m = cv::moments(image, true);
  return Point(m.m10/m.m00, m.m01/m.m00); 
}

}  // namespace nurc
