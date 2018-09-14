#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;

int t0l,t1l,t2l,t0h,t1h,t2h;
Mat im=imread("/Users/Anusha/Desktop/ip/a.jpg",1);
Mat temp(im.rows,im.cols,CV_8UC3,Scalar(0,0,0));

void callback(int ,void* )
{
	int i,j;

		for(i=0;i<im.rows;i++)		
		{
			for(j=0;j<im.cols;j++)
			{
			if(im.at<Vec3b>(i,j)[0] < t0l || im.at<Vec3b>(i,j)[0] > t0h )
				temp.at<Vec3b>(i,j)[0]=0;
			else
				temp.at<Vec3b>(i,j)[0]=im.at<Vec3b>(i,j)[0];

			if(im.at<Vec3b>(i,j)[1] < t1l || im.at<Vec3b>(i,j)[1] > t1h  )
				temp.at<Vec3b>(i,j)[0]=0;
			else
				temp.at<Vec3b>(i,j)[1]=im.at<Vec3b>(i,j)[1];
			if(im.at<Vec3b>(i,j)[2] < t2l || im.at<Vec3b>(i,j)[2] > t2h  )
				temp.at<Vec3b>(i,j)[2]=0;
			else
				temp.at<Vec3b>(i,j)[2]=im.at<Vec3b>(i,j)[2];			
			}
		}
	
	imshow("lin",temp);
}

int main()
{
	t0l=t1l=t2l=0;
	t0h=t1h=t2h=0;

	namedWindow("lin",WINDOW_NORMAL);
	createTrackbar("blue","lin",&t0l,255,callback);		
	createTrackbar("green","lin",&t1l,255,callback);	
	createTrackbar("red","lin",&t2l,255,callback);
	createTrackbar("blueh","lin",&t0h,255,callback);	
	createTrackbar("greenh","lin",&t1h,255,callback);	
	createTrackbar("redh","lin",&t2h,255,callback);
	waitKey(0);
	
	return 0;
}