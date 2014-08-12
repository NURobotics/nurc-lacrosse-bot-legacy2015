#include <lacrosse-bot/filter/KalmanFilter.hpp>


namespace nurc {

VectorXd& KalmanFilter::filter(VectorXd &measurement)
{
	z = measurement;
	update();
	predict();
	return x;
}

void KalmanFilter::update()
{
	K.resize(n_dims_, H.rows());
	K = P*H.transpose()*(H*P*H.transpose() + R).inverse();
	x = x + K*(z - H*x);
	P = (MatrixXd::Identity(n_dims_, n_dims_) - K*H)*P;
}

void KalmanFilter::predict()
{
	x = F*x + u;
	P = F*P*F.transpose();
}

void KalmanFilter::setCovarianceMatrix(MatrixXd &covariance_m)
{
	if(covariance_m.rows() == covariance_m.cols() && covariance_m.rows() == n_dims_)
		P = covariance_m;
}

void KalmanFilter::setVariances(vector<double> variances)
{
	if(variances.size() == n_dims_) {
		for(int i = 0; i < n_dims_; i++) {
			P(i,i) = variances[i];
		}
	}
}

void KalmanFilter::setNoiseMatrix(MatrixXd &noise_m)
{
	P = noise_m;
}

void KalmanFilter::setTransitionTransform(MatrixXd &transition_m)
{
	if(transition_m.rows() == transition_m.cols() && transition_m.rows() == n_dims_)
		F = transition_m;
}

void KalmanFilter::setMeasurementTransform(MatrixXd &measurement_m)
{
	H = measurement_m;
}

void KalmanFilter::setMeasurementVector(VectorXd &measurement_v)
{
	z = measurement_v;
}

} // namespace nurc
