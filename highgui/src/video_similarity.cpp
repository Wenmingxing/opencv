/*
Coded by luke on 26th April,2017
Aiming to test the opencv c++ video class and similarity


*/

#include <iostream> //for standard I/O
#include <string> //for strings
#include <iomanip>//for controlling float print precision
#include <sstream> //string to number conversion

#include <opencv2/imgproc/imgproc.hpp> //opencv window i/o
#include <opencv2/highgui/highgui.hpp> //Gaussian blur
#include <opencv2/core/core.hpp> //Basix opencv structures(cv::Mat,scalar)

using namespace std;

using namespace cv;

double getPSNR(const Mat& I1, const Mat& I2);
Scalar getMSSIM(const Mat& I1,const Mat& I2);

int main(int argc,char** argv)
{
	help();
	
	if (argc!=5)
	{
		cout<<"notenough parameters"<<endl;
		return -1;	
	}
	
	stringstream conv;
	const string sourceReference = argv[1],sourceCompareWit = argv[2];
	int psnrTriggerValue,delay;

	conv<<argv[3]<<endl<<argv[4]; //put in the strings
	conv>>psnrTriggerValue>>delay; //Take out the numbers

	char c;
	int frameNUm = -1; //frame counter

	VideoCapture captRefrnc(sourceReference),capUndTst(sourceCompareWith);

	if (!captRefrnc.isOpened())
	{
		cout<<"cloud not open reference"<<sourceReference<<endl;
		return -1;
	}

	if (!capUndTst.isOpened())
	{
		cout << "cloud not open case test"<<sourceCompareWith
<<endl;	
		return -1;		
	}

	const string WIN_UT = "Under Test";
	const string WIN_RF = "Reference";

	//Windows
	namedWindow(WIN_RF,CV_WINDOW_AUTOSIZE);
	namedWindow(WIN_UT,CV_WINDOW_AUTOSIZE);
	cvMoveWindow(WIN_RF,400,0); //750,2(bernat =0)
	cvMoveWindow(WIN_UT,refS.width,0); //1500,2

	cout << "Reference frame resolution: width="<<refS.width<<" Height=">>refS.height<<" of nr#: "<<captRefrnc.get(CV_CAP_PROP_FRAME_COUNT)<<endl;
	
	cout<<"PSNR trigger value "<setiosflags(ios::fixed)<<setprecision(3)<<psnrTriggerValue<<endl;

	
	Mat frameReference,frameUnderTest;
	double psnrV;
	Scalar mssimv;

	for(;;) //show the image captured in the window and repeat
	{
		capRefrnc >>frameReference;
		capUndTst >> frameUnderTest;

		if (frameReference.empty() || frameUnderTest.empty())
		{
			cout<<"< < < Game over! > > >";
			break;
		}
	}

}
