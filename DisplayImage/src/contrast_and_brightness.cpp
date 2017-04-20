#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


using namespace std;
using namespace cv;

int main(int argc,char** argv)
{
	double alpha = 1.0;//Simple contrast control
	int beta =0;//Simple brightness control

	Mat image = imread(argv[1]);
	Mat new_image = Mat::zeros(image.size(),image.type());

	cout<<"Basic Linear Transforms"<<endl;
	cout<<"-----------------------"<<endl;
	cout<<"* Enter the alpha value [1.0-3.0]: ";cin>>alpha;
	cout<<"* Enter the beta value [0-100]: ";cin>>beta;

	for (int y = 0;y < image.rows;y++)
	{
		for (int x = 0;x < image.cols;x++)
		{
			for (int c = 0;c < 3;c++)
			{
				new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>(alpha * (image.at<Vec3b>(y,x)[c] ) + beta );	
			}
		}
	}

	namedWindow("original image",WINDOW_AUTOSIZE);
	namedWindow("new image",WINDOW_AUTOSIZE);
	
	imshow("original image",image);
	imshow("new image",new_image);

	waitKey(0);
	return 0;

}
