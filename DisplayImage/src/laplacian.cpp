#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace std;

using namespace cv;

//main function
int main(int argc, char** argv)
{
	Mat src,src_gray,dst;
	int kernel_size = 3;
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;
	string window_name = "Laplace Demo";
	
	int c;

	//load an image
	src = imread(argv[1]);

	if (!src.data)
		return -1;
	
	//Remove the noise by Gaussian blur 
	GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);
	
	//Convert the image to grayscale
	cvtColor(src,src_gray,CV_BGR2GRAY);	
	
	//Create the window
	namedWindow(window_name,CV_WINDOW_AUTOSIZE);

	//Apply Laplace function
	Mat abs_dst;
	
	Laplacian(src_gray,dst,ddepth,kernel_size,scale,delta,BORDER_DEFAULT);
	convertScaleAbs(dst,abs_dst);
	
	//show what you got

	imshow(window_name,abs_dst);
	
	c = waitKey(0);
	
	if (char(c) == 27)
		return -1;
	return 0;

}
