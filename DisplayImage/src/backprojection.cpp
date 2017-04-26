#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>

using namespace std;

using namespace cv;

//Global variables 
Mat src,hsv,hue;
int bins = 25;

//Function headers
void Hist_and_Backproj(int,void*);

//Function main
int main(int argc,char** argv)
{
	//read an image
	src = imread(argv[1],1);
	
	//Transfrom it to hsv
	cvtColor(src,hsv,CV_BGR2HSV);

	//use only the hue value
	hue.create(hsv.size(),hsv.depth());

	int ch[] = {0,0};
	mixChannels(&hsv,1,&hue,1,ch,1);

	//create trackbar to enter the number of bins
	string window_name = "source image";
	namedWindow(window_name,CV_WINDOW_AUTOSIZE);
	createTrackbar("*hue bins:",window_name,&bins,180,Hist_and_Backproj);

	Hist_and_Backproj(0,0);

	//show the image 
	imshow(window_name,src);
	
	//wait until user exits the program
	waitKey(0);
	return 0;

}

void Hist_and_Backproj(int,void*)
{
	MatND hist;
	int histSize = MAX(bins,2);
	float hue_range[] = {0,180};
	const float* range = {hue_range};
	
	//Get the histogram and normalize it
	calcHist(&hue,1,0,Mat(),hist,1,&histSize,&range,true,false);
	normalize(hist,hist,0,255,NORM_MINMAX,-1,Mat());
	
	//Get backprojection
	MatND backproj;
	calcBackProject(&hue,1,0,hist,backproj,&range,1,true);

	//Draw the backProj
	imshow("Backproj",backproj);

	//Draw the histogram
	int w = 400,h=400;
	int bin_w = cvRound((double)w/histSize);
	Mat histImg = Mat::zeros(w,h,CV_8UC3);

	for (int i =0;i<bins;i++)
		{rectangle(histImg,Point(i*bin_w,h),Point((i+1)*bin_w,h-cvRound(hist.at<float>(i)*h/255.0)),Scalar(0,0,255),-1);}
	
	imshow("Histogram",histImg);

}
