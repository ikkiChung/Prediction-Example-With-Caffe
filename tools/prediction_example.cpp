#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "caffe/caffe.hpp"
#include "caffe/util/io.hpp"
#include "caffe/blob.hpp"

using namespace caffe;
using namespace std;


int main(int argc, char** argv)
{
	
	LOG(INFO) << argv[0] << " [GPU] [Device ID]";

    //Setting CPU or GPU
	if (argc >= 2 && strcmp(argv[1], "GPU") == 0) 
	{
		Caffe::set_mode(Caffe::GPU);
		int device_id = 0;
		if (argc == 3) 
        {
      		device_id = atoi(argv[2]);
    	}
		Caffe::SetDevice(device_id);
   		LOG(INFO) << "Using GPU #" << device_id;
	} 
	else 
	{
    	LOG(INFO) << "Using CPU";
    	Caffe::set_mode(Caffe::CPU);
	}

	// Set to TEST Phase
	Caffe::set_phase(Caffe::TEST);

	// Load net
	// Assume you are in Caffe master directory
	Net<float> net("./examples/prediction_example/prediction_example.prototxt");

	// Load pre-trained net (binary proto)
	// Assume you are already trained the cifar10 example.
	net.CopyTrainedLayersFrom("./examples/cifar10/cifar10_quick_iter_5000.caffemodel");

	float loss = 0.0;
	vector<Blob<float>*> results = net.ForwardPrefilled(&loss);
	LOG(INFO) << "Result size: "<< results.size();

	// Log how many blobs were loaded
	LOG(INFO) << "Blob size: "<< net.input_blobs().size();


	LOG(INFO)<< "-------------";
	LOG(INFO)<< " prediction :  ";

	// Get probabilities
	const boost::shared_ptr<Blob<float> >& probLayer = net.blob_by_name("prob");
	const float* probs_out = probLayer->cpu_data();
	
	// Get argmax results
	const boost::shared_ptr<Blob<float> >& argmaxLayer = net.blob_by_name("argmax");
	
	// Display results
	LOG(INFO) << "---------------------------------------------------------------";
	const float* argmaxs = argmaxLayer->cpu_data();
	for (int i = 0; i < argmaxLayer->num(); i++) 
	{
		LOG(INFO) << "Pattern:"<< i << " class:" << argmaxs[i*argmaxLayer->height() + 0] << " Prob=" << probs_out[i*probLayer->height() + 0];
	}
	LOG(INFO)<< "-------------";


	return 0;
}
