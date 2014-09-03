#include <lacrosse-bot/filter/KalmanFilter.hpp>


namespace nurc {

Vector4d& KalmanFilter::filter(Vector2d &measurement)
{
	z = measurement;
	update();
	//predict();
	return x;
}

void KalmanFilter::update()
{
  Matrix2d Ctemp = (H*P*H.transpose() + R);
  JacobiSVD<Matrix2d> jsvd(Ctemp);
  Vector2d singulars = jsvd.singularValues();
  Matrix2d S = Matrix2d::Zero();
  S(0,0) = (singulars(0,0) < 0.000001) ? 0: singulars(0,0);
  S(1,1) = (singulars(1,1) < 0.000001) ? 0: singulars(1,1);

	Matrix<double,4,2> Ktemp = P*H.transpose()*(jsvd.matrixV()*S*(jsvd.matrixV().transpose()));
	Vector4d xtemp = x + K*(z - H*x);
	Matrix4d T = P;
  P = (Matrix4d::Identity() - K*H)*P;
  
  cout << "--- UPDATE STEP 1 ---" << endl;
	cout << "K: " << endl << Ktemp << endl;
	cout << "x: " << endl << xtemp << endl;
	cout << "T: " << endl << T << endl << endl;
	cout << "P: " << endl << P << endl << endl;
	
	Ktemp = P*H.transpose()*(H*P*H.transpose() + R).inverse();
	xtemp = xtemp + Ktemp*(z - H*xtemp);
  P = (Matrix4d::Identity() - Ktemp*H)*P;
  
  cout << "--- UPDATE STEP 2 ---" << endl;
	cout << "K: " << endl << Ktemp << endl;
	cout << "x: " << endl << xtemp << endl;
	cout << "T: " << endl << T << endl << endl;
	cout << "P: " << endl << P << endl << endl;
	
	Ktemp = P*H.transpose()*(H*P*H.transpose() + R).inverse();
	xtemp = xtemp + Ktemp*(z - H*xtemp);
  P = (Matrix4d::Identity() - Ktemp*H)*P;
  
  cout << "--- UPDATE STEP 3 ---" << endl;
	cout << "K: " << endl << Ktemp << endl;
	cout << "x: " << endl << xtemp << endl;
	cout << "T: " << endl << T << endl << endl;
	cout << "P: " << endl << P << endl << endl;
	
  P = T;
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
