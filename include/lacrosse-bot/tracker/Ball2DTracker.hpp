#ifndef LACROSSE_BOT_BALL2DTRACKER_H
#define LACROSSE_BOT_BALL2DTRACKER_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <Eigen/Dense>
#include <lacrosse-bot/filter/ThresholdFilter.hpp>


namespace nurc {

using namespace cv;
using namespace std;

class Ball2DTracker : public Tracker
{
public:
	Ball2DTracker() {};

	bool setVideoCapture(unsigned int capture);
	bool setVideoCapture(const char *capture);

	VideoCapture& getVideoCapture() { return video_capture_; }
	Mat& getCameraFrame() { return camera_frame_; }

	// Helper Functions
	Point getBallPosition();
	Point getBallVelocity();
	Vector4d getBallState();
	
protected:

	ThresholdFilter threshold_f_;
	KalmanFilter kalman_f_;
	VideoCapture video_capture_;
	Mat camera_frame_;
	Mat transformed_frame_;

}

} // namespace nurc


#endif // LACROSSE_BOT_BALL2DTRACKER_H
