#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;

int t;
Mat im=imread("/Users/Anusha/Desktop/ip/1.jpg",0);

void callback(int ,void* )
{
	Mat temp(im.rows,im.cols, CV_8UC1, Scalar(0));
	int i,j;
	for(i=0;i<im.rows;i++)		
	{
		for(j=0;j<im.cols;j++)
		{
			if(im.at<uchar>(i,j) < t)
				temp.at<uchar>(i,j)=0;
			else
				temp.at<uchar>(i,j)=255;
		}
	}
	imshow("lin",temp);
}

int main()
{
	int i,j;
	t=0;		
	namedWindow("lin",WINDOW_NORMAL);
	createTrackbar("thresh","lin",&t,255,callback);
	callback(t,0);
	waitKey(0);

	return 0;
}