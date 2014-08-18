#include <lacrosse-bot/filter/KalmanFilter.hpp>


namespace nurc {

Vector4d& KalmanFilter::filter(Vector2d &measurement)
{
	z = measurement;
	update();
	predict();
	return x;
}

void KalmanFilter::update()
{
	K = P*H.transpose()*(H*P*H.transpose() + R).inverse();
	x = x + K*(z - H*x);
	//P = (Matrix4d::Identity() - K*H)*P;
	/*cout << "--- UPDATE STEP ---" << endl;
	cout << "Kalman Gain: " << endl << K << endl;
	cout << "x: " << endl << x << endl;
	cout << "Covariance: " << endl << P << endl << endl;*/
}

void KalmanFilter::predict()
{
	x = F*x + u;
	P = F*P*F.transpose();
	/*cout << "--- PREDICT STEP ---" << endl;
	cout << "x: " << endl << x << endl;
	cout << "Covariance: " << endl << P << endl << endl;*/
}

void KalmanFilter::setCovarianceMatrix(Matrix4d &covariance_m)
{
	P = covariance_m;
}

void KalmanFilter::setVariances(vector<double> variances)
{
	if(variances.size() == 4) {
		for(int i = 0; i < 4; i++) {
			P(i,i) = variances[i];
		}
	}
}

void KalmanFilter::setNoiseMatrix(Matrix2d &noise_m)
{
	R = noise_m;
}

void KalmanFilter::setTransitionTransform(Matrix4d &transition_m)
{
	F = transition_m;
}

void KalmanFilter::setMeasurementTransform(Matrix<double,2,4> &measurement_m)
{
	H = measurement_m;
}

void KalmanFilter::setMeasurementVector(Vector2d &measurement_v)
{
	z = measurement_v;
}

} // namespace nurc
