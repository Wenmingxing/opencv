/*
Coded by luke on 26th April,2017
Aiming to study the harris corner detection

*/
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>

using namespace std;

using namespace cv;


//Global variables
Mat src,src_gray;
int thresh = 100;
int max_thresh = 255;
	
string source_window = "source";
string corner_window = "corner";

//Function header
void cornerHarris_demo(int,void*);

//Main
int main(int argc, char** argv)
{
	//load source image and convert it to gray scale	
	src = imread(argv[1],1);
	cvtColor(src,src_gray,CV_BGR2GRAY);

	//create a window and a trackbar
	namedWindow(source_window,CV_WINDOW_AUTOSIZE);
	
	createTrackbar("Threshold",source_window,&thresh,max_thresh,cornerHarris_demo);

	imshow(source_window,src);
	
	cornerHarris_demo(0,0);
		
	waitKey(0);

	return 0;

}

//function definition for the cornerHarris_DEMO
void cornerHarris_demo(int,void*)
{
	Mat dst,dst_norm,dst_norm_scaled;

	dst = Mat::zeros(src.size(),CV_32FC1);
	
	//Detector parameters
	int blockSize = 2;
	int apertureSize = 3;
	double k = 0.04;

	//Detection corners
	cornerHarris(src_gray,dst,blockSize,apertureSize,k,BORDER_DEFAULT);
	
	//Normalizing
	normalize(dst,dst_norm,0,255,NORM_MINMAX,CV_32FC1,Mat());
	convertScaleAbs(dst_norm,dst_norm_scaled);
	for (int j = 0; j<dst_norm.rows;j++)
	{
		for (int i =0;i<dst_norm.cols;i++)
			{
				if ((int)dst_norm.at<float>(j,i) > thresh)
					circle(dst_norm_scaled,Point(i,j),5,Scalar(0),2,8,0);			
			}
	}

	//showing the result
	namedWindow(corner_window,CV_WINDOW_AUTOSIZE);
	imshow(corner_window,dst_norm_scaled);

}
