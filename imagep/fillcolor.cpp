#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
Mat temp=imread("/Users/Anusha/Desktop/ip/shapes.jpg",1);
Mat im=imread("/Users/Anusha/Desktop/ip/shapes.jpg",1);

void callback1(int event, int x, int y, int d, void*)
{
	if(event==EVENT_LBUTTONDOWN)
	{

			Point pt=Point(x,y);
			circle(im, pt, 1, Scalar(255, 255, 0), 10, 8, 0);
		
	}
	imshow("win",im);
	waitKey(1);
}


void callback(int event, int x, int y, int d, void*)
{
	if(event==EVENT_MOUSEMOVE)
	{
		setMouseCallback("win",callback1);
	}
	
	imshow("win",im);
	waitKey(1);
}

int main()
{
	namedWindow("win",WINDOW_NORMAL);
	setMouseCallback("win",callback);
	imshow("win",im);
	waitKey(0);
	return 0;
}