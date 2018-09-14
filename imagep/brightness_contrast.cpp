#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;

Mat im=imread("/Users/Anusha/Desktop/ip/b.jpg",0);
Mat temp=imread("/Users/Anusha/Desktop/ip/b.jpg",0);

void callback(int ,void*)
{
	int i,j,k;
	k=1;
	for(i=0;i<im.rows;i++)
	{
		for(j=0;j<im.cols;j++)
		{
			temp.at<uchar>(i,j)=im.at<uchar>(i,j)+t;
			temp.at<uchar>(i,j)= (int)((1+c/255)* im.at<uchar>(i,j));
		}
	}

	imshow("lin",temp);
}

int main()
{
	
	namedWindow("lin",WINDOW_NORMAL);
	createtrackbar("brightness","lin",&t,255,callback);
	createtrackbar("contrast","lin",&c,255,callback);
	waitKey(0);

	return 0;
}