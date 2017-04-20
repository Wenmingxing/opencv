#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
	double alpha = 0.5;double beta; double input;
	Mat src1,src2,dst;
	
	cout<<"Simple Liear Blender"<<endl;
	cout<<"--------------------"<<endl;
	cin>>input;
	
	//We use the alpha provided by user if it is between 0 and 1
	if (input >= 0 && input<=1)
		alpha = input;
	src1 = imread("../data/LinuxLogo.jpg");
	src2 = imread("../data/WindowsLogo.jpg");

	if (src1.empty())
	{	cout<<"Error loading src1"<<endl;
		return -1;
	}

	if (src2.empty())
	{
		cout<<"Error loading src2"<<endl;
		return -1;
	}
	
	beta = (1.0 - alpha);
	addWeighted(src1,alpha,src2,beta,0.0,dst);
	
	imshow("linear Blend",dst);
	
	waitKey(0);
	return 0;
}	
