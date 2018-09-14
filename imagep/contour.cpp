#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
RNG rng(12345);
Mat im=imread("/Users/Anusha/Desktop/ip/1.jpg",0);
Mat im_gray,canny_output;
int t;

void callback(int, void*)
{
	vector< vector<Point> > contours;
  	vector<Vec4i> hierarchy;
  	
  	Mat drawing(im.rows,im.cols, CV_8UC3, Scalar(0,0,0));
  	Canny( im, canny_output, t, t*2, 3 );
  	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
  	
 	   Scalar color = Scalar(0,0,255 );
       drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
    

  // Show in a window
 	namedWindow( "Contours", WINDOW_NORMAL );
  	imshow( "Contours", drawing );
}

int main()
{
	//cvtColor(im, im_gray, BGR2GRAY);
	t=100;
	blur(im, im, Size(3,3));
	namedWindow( "source", WINDOW_NORMAL);
  	  	
	createTrackbar( "thresh:", "source", &t, 255, callback );
	imshow( "source" , im );

	//callback(0,0);
	waitKey(0);
	return 0;
}