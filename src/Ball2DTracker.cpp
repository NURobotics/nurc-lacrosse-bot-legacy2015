#include <lacrosse-bot/tracker/Ball2DTracker.hpp>


namespace nurc {

Ball2DTracker::Ball2DTracker() :
	Tracker(),
	threshold_f_(Vec3b(150,0,0), Vec3b(175,255,255)),
  kalman_f_(4,2,0),
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
  
  kalman_f_.transitionMatrix = *(Mat_<float>(4, 4) << 1,0,1,0V,   0,1,0,1,  0,0,1,0,  0,0,0,1);
  Mat_<float> measurement(2,1); measurement.setTo(Scalar(0));
  kalman_f_.statePre.at<float>(0) = current_centroid_.x;
  kalman_f_.statePre.at<float>(1) = current_centroid_.y;
  kalman_f_.statePre.at<float>(2) = 0;
  kalman_f_.statePre.at<float>(3) = 0;
  
  setIdentity(kalman_f_.measurementMatrix);
  setIdentity(kalman_f_.processNoiseCov, Scalar::all(1e-4));
  setIdentity(kalman_f_.measurementNoiseCov, Scalar::all(10));
  setIdentity(kalman_f_.errorCovPost, Scalar::all(.1));
}

bool Ball2DTracker::captureImageFrame()
{
	if(video_capture_.isOpened()) {
		video_capture_ >> image_;

		previous_tick_count_ = current_tick_count_;
		current_tick_count_ = getTickCount();
		total_tick_count_ += current_tick_count_ - previous_tick_count_;

		return image_.data; 
	}
	else {
		return false;
	}
}

void Ball2DTracker::update()
{
  if(captureImageFrame()) {
    Vector2d state;
    image_.copyTo(transformed_image_);
    
    cvtColor(transformed_image_, transformed_image_, COLOR_BGR2HSV);
    resize(transformed_image_, transformed_image_, Size(0,0), 0.5, 0.5, INTER_LANCZOS4);
    GaussianBlur(transformed_image_, transformed_image_, Size(9,9), 2, 2);
    current_centroid_ = centroid_a_(threshold_f_(transformed_image_));
    current_centroid_.x *= 2;
    current_centroid_.y *= 2;
    
    // double vel_x = (centroid.x - current_centroid_.x)*getTickFrequency()/double(current_tick_count_ - previous_tick_count_);
    // double vel_y = (centroid.y - current_centroid_.y)*getTickFrequency()/double(current_tick_count_ - previous_tick_count_);
    double dt = double(current_tick_count_ - previous_tick_count_)/getTickFrequency();

    // Update the Transition matrix dt

    //Vector4d &ps = kalman_f_.getPredictedState();
    //ps(0,0) = 100;
    //ps(1,0) = 100;
    Mat_<float> measurement(2,1);
    measurement(0) = current_centroid_.x;
    measurement(1) = current_centroid_.y;
    predicted_state_ = kalman_f_.correct(measurement);
    
    cv::cvtColor(transformed_image_,transformed_image_,CV_GRAY2BGR);
    cv::circle(image_, current_centroid_, 2, cv::Scalar(255,0,0), -1);
    cv::circle(image_, getEstimatedCenter(), 2, cv::Scalar(0,0,255), -1);
    // cv::circle(transformed_image_, current_centroid_, 2, cv::Scalar(255,0,0), -1);
    // cv::circle(transformed_image_, getEstimatedCenter(), 2, cv::Scalar(0,0,255), -1);
  } 
}

} // namespace nurc

