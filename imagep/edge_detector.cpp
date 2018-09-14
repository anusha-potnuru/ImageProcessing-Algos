#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int gx,gy,t;
Mat im=imread("/Users/Anusha/Desktop/ip/a.jpg",0);
Mat temp(im.rows,im.cols,CV_8UC1,Scalar(0));

void callback(int ,void*)
{
	int i,j;
	for(i=0;i<im.rows-2;i++)
	{
		for(j=0;j<im.cols-2;j++)
		{
			gx= abs(im.at<uchar>(i,j+2)+2*im.at<uchar>(i+1,j+2)+im.at<uchar>(i+2,j+2)-im.at<uchar>(i,j)-2*im.at<uchar>(i+1,j)-im.at<uchar>(i+2,j));
			if(gx>t )
				temp.at<uchar>(i+1,j+1)=0;
			else
				temp.at<uchar>(i+1,j+1)=gx;
		}
	}
	for(i=0;i<im.rows-2;i++)
	{
		for(j=0;j<im.cols-2;j++)
		{
			gy=abs(im.at<uchar>(i,j)+im.at<uchar>(i,j+2)+2*im.at<uchar>(i,j+1)-im.at<uchar>(i+2,j)-2*im.at<uchar>(i+2,j+1)-im.at<uchar>(i+2,j+2));
			if(temp.at<uchar>(i+1,j+1)+gy>t )
				temp.at<uchar>(i+1,j+1)=0;
			else
				temp.at<uchar>(i+1,j+1)=temp.at<uchar>(i+1,j+1)+gy;
		}
	}
	imshow("win",temp);
}

int main()
{
	t=0;
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("thresh","win",&t,255,callback);
	callback(t,0);
	waitKey(0);

	return 0;
}