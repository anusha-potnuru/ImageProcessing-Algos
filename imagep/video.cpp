#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int main()
{
	namedWindow("win",WINDOW_NORMAL);
	VideoCapture vid("perfect.mp4");
	Mat img;
	while(vid.read(img))
	{
		// code to modify img 
		imshow("perfect",img);
		waitKey(0);
	}
	return 0;
}



