#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace std;

using namespace cv;

//Main function 

int main(int argc,char** argv)
{
	Mat src,src_gray;
	Mat grad;

	string window_name = "Sobel Demo-simple Edge Detector";

	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;
	
	int c;
	
	//load an image
	src = imread(argv[1]);
	
	if(!src.data)
		return -1;
	
	GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);

	//Convert it to gray
	cvtColor(src,src_gray,CV_BGR2GRAY);
	
	//Create an window
	namedWindow(window_name,CV_WINDOW_AUTOSIZE);

	//Generate grad_x grad_y 
	Mat grad_x,grad_y;
	Mat abs_grad_x,abs_grad_y;

	//Gradient x
	Sobel(src_gray,grad_x,ddepth,1,0,3,scale,delta,BORDER_DEFAULT);
	convertScaleAbs(grad_x,abs_grad_x);

	//Gradient y
	Sobel(src_gray,grad_y,ddepth,0,1,3,scale,delta,BORDER_DEFAULT);
	convertScaleAbs(grad_y,abs_grad_y);

	//Total gradient (approximate)
	addWeighted(abs_grad_x,0.5,abs_grad_y,0.5,0,grad);

	imshow(window_name,grad);
	
	c=waitKey(0);
	if (char(c) == 27 )
		return -1;
	return 0;

}
