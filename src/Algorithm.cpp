#include <lacrosse-bot/algorithm/Algorithm.hpp>

namespace nurc {

Point Centroid::algorithm(Mat& image)
{
  int center_x = 0, center_y = 0, sum = 0;
  vector<int> histogram_y(image.cols, 0);
  vector<int> histogram_x(image.rows, 0);
  for (int y = 0; y < image.cols; y++) {
    for (int x = 0; x < image.rows; x++) {
      if (image.at<uchar>(y, x)) {
        histogram_y[y]++;
        histogram_x[x]++;
        sum++;
      }
    }
  }

  for (int i = 0; i < histogram_y.size(); i++) center_y += i*histogram_y[i];
  for (int j = 0; j < histogram_x.size(); j++) center_x += j*histogram_x[j];

  center_y /= sum;
  center_x /= sum;

  return Point(center_x, center_y); 
}

}  // namespace nurc
