//Coded by luke on April 25th 2017, find and draw the contours in the image

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>


using namespace std;
using namespace cv;

//GLobal variables
Mat src,src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

//Function header
void thresh_callback(int,void*);

//Main function 
int main(int argc, char** argv)
{
	//load the image and convert it to gray scale
	src = imread(argv[1],1);
	
	cvtColor(src,src_gray,CV_BGR2GRAY);

	blur(src_gray,src_gray,Size(3,3));

	//Create window
	string source_window = "source";
	namedWindow(source_window,CV_WINDOW_AUTOSIZE);
	imshow(source_window,src);
	
	createTrackbar("Canny thresh:","source",&thresh,max_thresh,thresh_callback);
	thresh_callback(0,0);

	waitKey(0);
	return 0;	

}

//Function thresh_callback
void thresh_callback(int,void*)
{
	Mat canny_output;
	vector< vector<Point> > contours;
	vector<Vec4i> hierarchy;
	
	//Detect edges using canny
	Canny(src_gray,canny_output,thresh,thresh*2,3);
	
	//Find contours
	findContours(canny_output,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));

	//Draw the contours
	Mat drawing = Mat::zeros(canny_output.size(),CV_8UC3);
	for (int i =0; i< contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
		drawContours(drawing,contours,i,color,2,8,hierarchy,0,Point());
	}
		
	//Show in a window
	namedWindow("Contours",CV_WINDOW_AUTOSIZE);
	imshow("Contours",drawing);
}
