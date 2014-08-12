#include <lacrosse-bot/tracker/Ball2DTracker.hpp>


int main(int argc, char **argv)
{
  std::cout << "Ball2DTracker main test initialized..." << std::endl << std::endl;

  char response = 'n';
  std::cout << "Begin running video tests (y/n)? ";
  std::cin >> response;
  cv::namedWindow("Feed Image", CV_WINDOW_AUTOSIZE);
  cv::namedWindow("Transformed Image", CV_WINDOW_AUTOSIZE);

  if(response == 'y') {
    nurc::Ball2DTracker* tracker = new nurc::Ball2DTracker;

    while(cv::waitKey(1) == -1) {
			/* tracker.captureImageFrame();
      cv::imshow("Feed Image", tracker.getImage());
      cv::imshow("Transformed Image", tracker.getTransformedImage());

      cv::Point measured_center = tracker.getMeasuredCenter();
      cv::Point estimated_center = tracker.getEstimatedCenter();

      std::cout << "The measured centroid was calcualted at: (" << measured_center.x << ", " << measured_center.y << ")" << std::endl;
      std::cout << "The filtered estimate was calculated at: (" << estimated_center.x << ", " << estimated_center.y << ")" << std::endl;*/
    }

		delete tracker;
  }

  std::cout << std::endl << "Ball2DTracker main test completed." << std::endl;

  return 0;
}

