#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
Mat im=imread("/Users/Anusha/Desktop/ip/a.jpg",0);

void callback(int event, int x, int y, int d, void*)
{
	if(event==EVENT_LBUTTONDOWN)
		cout<<x<<" "<<y<<endl;
	else if(event == EVENT_MOUSEMOVE)
		cout<<x<<" "<<y<<endl;
}

int main()
{
	namedWindow("win",WINDOW_NORMAL);
	setMouseCallback("win",callback);
	imshow("win",im); 
	waitKey(0);
	return 0;
}