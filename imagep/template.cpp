#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
Mat im="coins.jpg";
Mat temp="coins(1).jpg";

void MatchingMethod(int , void*)
{
	double minVal; double maxVal; Point minLoc; Point maxLoc;
 	Point matchLoc;

	Mat result(im.rows-temp.rows+1, im.cols-temp.cols+1,CV_8UC3, Scalar(0,0,0));

	matchTemplate( img, temp, result, match_method );
 	normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );

 	minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );

 	if( match_method  == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED )
    { matchLoc = minLoc; }
  	else
    { matchLoc = maxLoc; }

  /// Show me what you got
  rectangle( img_display, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );
  rectangle( result, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );

  imshow( image_window, img_display );
  imshow( result_window, result );

  return;

}

int main()
{
	namedWindow( image, CV_WINDOW_AUTOSIZE );
 	namedWindow( result, CV_WINDOW_AUTOSIZE );
 	createTrackbar( trackbar_label, image_window, &match_method, 5, MatchingMethod );

	return 0;
}