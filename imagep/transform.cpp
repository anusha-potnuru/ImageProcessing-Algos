#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int i,t,k,j;

Mat im1=imread("/Users/Anusha/Desktop/ip/filter.png",1);
Mat im2=imread("/Users/Anusha/Desktop/ip/filter2.png",1);
Mat im(im1.rows,im1.cols,CV_8UC3,Scalar(0,0,0));

void callback(int, void*)
{
	float a=(float)t/256;
	for(i=0;i<im1.rows;i++)
	{	
		for(j=0;j<im1.cols;j++)
		{
			for(k=0;k<3;k++)
				im.at<Vec3b>(i,j)[k]=(float)a*im1.at<Vec3b>(i,j)[k]+(float)(1-a)*im2.at<Vec3b>(i,j)[k];
		}
	}
	imshow("win",im);
}
int main()
{
	cout<<im1.rows<<" "<<im1.cols<<endl;
	cout<<im2.rows<<" "<<im2.cols<<endl;
	t=0;
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("thresh","win",&t,256,callback);
	callback(t,0);
	waitKey(0);

	return 0;
}