#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int main()
{
	Mat im=imread("/Users/Anusha/Desktop/ip/a.jpg",1);
	Mat temp(im.rows/2,im.cols/2,CV_8UC3);
	for(i=0;i<im.rows;i=i+2)
	{
		for(j=0;j<im.cols;j=j+2)
		{
			temp.at<uchar>(i,j)=(im.at<uchar>(i,j)+im.at<uchar>(i+1,j)+im.at<uchar>(i,j+1)+im.at<uchar>(i+1,j+1))/4;
		}

	}
	namedWindow("win",WINDOW_NORMAL);
	//imshow("now",im);
	imshow("time",im);
	imshow("win",temp);
	waitKey(0);


	return 0;
}