#include <lacrosse-bot/tracker/Ball2DTracker.hpp>


namespace nurc {

Ball2DTracker::Ball2DTracker() :
	Tracker(),
	threshold_f_(Vec3b(150,0,0), Vec3b(175,255,255)),	
	kalman_f_(),
	centroid_a_()
{
	// Set initial conditions	
	captureImageFrame();
	image_.copyTo(transformed_image_);
	cvtColor(transformed_image_, transformed_image_, COLOR_BGR2HSV);
  resize(transformed_image_, transformed_image_, Size(0,0), 0.5, 0.5, INTER_LANCZOS4);
  GaussianBlur(transformed_image_, transformed_image_, Size(9,9), 2, 2);
	current_centroid_ = centroid_a_(threshold_f_(transformed_image_));
	current_centroid_.x *= 2;
	current_centroid_.y *= 2;
	Vector4d &predicted_state = kalman_f_.getPredictedState();
	predicted_state(0,0) = current_centroid_.x;
	predicted_state(1,0) = current_centroid_.y;
	predicted_state(2,0) = 0.0;
	predicted_state(3,0) = 0.0;
	
	Vector2d &z = kalman_f_.getMeasuredState();
	z << current_centroid_.x, current_centroid_.y;
	//kalman_f_.setMeasurementVector(z);
	kalman_f_.setVariances({1000.0, 1000.0,1000.0,1000.0});

	
	Matrix4d &Transition = kalman_f_.getTransitionTransform();
	Transition << 1.0, 0.0, 1.0, 0.0,
								0.0, 1.0, 0.0, 1.0,
								0.0, 0.0, 1.0, 0.0,
								0.0, 0.0, 0.0, 1.0;
	//kalman_f_.setTransitionTransform(Transition);
	
	Matrix<double,2,4> &Measurement = kalman_f_.getMeasurementTransform();
	Measurement << 1.0, 0.0, 0.0, 0.0,
					 			 0.0, 1.0, 0.0, 0.0;
	//kalman_f_.setMeasurementTransform(Measurement);
 
	Matrix2d &Noise = kalman_f_.getNoiseMatrix();
	Noise << 0.0, 0.0,
					 0.0, 0.0;
	//kalman_f_.setNoiseMatrix(Noise);
}

Point Ball2DTracker::getBallPosition()
{
	Vector4d &x = kalman_f_.getPredictedState();
	return Point(x(0), x(1));
}

Point Ball2DTracker::getBallVelocity()
{
	Vector4d &x = kalman_f_.getPredictedState();
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
	Vector2d state;
	image_.copyTo(transformed_image_);
	
	cvtColor(transformed_image_, transformed_image_, COLOR_BGR2HSV);
  resize(transformed_image_, transformed_image_, Size(0,0), 0.5, 0.5, INTER_LANCZOS4);
  GaussianBlur(transformed_image_, transformed_image_, Size(9,9), 2, 2);
	Point centroid = centroid_a_(threshold_f_(transformed_image_));
	centroid.x *= 2;
	centroid.y *= 2;
	
	// double vel_x = (centroid.x - current_centroid_.x)*getTickFrequency()/double(current_tick_count_ - previous_tick_count_);
	// double vel_y = (centroid.y - current_centroid_.y)*getTickFrequency()/double(current_tick_count_ - previous_tick_count_);
	double dt = double(current_tick_count_ - previous_tick_count_)/getTickFrequency();

	// Update the Transition matrix dt
	Matrix4d &transition_transform = kalman_f_.getTransitionTransform();
	transition_transform(0,2) = dt;
	transition_transform(1,3) = dt;

	current_centroid_ = centroid;
	state << centroid.x, centroid.y;
	kalman_f_.filter(state);

	//Vector4d &ps = kalman_f_.getPredictedState();
	//ps(0,0) = 100;
	//ps(1,0) = 100;

	cv::cvtColor(transformed_image_,transformed_image_,CV_GRAY2BGR);
	Vector4d &predicted_state = kalman_f_.getPredictedState();
  cv::circle(image_, current_centroid_, 2, cv::Scalar(255,0,0), -1);
  cv::circle(image_, cv::Point(predicted_state(0,0), predicted_state(1,0)), 2, cv::Scalar(0,0,255), -1);
  cv::circle(transformed_image_, current_centroid_, 2, cv::Scalar(255,0,0), -1);
  cv::circle(transformed_image_, cv::Point(predicted_state(0,0), predicted_state(1,0)), 2, cv::Scalar(0,0,255), -1);

}

} // namespace nurc

