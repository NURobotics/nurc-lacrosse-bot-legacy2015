#include <lacrosse-bot/tracker/Ball2DTracker.hpp>


namespace nurc {

Ball2DTracker::Ball2DTracker() :
	Tracker(),
	threshold_f_(Vec3b(150,0,0), Vec3b(175,255,255)),	
	kalman_f_(4),
	centroid_a_()
{

	kalman_f_.setVariances({1000.0, 1000.0,1000.0,1000.0});
	
	MatrixXd Transition(kalman_f_.getNDims(), kalman_f_.getNDims());
	Transition << 1.0, 0.0, 1.0, 0.0,
								0.0, 1.0, 0.0, 1.0,
								0.0, 0.0, 1.0, 0.0,
								0.0, 0.0, 0.0, 1.0;
	kalman_f_.setTransitionTransform(Transition);
	
	MatrixXd Measurement(kalman_f_.getNDims(), kalman_f_.getNDims());
	Measurement << 1.0, 0.0, 1.0, 0.0,
								0.0, 1.0, 0.0, 1.0,
								0.0, 0.0, 1.0, 0.0,
								0.0, 0.0, 0.0, 1.0;
	kalman_f_.setMeasurementTransform(Measurement);

	MatrixXd Noise(kalman_f_.getNDims(), kalman_f_.getNDims());
	Noise <<			0.0, 0.0, 0.0, 0.0,
								0.0, 0.0, 0.0, 0.0,
								0.0, 0.0, 0.0, 0.0,
								0.0, 0.0, 0.0, 0.0;
	kalman_f_.setNoiseMatrix(Noise);
}

} // namespace nurc
