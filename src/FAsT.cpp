#include <opencv2/opencv.hpp>

#include "FAsTMatch.h"
#include "MatchConfig.h"

using namespace std;
using namespace cv;

#define DLLEXPORT extern "C" __declspec(dllexport)
DLLEXPORT double match(
	unsigned char* tmpl_arr, const int tmpl_w, const int tmpl_h,
	unsigned char* test_arr, const int test_w, const int test_h,
	float * ret)
{
	Mat image(tmpl_h, tmpl_w, CV_8UC1, (void *)tmpl_arr);
	Mat templ(test_h, test_w, CV_8UC1, (void *)test_arr);

    fast_match::FAsTMatch fast_match;
    fast_match.init( 0.15f, 0.85f, false, 0.5f, 2.0f );
	double best_distance = -1;
	vector<Point2f> corners = fast_match.apply(image, templ, best_distance);

	ret[0] = corners[0].x;
	ret[1] = corners[0].y;
	ret[2] = corners[1].x;
	ret[3] = corners[1].y;
	ret[4] = corners[2].x;
	ret[5] = corners[2].y;
	ret[6] = corners[3].x;
	ret[7] = corners[3].y;
    
	return best_distance;
}

