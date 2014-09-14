#include <lacrosse-bot/tracker/Ball2DTracker.hpp>


namespace nurc {

Ball2DTracker::Ball2DTracker() :
	Tracker(),
	threshold_f_(Vec3b(150,0,0), Vec3b(175,255,255)),
  predicted_state_(2,1),
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
  
  predicted_state_.at<float>(0) = 0;
  predicted_state_.at<float>(1) = 0;
  
  kalman_f_.transitionMatrix = *(Mat_<float>(4, 4) << 1,0,1,0,   0,1,0,1,  0,0,1,0,  0,0,0,1);
  Mat_<float> measurement(2,1); measurement.setTo(Scalar(0));
  kalman_f_.statePre.at<float>(0) = current_centroid_.x;
  kalman_f_.statePre.at<float>(1) = current_centroid_.y;
  kalman_f_.statePre.at<float>(2) = 0;
  kalman_f_.statePre.at<float>(3) = 0;
  
  kalman_f_.measurementMatrix.create(2, 4, CV_32FC1);
  kalman_f_.measurementMatrix = *(Mat_<float>(2,4) << 1, 0, 0, 0,  0, 1, 0, 0);
  
  setIdentity(kalman_f_.measurementNoiseCov, Scalar::all(2));
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
    
    double dt = double(current_tick_count_ - previous_tick_count_)/getTickFrequency();
  
    kalman_f_.transitionMatrix.at<float>(0,2) = dt;
    kalman_f_.transitionMatrix.at<float>(1,3) = dt;

    kalman_f_.predict();
  
    std::cout << "Transition Matrix: \n" << kalman_f_.transitionMatrix << std::endl;
    std::cout << "Measurement Matrix: \n" << kalman_f_.measurementMatrix << std::endl;
    std::cout << "Kalman Gain: \n" << kalman_f_.gain << std::endl;
    
    Mat_<float> measurement(2,1);
    measurement(0) = current_centroid_.x;
    measurement(1) = current_centroid_.y;
    predicted_state_ = kalman_f_.correct(measurement);
    
    cv::cvtColor(transformed_image_,transformed_image_,CV_GRAY2BGR);
    resize(transformed_image_, transformed_image_, Size(0,0), 2, 2, INTER_LANCZOS4);
    cv::circle(image_, current_centroid_, 2, cv::Scalar(255,0,0), -1);
    cv::circle(image_, getEstimatedCenter(), 2, cv::Scalar(0,0,255), -1);
    cv::circle(transformed_image_, current_centroid_, 2, cv::Scalar(255,0,0), -1);
    cv::circle(transformed_image_, getEstimatedCenter(), 2, cv::Scalar(0,0,255), -1);
  } 
}

} // namespace nurc

