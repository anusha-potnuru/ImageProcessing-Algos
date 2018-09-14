#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int main()
{
	Mat im=imread("/Users/Anusha/Desktop/ip/a.jpg",0);
	Mat temp=imread("/Users/Anusha/Desktop/ip/a.jpg",0);
	for(i=0;i<im.rows-2;i++)
	{
		for(j=0;j<im.cols-2;j++)
		{
			temp.at<uchar>(i+1,j+1)=(im.at<uchar>(i,j)+im.at<uchar>(i+1,j)+im.at<uchar>(i,j+1)+im.at<uchar>(i+1,j+1)+im.at<uchar>(i+2,j)+im.at<uchar>(i+1,j+2)+im.at<uchar>(i+2,j)+im.at<uchar>(i+2,j+1)+im.at<uchar>(i+2,j+2))/9;
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",temp);

	return 0;
}