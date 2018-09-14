#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;

int t;
Mat im=imread("/Users/Anusha/Desktop/ip/a.jpg",0);
Mat temp(im.rows,im.cols, CV_8UC3, Scalar(0,0,0));

void callback0(int ,void* )
{
	int i,j;
	for(i=0;i<im.rows;i++)		
	{
		for(j=0;j<im.cols;j++)
		{
			if(im.at<uchar>(i,j)[0] < t0)
				temp.at<uchar>(i,j)=0;
			else
				temp.at<uchar>(i,j)=255;
		}
	}
	imshow("lin",temp);
}

void callback1(int ,void* )
{
	
	int i,j;
	for(i=0;i<im.rows;i++)		
	{
		for(j=0;j<im.cols;j++)
		{
			if(im.at<uchar>(i,j) < t1)
				temp.at<uchar>(i,j)=0;
			else
				temp.at<uchar>(i,j)=255;
		}
	}
	imshow("lin",temp);
}

void callback2(int ,void* )
{
	int i,j;
	for(i=0;i<im.rows;i++)		
	{
		for(j=0;j<im.cols;j++)
		{
			if(im.at<uchar>(i,j) < t2)
				temp.at<uchar>(i,j)=0;
			else
				temp.at<uchar>(i,j)=255;
		}
	}
	imshow("lin",temp);
}

int main()
{

	namedWindow("lin",WINDOW_NORMAL);
	createTrackbar("blue","lin",&t0,255,callback);
	callback0(t0,0);
	createTrackbar("green","lin",&t1,255,callback);
	callback1(t1,0);
	createTrackbar("red","lin",&t2,255,callback);
	callback2(t2,0);
	
	return 0;
}