#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;

using namespace std;

//Global variables
Mat src,dst;
int top, bottom, left, right;

int borderType;
Scalar value;
string window_name = "copyMakeBorder Demo";
RNG rng(12345);

//function main
int main(int argc,char** argv)
{
	int c;
	//Load image
	src = imread(argv[1]);
 
	if (!src.data)
	{
		cout<<"No data entered,please enter the path to an image file."<<endl;
		return -1;
				
	}
	
	//brief how to for this program
	cout<<"\n\t copyMakeBorder Demo:"<<endl;
	cout<<"\t------------------------------"<<endl;
	cout<<"**press 'c' to set the border to a random constant value"<<endl;
	cout<<"**press 'r' to set the border to be replicated "<<endl;
	cout<<"**press 'ESC' to exit"<<endl;

	//create window
	namedWindow(window_name,CV_WINDOW_AUTOSIZE);
	
	//Initilize arguments for the filter
	top = (int)(0.05*src.rows);bottom = (int)(0.05*src.rows);
	left = (int)(0.05*src.cols);right = (int)(0.05*src.cols);
	dst = src;
	
	imshow(window_name,dst);

	while(true)
	{
		c = waitKey(500);
		
		if ((char)c == 27)
			break;
		else if((char)c == 'c' )
			borderType = BORDER_CONSTANT;
		else if((char)c == 'r')
			borderType = BORDER_REPLICATE;

		value = Scalar (rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
		copyMakeBorder(src, dst, top, bottom, left, right, borderType, value);
		imshow(window_name,dst);
	}
	
	return 0;
}
