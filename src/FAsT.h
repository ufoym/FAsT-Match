#include <opencv2/opencv.hpp>
#include "FAsTMatch.h"

double match(unsigned char * _templ, int templ_w, int templ_h,
	unsigned char * _image, int image_w, int image_h) {
	cv::Mat templ = cv::Mat(templ_h, templ_w, CV_8UC3, _templ);
	cv::Mat image = cv::Mat(image_h, image_w, CV_8UC3, _image);

    FAsTMatch fast_match;
    fast_match.init( 0.15f, 0.85f, false, 0.5f, 2.0f );
    double best_distance = -1;
    std::vector<cv::Point2f> corners = fast_match.apply(image, templ, best_distance);

    return best_distance;
}
