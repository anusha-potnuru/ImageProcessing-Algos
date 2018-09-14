#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int main()
{
	int i,j;
	vector<int> v[9];
	Mat im=imread("/Users/Anusha/Desktop/ip/a.jpg",0);
	Mat temp=imread("/Users/Anusha/Desktop/ip/a.jpg",0);
	for(i=0;i<im.rows-2;i++)
	{
		for(j=0;j<im.cols-2;j++)
		{
			for(a=0;a<3;a++)
			{
				for(b=0;b<3;b++)
					v.push_back(im.at<uchar>(i+a,j+b));
			}
			sort(v,v+v.size());

			temp.at<uchar>(i+1,j+1)=v[4];
			v.clear();
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	//imshow("now",im);
	imshow("time",im);
	imshow("win",temp);
	waitKey(0);

	return 0;
}