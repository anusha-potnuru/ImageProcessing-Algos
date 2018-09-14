#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
//RNG rng(12345);
Mat im=imread("/Users/Anusha/Desktop/1.jpg",1);
Mat im_gray,canny_output;
int t;

int main()
{
	//cvtColor(im, im_gray, BGR2GRAY);
	t=100;
  int s1=1,c=7;
 Mat im3;
	GaussianBlur(im, im, Size(3,3),2,2);
  adaptiveThreshold(im,  im3, 255, ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 2*s1 + 1, c);
	//namedWindow( "source", WINDOW_NORMAL);
  imshow("win",im3);
  vector< vector<Point> > contours;
   // vector<Vec4i> hierarchy;
    
    Mat drawing(im.rows,im.cols, CV_8UC3, Scalar(0,0,0));
    Canny( im3, canny_output, t, t*2, 3 );
    findContours(canny_output, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    //for( int i = 0; i< contours.size(); i++ )
    {
      Scalar color = Scalar(0,0,255 );
       drawContours( drawing, contours, -1, color, 2, 8, -1 );
    }

  // Show in a window
  //namedWindow( "Contours", WINDOW_NORMAL );
    imshow( "Contours", drawing );

  	  	
	//createTrackbar( "win", "s1", &t, 7, callback );
	imshow( "source" , im );

	//callback(0,0);
	waitKey(0);
	return 0;
}