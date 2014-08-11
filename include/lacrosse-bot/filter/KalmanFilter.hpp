#ifndef LACROSSE_BOT_KALMANFILTER_H
#define LACROSSE_BOT_KALMANFILTER_H

#include <Eigen/Dense>
#include <lacrosse-bot/filter/Filter.hpp>


namespace nurc {

using namespace cv;
using namespace Eigen;
using namespace std;

class KalmanFilter : public Filter<VectorXd&, VectorXd&> 
{
public:
	KalmanFilter(unsigned int n_dims = 4) :
		n_dims_(n_dims_),
		P(n_dims_, n_dims_),
		F(n_dims_, n_dims_),
		H(n_dims_, n_dims_),
		R(n_dims_, n_dims_),
		x(n_dims_),
		z(n_dims_),
		u(n_dims_),
		K(n_dims_, n_dims_) {}

	virtual VectorXd& filter(VectorXd &measurement);

	void predict();
	void update();

	// Allow encapsulation
	void setCovarianceMatrix(MatrixXd &covariance_m);
	void setVariances(vector<double> variances);
	void setNoiseMatrix(MatrixXd &noise_m);
	void setTransitionTransform(MatrixXd &transition_m);
	void setMeasurementTransform(MatrixXd &measurement_m);

	MatrixXd& getCovarianceMatrix() { return P; }
	MatrixXd& getNoiseMatrix() { return R; }
	MatrixXd& getTransitionTransform() { return F; }
	MatrixXd& getMeasurementTransform() { return H; }
	
	unsigned int getNDims() { return n_dims_; }
	
protected:
	unsigned int n_dims_;
	
	MatrixXd P; // Covariance Matrix
	MatrixXd F; // Transition Transform
	MatrixXd H; // Measurement Transform
	MatrixXd R; // Measurement Noise Matrix
	VectorXd x; // Predicted State
	VectorXd z; // Measured State
	VectorXd u; // Change in State
	MatrixXd K; // Kalman Gain
};

} // namespace nurc


#endif
