/*

Coded by luke on 26th, April 2017
Aiming to show the bounding boxes and circle for the contours in an image

*/

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

Mat src, src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

//function header
void thresh_callback(int,void*);

//main function
int main(int argc,char** argv)
{
	//Load source image and convert it to gray
	src = imread(argv[1],1);

	//Convert it to gray scale and blur it for eliminating noise
	cvtColor(src, src_gray, CV_BGR2GRAY);
	blur(src_gray,src_gray,Size(3,3));
	
	//Create the window
	string source_window = "source window";
	namedWindow(source_window,CV_WINDOW_AUTOSIZE);
	imshow(source_window,src);
	
	//Create the trackbar and attached the thresh_callback function to it
	createTrackbar("thresh:",source_window,&thresh,max_thresh,thresh_callback);

	thresh_callback(0,0);
	waitKey(0);
	return 0;

}

//Function definition for the callback
void thresh_callback(int, void*)
{
	Mat threshold_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	//Detect the edges using threshod
	threshold(src_gray,threshold_output,thresh,255,THRESH_BINARY);
	
	//Find the contours and hierarchy
	findContours(threshold_output,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
	
	//Find the rotated rectangles and ellipses for each contour
	vector<RotatedRect> minRect(contours.size());
	vector<RotatedRect> minEllipse(contours.size());

	for (int i=0;i<contours.size();i++)
	{
		minRect[i] = minAreaRect(Mat(contours[i]));
		if (contours[i].size() > 5)
			minEllipse[i] = fitEllipse(Mat(contours[i]));
	} 

	//Draw the contours + rotated rects + ellipses
	Mat drawing = Mat::zeros(threshold_output.size(),CV_8UC3);
	for (int i= 0; i<contours.size();i++)
	{
		Scalar color=Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
		
		//contours
 		drawContours(drawing,contours,i,color,1,8,vector<Vec4i>(),0,Point());
			
		//ellipse
		ellipse(drawing,minEllipse[i],color,2,8);
		//rotated rectangle
		Point2f rect_points[4];
		minRect[i].points(rect_points);
		for (int j =0;j<4;j++)
		{
			line(drawing,rect_points[j],rect_points[(j+1)%4],color,1,8);	
		}
	}
	namedWindow("contours",CV_WINDOW_AUTOSIZE);
	imshow("contours",drawing);
}
