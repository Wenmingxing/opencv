#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
//#include <>

using namespace std;
using namespace cv;

//function main
int main(int argc, char** argv)
{
	Mat src,dst;
	
	string src_window = "src window";
	string dst_window = "dst window";

	//load image
	src = imread(argv[1]);
	if (!src.data)
		return -1;

	//Convert to grayscale
	cvtColor(src,src,CV_BGR2GRAY);

	//Applying histogram equalization
	equalizeHist(src,dst);
	
	namedWindow(src_window,CV_WINDOW_AUTOSIZE);
	namedWindow(dst_window,CV_WINDOW_AUTOSIZE);
	
	imshow(src_window,src);
	imshow(dst_window,dst);
	
	waitKey(0);
	return 0;

}
