#include <iostream>
#include <cmath>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace std;
using namespace cv;
float theta;
int i1,J,t;
Mat im=imread("/Users/Anusha/Desktop/ip/a.jpg",0);
int a = sqrt(im.rows*im.rows + im.cols*im.cols)+200;
Mat temp(a,a, CV_8UC1,Scalar(0));


void callback(int ,void*)
{
	int i,j,x,y,X,Y;
	theta= (double)(t*2*3.14)/360;
	for(i=0;i<im.rows;i++)
	{
		for(j=0;j<im.cols;j++)
		{
			x=i-im.rows/2;
			y=j-im.cols/2;
			X= ((double)x)*cos(theta)+((double)y)*sin(theta);
			Y= (-(double)x)*sin(theta)+((double)y)*cos(theta);
			i1=X+a/2;
			J=Y+a/2;
			temp.at<uchar>(i1,J)=im.at<uchar>(i,j);
		}
	}
	imshow("lin",temp);

}

int main()
{
	t=0;	
	namedWindow("lin",WINDOW_NORMAL);
	createTrackbar("thresh","lin",&t,360,callback);
	imshow("original",im);
	//callback(t,0);
	waitKey(0);

	return 0;
}