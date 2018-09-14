#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
Mat im=imread("/Users/Anusha/Desktop/ip/filter.jpg",0);
void erosion()
{
	vector<int> v;
	for(i=0;i<im.rows-1;i++)
	{
		for(j=0;j<im.cols-1;j++)
		{
			for(x=i;x<i+3;x++)
			{
				for(y=j;y<j+3;y++)
				{
					v.pushback(im.at<uchar>(x,y));
				}
			}
			sort(v.begin(),v.end());
			for(x=i;x<i+3;x++)
			{
				for(y=j;y<j+3;y++)
				{
					im.at<uchar>(x,y)=v[0];
				}
			}
			v.clear();

		}
	}


}

int main()
{
	erosion();
	namedWindow("lin",WINDOW_NORMAL);
	imshow("lin",im);
	waitKey(0);
	

	return 0;
}