#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <stdlib.h>
//#include <stdio.h>
#include <iostream>

using namespace cv;

using namespace std;

//Global variables
int threshold_value = 0;
int threshold_type = 3;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;

Mat src,src_gray,dst;

char* window_name = "Threshold Demo";

char* trackbar_type = "Type: \n0: Binary\n1: Binary_inverted\n2: Truncated\n3:To zero\n4:to zeto Inverted";
char* trackbar_value = "Value";

//FUnction headers
void Threshold_Demo(int,void*);

//Main function
int main(int argc,char** argv)
{
	//load an image
	src = imread(argv[1],1);

	//convert the image to gray
	cvtColor(src,src_gray,CV_BGR2GRAY);
	
	//Create a window to display results
	namedWindow(window_name,CV_WINDOW_AUTOSIZE);

	//Create Trackbar to choose type of threshold
	createTrackbar(trackbar_type,window_name,&threshold_type,max_type,Threshold_Demo);

	createTrackbar(trackbar_value,window_name,&threshold_value,max_value,Threshold_Demo);

	//Call the function to initialize
	Threshold_Demo(0,0);

	//wait until user finishes program
	while(true)
	{
		int c;
		c = waitKey(20);
		if ((char)c == 27)
		{break;}

	}

}

//Function threshold demo
void Threshold_Demo(int,void*)
{
	/*
		0: binary
		1: binary inverted
		2: threshold truncated
		3: threshold to zero
		4: threshold to zero inverted
	*/
	threshold(src_gray,dst,threshold_value,max_BINARY_value,threshold_type);
	imshow(window_name,dst);
}	
