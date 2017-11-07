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
#include <cascade.h>
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
//    Classifier classifier(model_file, trained_file, mean_file, label_file);

//    string file = "/home/mohamad/Downloads/FB_IMG_1508599203292.jpg";

//    std::cout << "Prediction: " << std::endl;

//    cv::Mat img = cv::imread(file, -1);
//    CHECK(!img.empty()) << "Unable to decode image " << file;
    


//    std::vector<Node> nodes;
//    Node n1;
//    n1.patch = img;
//    nodes.push_back(n1);

//    std::vector<Node> results = classifier.Classify(nodes);



//    for (int j = 0; j < results.size(); j++){
//        Node tmpNode = results[j];
//        /* Print the top N predictions. */
//        for (size_t i = 0; i < tmpNode.predictions.size(); ++i) {
//          Prediction p = tmpNode.predictions[i];
//          std::cout << std::fixed << std::setprecision(4) << p.second << " - \""
//                    << p.first << "\"" << std::endl;
//        }
//    }


    Classifier root(model_file, trained_file, mean_file, label_file);
    Classifier classifier1_1(model_file, trained_file, mean_file, label_file);
    Classifier classifier1_2(model_file, trained_file, mean_file, label_file);
    Classifier classifier1_1_1(model_file, trained_file, mean_file, label_file);
    Classifier classifier1_1_2(model_file, trained_file, mean_file, label_file);
    Classifier classifier1_2_1(model_file, trained_file, mean_file, label_file);
    Classifier classifier1_2_2(model_file, trained_file, mean_file, label_file);

    std::vector<Classifier> firstLevel;
    std::vector<std::vector<Classifier>> secondLevel;
    std::vector<Classifier> tmp1, tmp2;

    firstLevel.push_back(classifier1_2);
    firstLevel.push_back(classifier1_1);

    tmp1.push_back(classifier1_1_2);
    tmp1.push_back(classifier1_1_1);

    tmp2.push_back(classifier1_2_2);
    tmp2.push_back(classifier1_2_1);

    secondLevel.push_back(tmp2);
    secondLevel.push_back(tmp1);

    string file = "/home/mohamad/Downloads/FB_IMG_1508599203292.jpg";

    cv::Mat img = cv::imread(file, -1);
    CHECK(!img.empty()) << "Unable to decode image " << file;



    std::vector<Node> nodes;
    Node n1;
    n1.patch = img;
    nodes.push_back(n1);


    Cascade cascade(root, firstLevel, secondLevel);


    cascade.run(nodes);

    for (int j = 0; j < cascade.results.size(); j++){
        Node tmpNode = cascade.results[j];
        /* Print the top N predictions. */
        for (size_t i = 0; i < tmpNode.predictions.size(); ++i) {
          Prediction p = tmpNode.predictions[i];
          std::cout << std::fixed << std::setprecision(4) << p.second << " - \""
                    << p.first << "\"" << std::endl;
        }
    }



    std::cout << "finished..." << std::endl;


    return a.exec();
}

