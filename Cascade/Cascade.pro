
QT += core
QT -= gui
QT += widgets

CONFIG += c++11

TARGET = caffe_test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    classifier.cpp \
    cascade.cpp



#INCLUDEPATH +=  /usr/include/hdf5/serial/

#INCLUDEPATH += /usr/local/caffe/build_caffe/install/include
#INCLUDEPATH += /usr/local/caffe/build_caffe/src
#INCLUDEPATH += $$(CAFFE_PATH)/

#LIBS +=     -L/usr/local/caffe/build_caffe/install/lib \
#                    -lcaffe \
#                    -lboost_system
#                    -lcaffe-nv


#INCLUDEPATH += /usr/local/cuda/include
#LIBS += -L/usr/local/cuda/lib64 \
#            -lcudart \
#            -lcublas \
#            -lcurand
#LIBS+ = - lglog - lgflags - lprotobuf - lboost_system - lboost_thread - LLMDB - lleveldb - lstdc + lcudnn - lcblas - latlas

#/usr/local/caffe/build_caffe/install/lib/libcaffe-nv.so
#    CONFIG += link_pkgconfig
#    PKGCONFIG += libglog
#    PKGCONFIG += cublas-8.0

message(caffe Path = /media/mohamad/DATA/caffe/build_caffe)
    INCLUDEPATH +=  /usr/include/hdf5/serial/   #needed on some linux system   /media/mohamad/DATA/caffe/build_caffe

    INCLUDEPATH += /media/mohamad/DATA/caffe/build_caffe/install/include/
    INCLUDEPATH += /media/mohamad/DATA/caffe/build_caffe/

    LIBS += /media/mohamad/DATA/caffe/build_caffe/install/lib/libcaffe-nv.so # is the version from nvidia
            #-lcnmem \
            #-lproto

    LIBS += -lboost_system

    CONFIG += link_pkgconfig
    PKGCONFIG += libglog
    PKGCONFIG += cublas-9.0
#    PKGCONFIG += opencv

INCLUDEPATH += /usr/local/include/
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_flann -lopencv_imgproc

#/media/mohamad/DATA/Opencv/build/lib

HEADERS += \
    classifier.h \
    node.h \
    cascade.h
