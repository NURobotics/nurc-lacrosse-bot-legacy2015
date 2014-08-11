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
	K.resize(n_dims_, n_dims_);
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
	if(noise_m.rows() == noise_m.cols() && noise_m.rows() == n_dims_)
		P = noise_m;
}

void KalmanFilter::setTransitionTransform(MatrixXd &transition_m)
{
	if(transition_m.rows() == transition_m.cols() && transition_m.rows() == n_dims_)
		P = transition_m;
}

void KalmanFilter::setMeasurementTransform(MatrixXd &measurement_m)
{
	if(measurement_m.rows() == measurement_m.cols() && measurement_m.rows() == n_dims_)
		P = measurement_m;
}

} // namespace nurc
