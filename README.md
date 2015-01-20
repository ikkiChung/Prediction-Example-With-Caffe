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

The caffe makefile will automatic find the new exmaple and copy the result to build directory.

    caffe-master ikki$ ls ./build/tools/prediction_example*
    ./build/tools/prediction_example
    ./build/tools/prediction_example.bin
    ./build/tools/prediction_example.o
    ./build/tools/prediction_example.o.warnings.txt

Prediction
----------------

Just run the example.

    ./build/tools/prediction_example

For run on GPU device.

    ./build/tools/prediction_example GPU 0


