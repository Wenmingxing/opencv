//coded by luke on 25th April 2017, aiming to set the bounding boxes and circles for the images.
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

//global veriables
Mat src,src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

//Function header
void thresh_callback(int, void*);

//Main function
int main(int argc,char** argv)
{
	//Load source image and convert it to gray
	src = imread(argv[1],1);
	
	//Convert to gray scale and blur it
	cvtColor(src,src_gray,CV_BGR2GRAY);
	blur(src_gray,src_gray,Size(3,3));

	//Create window
	string source_window = "source";

	namedWindow(source_window,CV_WINDOW_AUTOSIZE);
	imshow(source_window,src);

	//Create the trackbar and the attached the thresh_callback function with it
	createTrackbar("Thresh:",source_window,&thresh,max_thresh,thresh_callback);
	thresh_callback(0,0);

	waitKey(0);
	return 0;
} 

//Function definition
void thresh_callback(int,void*)
{
	Mat threshold_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	
	//Detect edges using threshold
	threshold(src_gray,threshold_output,thresh,255,THRESH_BINARY);
	
	//Find contours
	findContours(threshold_output,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));

	//Approximate contours to polygons + get bounding rects and circles
	vector<vector<Point> > contours_poly(contours.size());
	vector<Rect> boundrect(contours.size());
	vector<Point2f> center(contours.size());
	vector<float> radius(contours.size());
	
	for (int i =0;i<contours.size();i++)
	{
		approxPolyDP(Mat(contours[i]),contours_poly[i],3,true);
		boundrect[i] = boundingRect(Mat(contours_poly[i]));
		minEnclosingCircle((Mat)contours_poly[i],center[i],radius[i]);
	}

	//Draw polygonal contours + bounding rects+ circles
	Mat drawing = Mat::zeros(threshold_output.size(),CV_8UC3);
	for (int i=0;i<contours.size();i++)
	{
		Scalar color = Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
		drawContours(drawing,contours_poly,i,color,1,8,vector<Vec4i>(),0,Point());
		rectangle(drawing,boundrect[i].tl(),boundrect[i].br(),color,2,8,0);
		circle(drawing,center[i],(int)radius[i],color,2,8,0);	
	}

	//show in image
	namedWindow("contours",CV_WINDOW_AUTOSIZE);
	imshow("contours",drawing);
}
