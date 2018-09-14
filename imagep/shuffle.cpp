#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
Mat im=imread("/Users/Anusha/Desktop/ip/a.jpg",1);
Mat shuffle(im.rows,im.cols,CV_8UC3, Scalar(0,0,0));
Mat shuffle(im.rows/3,im.cols/3,CV_8UC3, Scalar(0,0,0));

void shuffle()
{
	vector< Pair<int,int> > v[9]={ (0,0), (im.rows/3+1,0), (2*im.rows/3+1,0), (0,im.cols/3+1), (im.rows/3+1,im.cols/3+1), (im.rows/3+1, 2*im.cols/3+1), ()



}

int main()
{
	srand(time(NULL));

	return 0;
}