#include <lacrosse-bot/tracker/Ball2DTracker.hpp>


namespace nurc {

Ball2DTracker::Ball2DTracker() :
	Tracker(),
	threshold_f_(Vec3b(150,0,0), Vec3b(175,255,255)),	
	kalman_f_(4),
	centroid_a_(),
	current_centroid_(0.0,0.0)
{
	VectorXd z(2);
	z << 0.0, 0.0;
	kalman_f_.setMeasurementVector(z);
	kalman_f_.setVariances({1000.0, 1000.0,1000.0,1000.0});
	
	MatrixXd Transition(kalman_f_.getNDims(), kalman_f_.getNDims());
	Transition << 1.0, 0.0, 1.0, 0.0,
								0.0, 1.0, 0.0, 1.0,
								0.0, 0.0, 1.0, 0.0,
								0.0, 0.0, 0.0, 1.0;
	kalman_f_.setTransitionTransform(Transition);
	
	MatrixXd Measurement(2, kalman_f_.getNDims());
	Measurement << 1.0, 0.0, 0.0, 0.0,
					 			 0.0, 1.0, 0.0, 0.0;
	kalman_f_.setMeasurementTransform(Measurement);
 
	MatrixXd Noise(2, 2);
	Noise << 0.0, 0.0,
					 0.0, 0.0;
	kalman_f_.setNoiseMatrix(Noise);
}

Point Ball2DTracker::getBallPosition()
{
	VectorXd &x = kalman_f_.getPredictedState();
	return Point(x(0), x(1));
}

Point Ball2DTracker::getBallVelocity()
{
	VectorXd &x = kalman_f_.getPredictedState();
	return Point(x(2),x(3));
}

bool Ball2DTracker::captureImageFrame()
{
	if(video_capture_.isOpened()) {
		video_capture_ >> image_;

		previous_tick_count_ = current_tick_count_;
		current_tick_count_ = getTickCount();
		total_tick_count_ += current_tick_count_ - previous_tick_count_;

		update();

		return image_.data; 
	}
	else {
		return false;
	}
}

void Ball2DTracker::update()
{
	VectorXd state(4);
	image_.copyTo(transformed_image_);
	
	cvtColor(transformed_image_, transformed_image_, COLOR_BGR2HSV);
  resize(transformed_image_, transformed_image_, Size(0,0), 0.5, 0.5, INTER_LANCZOS4);
  GaussianBlur(transformed_image_, transformed_image_, Size(9,9), 2, 2);
	Point centroid = centroid_a_(threshold_f_(transformed_image_));
	double vel_x = (centroid.x - current_centroid_.x)*getTickFrequency()/double(current_tick_count_ - previous_tick_count_);
	double vel_y = (centroid.y - current_centroid_.y)*getTickFrequency()/double(current_tick_count_ - previous_tick_count_);

	current_centroid_ = centroid;
	state << centroid.x, centroid.y, vel_x, vel_y;
	kalman_f_(state);

	cv::cvtColor(transformed_image_,transformed_image_,CV_GRAY2BGR);
	VectorXd &predicted_state = kalman_f_.getPredictedState();
  cv::circle(image_, current_centroid_, 2, cv::Scalar(255,0,0), -1);
  cv::circle(image_, cv::Point(predicted_state(0), predicted_state(1)), 2, cv::Scalar(0,0,255), -1);
  cv::circle(transformed_image_, current_centroid_, 2, cv::Scalar(255,0,0), -1);
  cv::circle(transformed_image_, cv::Point(predicted_state(0), predicted_state(1)), 2, cv::Scalar(0,0,255), -1);
}

} // namespace nurc

