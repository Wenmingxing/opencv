#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace cv;

//global variables
string src_window = "src window";
string warp_window = "warp";
string warp_rotate_window = "warp rotate";

int main(int argc, char** argv)
{
	Mat src,warp_dst,warp_rotate_dst;
	Mat warp_mat(2,3,CV_32FC1);
	Mat rot_mat(2,3,CV_32FC1);
	//Point2f srcTri[3],dstTri[3];
	vector<Point2f> srcTri(3),dstTri(3);
	src = imread(argv[1]);
	if (!src.data)
		return -1;

	warp_dst = Mat::zeros(src.rows,src.cols,src.type());
	srcTri[0] = Point2f(0,0);
	srcTri[1] = Point2f(src.cols-1,0);
	srcTri[2] = Point2f(0,src.rows-1);

	dstTri[0] = Point2f(src.cols*0.0,src.rows*0.22);
	dstTri[1] = Point2f(src.cols*0.85,src.rows*0.25);
	dstTri[2] = Point2f(src.cols*0.15,src.rows*0.7);

	//Get the affine transform
	warp_mat = getAffineTransform(srcTri,dstTri);
	
	//Apply the afifine tranform to the dst
	warpAffine(src,warp_dst,warp_mat,src.size());

	//Set the rotation parameters
	Point center = Point(warp_dst.cols/2,warp_dst.rows/2);
	double angle = 50;
	double scale = 0.6;

	rot_mat = getRotationMatrix2D(center,angle,scale);
	
	warpAffine(warp_dst,warp_rotate_dst,rot_mat,src.size());

	//show the images
	namedWindow(src_window,CV_WINDOW_AUTOSIZE);
	imshow(src_window,src);
	
	namedWindow(warp_window,CV_WINDOW_AUTOSIZE);
	imshow(warp_window,warp_dst);
	
	namedWindow(warp_rotate_window,CV_WINDOW_AUTOSIZE);
	imshow(warp_rotate_window,warp_rotate_dst);

	waitKey(0);
	return -1;
}
