#include <lacrosse-bot/tracker/Tracker.hpp>


namespace nurc
{

using namespace cv;
using namespace std;

Tracker::Tracker()
{
	video_capture_ = VideoCapture(0);
	if(!video_capture_.isOpened()) {
		image_ = Mat( video_capture_.get(CV_CAP_PROP_FRAME_HEIGHT), 
												 video_capture_.get(CV_CAP_PROP_FRAME_WIDTH),
												 CV_8UC3 );
	}
	else {
		image_ = Mat( 600, 800, CV_8UC3 );
	}

	previous_tick_count_ = current_tick_count_ = getTickCount();
	total_tick_count_ = 0;
	
}

bool Tracker::setVideoCapture(unsigned int capture)
{
	video_capture_.open(capture);
	return video_capture_.isOpened();
}

bool Tracker::setVideoCapture(const char* capture)
{
	video_capture_.open(capture);
	if(video_capture_.isOpened()) {
		image_.create( video_capture_.get(CV_CAP_PROP_FRAME_HEIGHT), 
												  video_capture_.get(CV_CAP_PROP_FRAME_WIDTH),
												  CV_8UC3 );
	}
	else {
		image_.create( 600, 800, CV_8UC3 );
	}
	return video_capture_.isOpened();
}

} // namespace nurc
