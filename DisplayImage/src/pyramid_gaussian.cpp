#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
using namespace cv;
using namespace std;

//Global variables
Mat src,dst,tmp;
char* window_name = "Pyramids Demo";

//Function main

int main(int argc, char** argv)
{
	//General instructions
	cout<<"\n Zoom in-out demo \n"<<"-----------------\n"<<"*[u]->zoom in \n"<<"*[d]->zoom out\n"<<"*[ESC]->close program \n \n";

	//Test image- make sure it's divisible by 2^{n}
	src = imread("chicky.jpg");
	if (!src.data)
	{
		cout<<"No data!---- Exiting the program\n";
		return -1;

	}

	tmp = src;
	dst = tmp;

	//Create window
	namedWindow(window_name,CV_WINDOW_AUTOSIZE);
	imshow(window_name,dst);

	//loop
	while(true)
	{
		int c;
		c = waitKey(10);
		
		if ((char)c == 27)
			break;
		if ((char)c == 'u')
		{
			pyrUp(tmp,dst,Size(tmp.cols*2,tmp.rows*2));
			cout<<"** zoom in: image x 2"<<endl;
		}
	
		else if ((char)c == 'd')
		{
			pyrDown(tmp,dst,Size(tmp.cols/2,tmp.rows/2));
			cout<<"** zoom out: image /2"<<endl;
		
		}

		imshow(window_name,dst);
		tmp = dst;
	}
	return 0;
}
