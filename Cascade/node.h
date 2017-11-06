#ifndef NODE
#define NODE


#include <vector>
#include <opencv2/opencv.hpp>

using std::string;

//typedef std::pair<string, float> Prediction;

using Prediction = std::pair<string, float> ;

struct Node {

    cv::Mat patch;

//    cv::Rect2i ImagePatch;
//    cv::Rect2i OriginalImagePatch;

    std::vector<Prediction> predictions;
};


#endif // NODE

