//Coded by luke on 25th April 2017, aiming to extract the convex hull from the image

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
//#include <stdlib.h>
//#include <stdio.h>
using namespace std;
using namespace cv;

//Global variables
Mat src,src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);
	
//Function header
void thresh_callback(int,void*);

	
//Main function 
int main(int argc, char** argv)
{
	//Load source and convert it to gray
	src = imread(argv[1],1);
	cvtColor(src,src_gray,CV_BGR2GRAY);
	
	blur(src_gray,src_gray,Size(3,3));

	//Create the window
	string source_window = "source";
	namedWindow(source_window,CV_WINDOW_AUTOSIZE);
	imshow(source_window,src);

	createTrackbar("Threshod:",source_window,&thresh,max_thresh,thresh_callback);
	
	thresh_callback(0,0);
	
	waitKey(0);
	return 0;

}

//Function definition
void thresh_callback(int,void*)
{
	Mat src_copy = src.clone();
	Mat threshold_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	//Detect the edges using threshold
	threshold(src_gray,threshold_output,thresh,255,THRESH_BINARY);

	//Find the contours
	findContours(threshold_output,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
	
	//Find the convex hull objects for each contour
	vector<vector<Point> > hull(contours.size());

	for (int i = 0 ;i<contours.size();i++)
		convexHull(Mat(contours[i]),hull[i],false);
	
	//Draw contours + hull results
	Mat drawing = Mat::zeros(threshold_output.size(),CV_8UC3);
	for (int i = 0; i<contours.size();i++)
	{
		Scalar color = Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
		drawContours(drawing,contours,i,color,1,8,vector<Vec4i>(),0,Point());
		drawContours(drawing,hull,i,color,1,8,vector<Vec4i>(),0,Point());

	}
	//show in the window
	namedWindow("Hull demo",CV_WINDOW_AUTOSIZE);
	imshow("Hull demo",drawing);
}
