#ifndef LACROSSE_BOT_BALL2DTRACKER_H
#define LACROSSE_BOT_BALL2DTRACKER_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <Eigen/Dense>
#include <lacrosse-bot/tracker/Tracker.hpp>
#include <lacrosse-bot/algorithm/Algorithm.hpp>
#include <lacrosse-bot/filter/ThresholdFilter.hpp>
#include <lacrosse-bot/filter/KalmanFilter.hpp>


namespace nurc {

using namespace Eigen;
using namespace std;

class Ball2DTracker : public Tracker
{
public:
	Ball2DTracker();

	// Overloaded Functions
	bool captureImageFrame();
	
	// Helper Functions
	Point getBallPosition();
	Point getBallVelocity();
	
	cv::Mat& getTransformedImage() { return transformed_image_; }
	cv::Point getMeasuredCenter() { return current_centroid_; }
  cv::Point getEstimatedCenter() { return cv::Point((int)predicted_state_.at<float>(0), (int)predicted_state_.at<float>(1)); }
	
  void update();

  cv::Mat_<float> predicted_state_;
	
//protected:
	// Filters
	ThresholdFilter threshold_f_;
	cv::KalmanFilter kalman_f_;

	// Algorithms
	Centroid centroid_a_;
	
	// Frames
	cv::Mat transformed_image_;
	
	cv::Point current_centroid_;

};

} // namespace nurc


#endif // LACROSSE_BOT_BALL2DTRACKER_H
