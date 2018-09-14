#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int main()
{
	float a;
	Mat im=imread("/Users/Anusha/Desktop/ip/1.jpg",0);
	Mat temp(im.rows,im.cols,CV_8UC1,Scalar(0));
	for(i=0;i<im.rows;i++)
	{
		for(j=0;j<im.cols;j++)
		{
			a=0.114* im.at<vec3b>(i,j)[0] + 0.299* im.at<vec3b>(i,j)[2] + 0.587*im.at<vec3b>(i,j)[1];  
			temp.at<uchar>(i,j)= (int)(a);
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",temp);
	waitKey(0);

	return 0;
}