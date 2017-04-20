#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

//function main
int main(int argc, char** argv)
{
	Mat src,src_gray;

	src = imread(argv[1]);
	
	if (!src.data)
		return -1;
	
		
	//convert it to gray
	cvtColor(src,src_gray,CV_COLOR_BGR2GRAY);
	
	//Reduce the noise so we avoid false circle detection
	GaussianBlur(src_gray,src_gray,Size(9,9),2,2);
	
	vector<Vec3f> circles;

	//apply the hough transform to find circle
	HoughCircles(src_gray,circles,CV_HOUGH_GRADIENT,1,src_gray.rows/8,200,100,0,0);

	//Draw the circles detected
	for (size_t i = 0;i < circles.size();i++)
	{
		Point center(cvRound(circles[i][0]),cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
	
		//Circle center
		circle(src,center,3,Scalar(0,255,0),-1,8,0);//-1 means the circle is filled.
		//circle outline
		circle(src,center,radius,Scalar(0,0,255),3,8,0);			
	}

	//show your results
	namedWindow("HOugh circle transform demo",CV_WINDOW_AUTOSIZE);
	imshow("Hough circle Transform demo",src);
		
	waitKey(0);
	return 0;
}

