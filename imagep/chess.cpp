#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int main()
{
	int i,j;
	Mat img(8,8,CV_8UC1,Scalar(0));
	for(i=0;i<im.rows;i++)
	{
		for(j=0;j<im.cols;j++)
		{
			if((i+j)%2==1)
				img.at<uchar>(i,j)=255;
		}
	}
	
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img);
	waitKey(0);
	return 0;
}