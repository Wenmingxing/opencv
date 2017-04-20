#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

//Global veriables
Mat src,src_gray,dst,detected_edges;


int lowThreshold = 1;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
string window_name = "Edge Map";


//Function CannyThreshold
void CannyThreshold(int,void*)
{
	//Reduce noise with a kernel 3x3
	blur(src_gray,detected_edges,Size(3,3));
	
	//canny detector
	Canny(detected_edges,detected_edges,lowThreshold,lowThreshold*ratio,kernel_size);

	//Using Canny's output as a mask, we display our result
	dst = Scalar::all(0);

	src.copyTo(dst,detected_edges);
	imshow(window_name,dst);

}

//function main
int main(int argc, char** argv)
{
	//load the image 
	src = imread(argv[1]);
	
	if (!src.data)
		return -1;

	//Create a matrix of the same type sand size as src (for dst)

	dst.create(src.size(),src.type());
	
	//Convert the image to grayscale
	cvtColor(src,src_gray,CV_BGR2GRAY);

	//Create a window
	namedWindow(window_name,CV_WINDOW_AUTOSIZE);
	
	//Create a Trackbar for user to enter threshold
	createTrackbar("Min Threshold",window_name,&lowThreshold,max_lowThreshold,CannyThreshold);

	//show the image 
	CannyThreshold(0,0);
	

	waitKey(0);

	return 0;
}
