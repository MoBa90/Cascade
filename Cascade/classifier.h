#ifndef CLASSIFIER
#define CLASSIFIER


#include <opencv2/core/core.hpp>
#include <caffe/caffe.hpp>
#include <string>
#include <iostream>
#include <stdio.h>
#include "node.h"

using std::string;

/* Pair (label, confidence) representing a prediction. */
typedef std::pair<string, float> Prediction;


class Classifier {
 public:
  Classifier() = default;
  Classifier(const string& model_file,
             const string& trained_file,
             const string& mean_file,
             const string& label_file);

  std::vector<Node> Classify(std::vector<Node>& imgsNode, int N = 5);

 private:
  void SetMean(const string& mean_file);

  std::vector<float> Predict(const cv::Mat& img);

  void WrapInputLayer(std::vector<cv::Mat>* input_channels);

  void Preprocess(const cv::Mat& img,
                  std::vector<cv::Mat>* input_channels);

 private:
  caffe::shared_ptr<caffe::Net<float> > net_;
  cv::Size input_geometry_;
  int num_channels_;
  cv::Mat mean_;
  std::vector<string> labels_;
};

#endif // CLASSIFIER
