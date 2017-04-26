/*
coded by luke on 26th April 2017,
Aiming to produce the moments for the contours in an image


*/


#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>


using namespace std;
using namespace cv;

//Global variables
Mat src, src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

void thresh_callback(int,void*);

//main function
int main(int argc,char** argv)
{
	//load the image and convert it to gray scale
	src = imread(argv[1],1);
	cvtColor(src,src_gray,CV_BGR2GRAY);
	//Blur the gray_scale image to eliminate the noise
	blur(src_gray,src_gray,Size(3,3));

	//Create the window to show the original image
	string source_window = "source";
	namedWindow(source_window,CV_WINDOW_AUTOSIZE);
	imshow(source_window,src);

	//Create the trackbar and attached the callback function to it.
	createTrackbar("Canny thresh:",source_window,&thresh,max_thresh,thresh_callback);
	
	thresh_callback(0,0);
	
	waitKey(0);
	return 0;

} 

//function definition for the callback function
void thresh_callback(int, void*)
{
	Mat canny_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	//canny function to detect the edges of the gray_scale image
	Canny(src_gray,canny_output,thresh,thresh*2,3);

	//find the contours
	findContours(canny_output,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
	
	//Get the moments
	vector<Moments> mu(contours.size());
	for (int i=0;i<contours.size();i++)
		mu[i] = moments(contours[i],false);
	
	//Get the mass centers
	vector<Point2f> mc(contours.size());
	for (int i=0;i<contours.size();i++)
		mc[i] = Point2f(mu[i].m10/mu[i].m00,mu[i].m01/mu[i].m00);
		
	//draw the contours
	Mat drawing = Mat::zeros(canny_output.size(),CV_8UC3);
	/*for (int i =0 ;i<contours.size();i++)
	{
		Scalar color = Scalar(rng.uniform(0,255),rng.unifrom(0,255),rng.uniform(0,255));
		drawContours(drawing,contours,i,color,2,8,vector<Vec4i>(),0,Point());

		circle(drawing,mc[i],4,color,-1,8,0);
	}*/
	//show in image
	

	//calculate the area with the moments 00 and compare with result of the opencv  function	
	cout<<"\t info: Area and contour length"<<endl;

	for (int i =0;i<contours.size();i++)	
	{
		cout<<"*Contours["<<i<<"] - Area (M_00) = "<<mu[i].m00<<"- Area opencv:"<<contourArea(contours[i])<<"-length: "<<arcLength(contours[i],true)<<endl;
		Scalar color = Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
		drawContours(drawing,contours,i,color,2,8,hierarchy,0,Point());
		circle(drawing,mc[i],4,color,-1,8,0);	
	}
	namedWindow("contours",CV_WINDOW_AUTOSIZE);
	imshow("contours",drawing);


}
