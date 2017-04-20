#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	String imageName("HappyFish.jpg");//By default
	cout<<imageName<<endl;
	if ( argc > 1)
	{
		imageName = argv[1];	
	}
	double t = (double)getTickCount();
	Mat image;
	
	image = imread(imageName,IMREAD_COLOR);//Read the file

	if (image.empty())
	{
		cout<<"could not open or find the image"<<std::endl;
		return -1;	
	}
	
	namedWindow("Display window",WINDOW_AUTOSIZE);//Create a window to show the image
	
	imshow("Display window",image);
	t = ((double)getTickCount() - t)/getTickFrequency();
	cout<<"Times passed in seconds: "<<t<<endl;
	waitKey(0);//wait for a keystroke in the window
	
	return 0;

}
