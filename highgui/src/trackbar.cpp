/*
Coded by luke on 26th April,2017
Aiming to use the createtrackbar to blend two images.
*/

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace std;

using namespace cv;


//global variables
const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;

//Matrices to store images
Mat src1,src2,dst;


//Function header
void on_trackbar(int,void*)
{
	alpha = (double)alpha_slider/alpha_slider_max;
	beta = (1.0 - alpha);

	addWeighted(src1,alpha,src2,beta,0.0,dst);

	imshow("Linear Blend",dst);
}

//Main function
int main(int argc, char** argv)
{
	//Load an image (same size,same type)
	src1 = imread(argv[1],1);
	src2 = imread(argv[2],1);

	if (!src1.data)
	{	cout<<"Error loading src1."<<endl;
		return -1;
	}
	if (!src2.data)
	{	cout<<"Error loading src2."<<endl;
		return -1;	
	}
	//Initialize values
	alpha_slider = 0;

	//create the window to show the image
	namedWindow("Linear Blend",CV_WINDOW_AUTOSIZE);
	
	
	//Create the trackbar
	createTrackbar("blend images","Linear Blend",&alpha_slider,alpha_slider_max,on_trackbar);
	
	//show the some stuff
	on_trackbar(0,0);
	
	//Wait until user press some key
	waitKey(0);
	return 0;

}
