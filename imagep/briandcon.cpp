#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;

Mat im=imread("/Users/Anusha/Desktop/ip/a.jpg",0);
Mat temp=imread("/Users/Anusha/Desktop/ip/a.jpg",0);
int t,c;

void callback(int ,void*)
{
	int i,j,k;
	k=1;
	for(i=0;i<im.rows;i++)
	{
		for(j=0;j<im.cols;j++)
		{
			k=(im.at<uchar>(i,j)*c)/255;
			if(im.at<uchar>(i,j)+t+k <255)
				temp.at<uchar>(i,j)=im.at<uchar>(i,j)+t+k;
			else
				temp.at<uchar>(i,j)=255;
			//temp.at<uchar>(i,j)= (int)(c* im.at<uchar>(i,j)/255)+im.at<uchar>(i,j);
		}
	}

	imshow("lin",temp);
}

int main()
{
	namedWindow("lin",WINDOW_NORMAL);
	
	createTrackbar("brtnes","lin",&t,255,callback);
	//callback(t,0);
	createTrackbar("cntrst","lin",&c,255,callback);
	//callback(c,0);
	
	waitKey(0);

	return 0;
}