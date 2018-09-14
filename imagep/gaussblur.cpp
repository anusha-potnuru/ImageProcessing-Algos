#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int main()
{
	int i,j;
	Mat im=imread("/Users/Anusha/Desktop/ip/a.jpg",0);
	Mat temp=imread("/Users/Anusha/Desktop/ip/a.jpg",0);
	for(i=0;i<im.rows-2;i++)
	{
		for(j=0;j<im.cols-2;j++)
		{
			temp.at<uchar>(i+1,j+1)=(im.at<uchar>(i,j)/16+im.at<uchar>(i+1,j)/8+im.at<uchar>(i,j+1)/8+im.at<uchar>(i+1,j+1)/4+im.at<uchar>(i+2,j)/16+im.at<uchar>(i+1,j+2)/8+im.at<uchar>(i+2,j)/16+im.at<uchar>(i+2,j+1)/8+im.at<uchar>(i+2,j+2)/16);
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	//imshow("now",im);
	imshow("time",im);
	imshow("win",temp);
	waitKey(0);

	return 0;
}