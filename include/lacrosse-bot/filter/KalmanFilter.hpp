#ifndef LACROSSE_BOT_KALMANFILTER_H
#define LACROSSE_BOT_KALMANFILTER_H

#include <Eigen/Dense>
#include <lacrosse-bot/filter/Filter.hpp>


namespace nurc {

using namespace cv;
using namespace Eigen;
using namespace std;

class KalmanFilter : Public Filter<VectorXd&, VectorXd&> 
{
public:
	KalmanFilter() {}
	KalmanFilter(unsigned int n_dims) :
		n_dims_(n_dims_),
		P(n_dims_, n_dims_),
		F(n_dims_, n_dims_),
		H(n_dims_, n_dims_),
		R(n_dims_, n_dims_),
		x(n_dims_),
		z(n_dims_),
		u(n_dims_),
		K(n_dims_) {}

	virtual VectorXd& filter(VectorXd measurement);

	void predict();
	void update();

	// Allow encapsulation
	void setCovarianceMatrix(MatrixXd &covariance_m);
	void setVariances(vector<double> variances);
	void setTransitionMatrix(MatrixXd &transition_m);
	void setMeasurementTransform(MatrixXd &measurement_m);
	void setNoiseTransform(MatrixXd &noise_m);

	MatrixXd& getCovarianceMatrix() { return P; }
	MatrixXd& getTransitionMatrix() { return F; }
	MatrixXd& getMeasurementTransform() { return H; }
	MatrixXd& getNoiseTransform() { return R; }
	
	unsigned int n_dims_;
protected:
	MatrixXd P; // Covariance
	MatrixXd F; // Transition
	MatrixXd H; // Measurement Transform
	MatrixXd R; // Measurement Noise Transform
	VectorXd x; // Predicted State
	VectorXd z; // Measured State
	VectorXd u; // Change in State
	MatrixXd K; // Kalman Gain
}

} // namespace nurc


#endif
