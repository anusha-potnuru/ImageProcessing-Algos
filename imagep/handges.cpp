#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;

int main()
{
	char k;
	namedWindow("win",WINDOW_NORMAL);
	VideoCapture vid(0);
	Mat img,dt;
	while(vid.isOpened())
	{
		vid.read(img);
		cvtColor(img, img, COLOR_BGR2GRAY);
		GaussianBlur(img, img, Size(3,3), 0);
		adaptiveThreshold(img , dt,255, ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY_INV,11,2);
		
		imshow("perfect",img);
		k=waitKey(10);
		if(k=='q')
			break;
	}

}