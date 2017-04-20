#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

using namespace cv;

using namespace std;

static void help(char* progName)
{
	cout<<endl;
	<< "This program demonstrated the use of the discrete Fourier transform (DFT). "<<endl;
	<<"The dft of an image is taken and it's power spectrum is displayed "<<endl;
	<<"Usage:"<<endl;
	<<progName<<"[image_name == default ../data/lena.jpg] "<<endl<<endl;
}

int main (int argc,char** argv)
{
	help(argv[0]);
	
	const char* filename = argc > 2 ? argv[1] : "../data/lena.jpg";

	Mat I = imread(filename,IMREAD_GRAYSCALE);
	if (I.empty())
		return -1;
	
	Mat padded;//Expand input image to optimal size
	int m = getOptimalDFTSize(I.rows); 
	int n = getOptimalDFTSize(I.cols);//on the border add zero values
	copyMakeBorder(I,padded,0,m-I.rows,0,n-I.cols,BORDER_CONSTANT,Scalar::all(0));
	
	Mat planes[] = {Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F)};
	Mat complex1;
	merge(planes,2,complex1);//Add to the expanded another plane with zeros

	dft(complex1,complex1);//this way the result may fit in the source matrix

	//Compute the magnitude and switch to logarithmic scale
	//+>log(1+sqrt(Re(DFT(i)^2 + Im(DFT(I)^2))))
	split(complex1,planes);//planes[0] = Re planes[1] = Im
	
	
	
}
