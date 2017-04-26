/*
Coded by luke on 26th April 2017
Aiming to use the shi-tomasi_corner detector
*/

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

//Global variables
Mat src, src_gray;

int maxCorners =23;
int maxTrackbar = 100;

RNG rng(12345);

string source_window = "image";


//Function header
void goodFeatureToTrackbar_demo(int,void*);

//main function
int main(int argc,char** argv)
{
	//Load source image and convert it to gray
	src = imread(argv[1],1);
	cvtColor(src,src_gray,CV_BGR2GRAY);
	
	//Create window
	namedWindow(source_window,CV_WINDOW_AUTOSIZE);
	imshow(source_window,src);

	//create the trackbar
	createTrackbar("Max corners",source_window,&maxCorners,maxTrackbar,goodFeatureToTrackbar_demo);

	goodFeatureToTrackbar_demo(0,0);

	waitKey(0);

	return 0;	
	
}

//function definition for the callback function

void goodFeatureToTrackbar_demo(int,void*)
{
	if (maxCorners < 1)
		maxCorners =1;
	
	//Parameter for shi-tomasi algorithm
	vector<Point2f> corners;
	double qualityLevel = 0.01;
	double minDistance = 10;
	int blockSize = 3;
	bool useHarrisDetector = false;
	double k =0.04;
	
	//copy the source image
	Mat copy;
	copy = src.clone();

	//Apply corner detection 
	goodFeaturesToTrack(src_gray,corners,maxCorners,qualityLevel,minDistance,Mat(),blockSize,useHarrisDetector,k);
	
	//Draw corners detected
	cout<<"Number of corners: "<<corners.size()<<endl;

	int r = 4;
	for (int i=0;i<corners.size();i++)
	{
		circle(copy,corners[i],r,Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255)),-1,8,0);
	
	}

	namedWindow("source_window",CV_WINDOW_AUTOSIZE);
	imshow("source_window",copy);
}	
