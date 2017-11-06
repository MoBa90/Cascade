#include <QCoreApplication>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <string>
#include <iostream>
#include <stdio.h>

#include <caffe_config.h>
#include <caffe/caffe.hpp>

#include <classifier.h>
#include "node.h"


using std::string;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    caffe::Caffe::set_mode(caffe::Caffe::GPU);
//    ::google::InitGoogleLogging(argv[0]);

    string model_file   = "/media/mohamad/DATA/google/deploy.prototxt";
    string trained_file = "/media/mohamad/DATA/google/snapshot_iter_1350.caffemodel";
    string mean_file    = "/media/mohamad/DATA/google/mean.binaryproto";
    string label_file   = "/media/mohamad/DATA/google/labels.txt";
    Classifier classifier(model_file, trained_file, mean_file, label_file);

    string file = "/home/mohamad/Downloads/FB_IMG_1508599203292.jpg";

    std::cout << "Prediction: " << std::endl;

    cv::Mat img = cv::imread(file, -1);
    CHECK(!img.empty()) << "Unable to decode image " << file;
    


    std::vector<Node> nodes;
    Node n1;
    n1.patch = img;
    nodes.push_back(n1);

    std::vector<Node> results = classifier.Classify(nodes);



    for (int j = 0; j < results.size(); j++){
        Node tmpNode = results[j];
        /* Print the top N predictions. */
        for (size_t i = 0; i < tmpNode.predictions.size(); ++i) {
          Prediction p = tmpNode.predictions[i];
          std::cout << std::fixed << std::setprecision(4) << p.second << " - \""
                    << p.first << "\"" << std::endl;
        }
    }

    std::cout << "hello" << std::endl;


    return a.exec();
}

