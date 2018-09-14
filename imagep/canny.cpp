#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int l,h;
Mat im=imread("/Users/Anusha/Desktop/ip/rubik.jpg",0);
Mat im1(im.rows, im.cols, CV_8UC1, Scalar(0));

void callback(int, void*)
{
	Canny(im, im1, l, h, 3);
	imshow("lin",im1);
}

int main()
{
	namedWindow("lin",WINDOW_NORMAL);	
	createTrackbar("lower","lin",&l,256,callback);
	createTrackbar("upper","lin",&h,256,callback);	
	waitKey(0);
	return 0;
}