//
//  FAsTMatch.h
//  FAsT-Match
//
//  Created by Saburo Okita on 23/05/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __FAsT_Match__FAsTMatch__
#define __FAsT_Match__FAsTMatch__

#include <iostream>
#include <opencv2/opencv.hpp>

#include "MatchNet.h"
#include "MatchConfig.h"

    class FAsTMatch{
    public:
        FAsTMatch();

        void init( float epsilon = 0.15f, float delta = 0.25f, bool photometric_invariance = false,
                   float min_scale = 0.5f, float max_scale = 2.0f );

		std::vector<cv::Point2f> apply(cv::Mat& image, cv::Mat& templ, double& best_distance);

    protected:
        cv::Mat image, templ;

        cv::RNG rng;
        float epsilon;
        float delta;
        bool photometricInvariance;
        float minScale;
        float maxScale;
		cv::Size halfTempl;
		cv::Size halfImage;



		std::vector<MatchConfig> createListOfConfigs(MatchNet& net, cv::Size templ_size, cv::Size image_size);
        std::vector<cv::Mat> configsToAffine( std::vector<MatchConfig>& configs, std::vector<bool>& insiders );

        std::vector<MatchConfig> getGoodConfigsByDistance( std::vector<MatchConfig>& configs, float best_dist, float new_delta,
                                                      std::vector<double>& distances, float& thresh, bool& too_high_percentage );

        std::vector<MatchConfig> randomExpandConfigs( std::vector<MatchConfig>& configs, MatchNet& net,
                                                 int level, int no_of_points, float delta_factor );

        float getThresholdPerDelta( float delta );

        std::vector<double> evaluateConfigs( cv::Mat& image, cv::Mat& templ, std::vector<cv::Mat>& affine_matrices,
                                        cv::Mat& xs, cv::Mat& ys, bool photometric_invariance );


        cv::Mat preprocessImage(cv::Mat& image);
		cv::Mat makeOdd(cv::Mat& image);
        std::vector<cv::Point2f> calcCorners( cv::Size image_size, cv::Size templ_size, cv::Mat& affine );

    };



#endif /* defined(__FAsT_Match__FAsTMatch__) */
