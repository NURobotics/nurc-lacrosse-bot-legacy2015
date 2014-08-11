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
	
	// Helper Functions
	Point getBallPosition();
	Point getBallVelocity();
	Vector4d& getBallState();
	
protected:
	// Filters
	ThresholdFilter threshold_f_;
	KalmanFilter kalman_f_;

	// Algorithms
	Centroid centroid_a_;
	
	// Frames
	cv::Mat transformed_frame_;

};

} // namespace nurc


#endif // LACROSSE_BOT_BALL2DTRACKER_H
