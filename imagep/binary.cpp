#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;

Mat im=imread("/Users/Anusha/Desktop/imagep/bin.jpg", CV_LOAD_IMAGE_GRAYSCALE);
Mat  dt(im.rows, im.cols, CV_8UC1, Scalar(0));

int main()
{
	GaussianBlur( im , im , Size( 3, 3 ), 0, 0);
	GaussianBlur( im , im , Size( 3, 3 ), 0, 0);
	medianBlur (im, im, 3);
	//threshold(im,dt, 127,255, THRESH_BINARY_INV);
	//adaptiveThreshold(im,dt,255, ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,11,2);
	adaptiveThreshold(im,dt,255, ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY_INV,11,2);
	namedWindow( "Contours", WINDOW_AUTOSIZE  );
	resize(im , im , Size(), 1, 0.5);
	resize(dt , dt , Size(), 1, 0.5);
	imshow( "Contours", im );
	waitKey(0);
  	imshow( "Contours", dt );
  	waitKey(0);
	return 0;
}