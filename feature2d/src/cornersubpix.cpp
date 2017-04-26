/*
coded by luke on 6th April 2017
Aiming to find more exact corner positions (more exact than integer pixels) by cornerSubpix method
*/

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

//Global variables
Mat src, src_gray;

int maxCorners = 10;
int maxTrackbar = 25;

RNG rng(12345);

string source_window = "image";

//Function header
void goodFeaturesToTrack_Demo(int,void*);

//Main function
int main(int argc,char** argv)
{
	//load the image and convert it to the gray scale
	src = imread(argv[1],1);
	cvtColor(src,src_gray,CV_BGR2GRAY);

	//blur the grayscale image to eliminate the noise
	blur(src_gray,src_gray,Size(3,3));
	
	//Create the window to show the original image
	namedWindow(source_window,CV_WINDOW_AUTOSIZE);
	imshow(source_window,src);
	
	//Create the trackbar and attach the callback function to it
	createTrackbar("Max Corners",source_window,&maxCorners,maxTrackbar,goodFeaturesToTrack_Demo);
	
	goodFeaturesToTrack_Demo(0,0);
	
	waitKey(0);
	return 0;
}

//Function definition for the callback function
void goodFeaturesToTrack_Demo(int ,void*)
{
	if(maxCorners < 1)
		maxCorners = 1;
	
	//Parameters for shi_tomasi_algorithm	
	vector<Point2f> corners;
	double qualityLevel = 0.01;
	double minDistance = 10;
	int blockSize = 3;
	bool useHarrisDetector = false;
	double k = 0.04;

	//copy the source image
	Mat copy;
	copy = src.clone();
	
	//apply the corner detector
	goodFeaturesToTrack(src_gray,corners,maxCorners,qualityLevel,minDistance,Mat(),blockSize,useHarrisDetector,k);

	
	//Draw corners detected
	cout<<"Number of the detected corners: "<<corners.size()<<endl;

	int r = 4;
	for (int i =0;i<corners.size();i++)
	{
		circle(copy,corners[i],r,Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255)),-1,8,0);
	}

	//show what you got 
	namedWindow("image2",CV_WINDOW_AUTOSIZE);
	imshow("image2",copy);

	//set the need parameters to find the refined corners
	Size winSize = Size(5,5);
	Size zeroZone = Size(-1,-1);

	TermCriteria criteria = TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER,40,0.001);

	//Calculate the refined corner locations
	cornerSubPix(src_gray,corners,winSize,zeroZone,criteria);
	
	for (int i =0;i<corners.size();i++)
		{cout << "--refined corner["<<i<<"] ("<<corners[i].x<<","<<corners[i].y<<" )"<<endl;
		}
}
