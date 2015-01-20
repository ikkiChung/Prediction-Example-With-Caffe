# Prediction-Example-With-Caffe

C++ Prediction Example With Caffe
===================

In this example, we will using cifar10_quick_iter_5000.caffemodel as pre-trained model.
And modified cifar10_quick_train_test.prototxt to get argmax for prediction.

Copy files to caffe master direcoty
---------------------

Copy files to your caffe master directory. keep the same dircctories and sub-directoies.

    caffe-master/

Compile Example
--------------------------------------------------

We assume you are ine the caffe master directory, just use make to compile our example.

    make

The caffe makefile will automatic find the new example and copy the result to build directory.

    caffe-master ikki$ ls ./build/tools/prediction_example*
    ./build/tools/prediction_example
    ./build/tools/prediction_example.bin
    ./build/tools/prediction_example.o
    ./build/tools/prediction_example.o.warnings.txt

Prediction
----------------

Just run the example.

    ./build/tools/prediction_example
    I0120 11:02:45.297869 2008834832 prediction_example.cpp:52] Result size: 3
    I0120 11:02:45.297899 2008834832 prediction_example.cpp:55] Blob size: 0
    I0120 11:02:45.297905 2008834832 prediction_example.cpp:58] -------------
    I0120 11:02:45.297910 2008834832 prediction_example.cpp:59]  prediction :  
    I0120 11:02:45.297919 2008834832 prediction_example.cpp:69] ------------------------------------------------------
    I0120 11:02:45.297924 2008834832 prediction_example.cpp:73] Pattern:0 class:5 Prob=2.69744e-06
    I0120 11:02:45.297940 2008834832 prediction_example.cpp:73] Pattern:1 class:3 Prob=4.0121e-05
    I0120 11:02:45.297948 2008834832 prediction_example.cpp:73] Pattern:2 class:9 Prob=0.00531694
    I0120 11:02:45.297956 2008834832 prediction_example.cpp:75] -------------


For run on GPU device.

    ./build/tools/prediction_example GPU 0
     

