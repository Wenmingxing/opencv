/*
Coded by luke on 26th April 2017
Aiming to use the feature detector interface in order to find interest points.
*/

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/nonfree.hpp>

#include <iostream>
#include <string>

using namespace std;

using namespace cv;

void readme();

//main function
int mainc(int argc, char** argv)
{
	if(argc != 3)
	{	readme();
		return -1;	
	}

	Mat img_1 = imread(argv[1],0);
	Mat img_2 = imread(argv[2],0);

	if(!img_1.data || !img_2.data)
	{
		cout<<"Error loading the images:"<<endl;
		return -1;	
	}

	//step 1:detect the keypoints using SURF detector
	int minHessian = 400;
	
	SurfFeatureDetector detector(minHessian);

	vector<KeyPoint> keypoints_1, keypoints_2;

	detector.detect(img_1,keypoints_1);
	detector.detect(img_2,keypoints_2);

	//draw the keypoints
	Mat img_keypoints_1,img_keypoints_2;
	drawKeypoints(img_1,keypoints_1,img_keypoints_1,Scalar::all(-1),DrawMatchesFlag::DEFAULT);
	drawKeypoints(img_2,keypoints_2,img_keypoints_2,Scalar::all(-1),DrawMatchesFlag::DEFAULT);

	//show detected (drawn) keypoints
	imshow("Keypoints 1",img_keypoints_1);
	imshow("Keypoints 2",img_keypoints_2);

	waitKey(0);
	retuen 0;

	
}

void readme()
{
	cout<<"Usage: ./SURF_detector <img1> <img2>"<<endl;

}
