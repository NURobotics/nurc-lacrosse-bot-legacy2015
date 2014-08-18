#ifndef LACROSSE_BOT_KALMANFILTER_H
#define LACROSSE_BOT_KALMANFILTER_H

#include <Eigen/Dense>
#include <lacrosse-bot/filter/Filter.hpp>


namespace nurc {

using namespace cv;
using namespace Eigen;
using namespace std;

class KalmanFilter : public Filter<Vector2d&, Vector4d&> 
{
public:

	KalmanFilter()
	{
		// Zero out
		x = Vector4d::Zero();
		z = Vector2d::Zero();
	}

	virtual Vector4d& filter(Vector2d &measurement);

	void predict();
	void update();

	// Allow encapsulation
	void setCovarianceMatrix(Matrix4d &covariance_m);
	void setVariances(vector<double> variances);
	void setNoiseMatrix(Matrix2d &noise_m);
	void setTransitionTransform(Matrix4d &transition_m);
	void setMeasurementTransform(Matrix<double,2,4> &measurement_m);
	void setMotionVector(Vector4d &motion_v);
	void setMeasurementVector(Vector2d &measurement_v);
	
	Matrix4d& getCovarianceMatrix() { return P; }
	Matrix2d& getNoiseMatrix() { return R; }
	Matrix4d& getTransitionTransform() { return F; }
	Matrix<double,2,4>& getMeasurementTransform() { return H; }
	Vector4d& getPredictedState() { return x; }
	Vector2d& getMeasuredState() { return z; }
	
protected:

	Matrix4d P; // Covariance Matrix
	Matrix4d F; // Transition Transform
	Matrix<double,2,4> H; // Measurement Transform
	Matrix2d R; // Measurement Noise Matrix
	Vector4d x; // Predicted State
	Vector2d z; // Measured State
	Vector4d u; // Change in State
	Matrix<double,4,2> K; // Kalman Gain

};

} // namespace nurc


#endif
