//This program is aiming to test the vector<Point> to mat
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;
int main (int argc, char** argv)
{
	vector<Point> ve(10);
	Mat img = Mat(ve);
	cout << img.size()<<endl;
	cout << img.rows<<endl;
	cout<<img.cols<<endl;
	cout<<img.type()<<endl;
	cout<<img<<endl;

	cout<<ve.size()<<endl;
	cout<<ve<<endl;
	return 0;

}
