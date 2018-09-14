#include <iostream>
#include <cmath>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
Mat im=imread("/Users/Anusha/Desktop/ip/pentagon.png",0);
int a=sqrt(im.rows*im.rows+im.cols*im.cols);
Mat hough(a,360, CV_8UC1,Scalar(0));
Mat temp(im.rows,im.cols, CV_8UC1,Scalar(0));
int t,r;

void houghfunc()
{
	for(int i=0;i<im.rows;i++)
	{
		for(int j=0;j<im.cols;j++)
		{
			if(im.at<uchar>(i,j)>100)
				for(int theta=0;theta<360;theta++)
				{
					int x=j;
					int y=i;
					r=abs((double(x))*cos(theta*3.14/180)+(double(y))*sin(theta*3.14/180));
					cout<<r<<endl;
					
					if(hough.at<uchar>(r,theta)<245)
						hough.at<uchar>(r,theta)+=10;
					else
						hough.at<uchar>(r,theta)=255;
				}
		}
	}
}

void callback(int, void*)
{
	t=150;
	for(int i=0;i<hough.rows;i++)
	{
		for(int j=0;j<hough.cols;j++)
		{
			if(hough.at<uchar>(i,j)>t)
			{
				
				int x=abs((double(i))*cos(j*3.14/180));
				int y=abs((double(i))*sin(j*3.14/180));
				temp.at<uchar>(y,x)=255;

			}
		}
	}
	imshow("out",temp);
}


int main()
{
	t=0;	
	namedWindow("out",WINDOW_NORMAL);
	houghfunc();
	//imshow("lin",hough);
	createTrackbar("bright","out",&t,255,callback);
	waitKey(0);
	return 0;
}