#include <lacrosse_bot/transform/Transform.h>

namespace nurc {

using namespace cv;
using namespace std;

class ThresholdTransform : public class Transform
{
public:
	ThresholdTransform(int threshold=0);
protected:
	int threshold_;
};

} // namespace
