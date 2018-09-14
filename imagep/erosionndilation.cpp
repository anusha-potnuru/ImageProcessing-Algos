#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
Mat im=imread("/Users/Anusha/Desktop/ip/filter4.png",0);
Mat temp=imread("/Users/Anusha/Desktop/ip/filter4.png",0);
Mat im1;
//Mat im1=imread("/Users/Anusha/Desktop/ip/filter2.png",0);
//Mat temp1=imread("/Users/Anusha/Desktop/ip/filter2.png",0);

void erosion()
{
	int i,j,x,y;
	vector<int> v;
	for(i=0;i<im.rows-2;i++)
	{
		for(j=0;j<im.cols-2;j++)
		{
			for(x=i;x<i+3;x++)
			{
				for(y=j;y<j+3;y++)
				{
					v.push_back(im.at<uchar>(x,y));
				}
			}
			sort(v.begin(),v.end());
			for(x=i;x<i+3;x++)
			{
				for(y=j;y<j+3;y++)
				{
					temp.at<uchar>(x,y)=v[0];
				}
			}
			v.clear();
		}
	}
}

void dilation()
{
	int i,j,x,y;
	vector<int> v;
	for(i=0;i<im1.rows-2;i++)
	{
		for(j=0;j<im1.cols-2;j++)
		{
			for(x=i;x<i+3;x++)
			{
				for(y=j;y<j+3;y++)
				{
					v.push_back(im1.at<uchar>(x,y));
				}
			}
			sort(v.begin(),v.end());
			for(x=i;x<i+3;x++)
			{
				for(y=j;y<j+3;y++)
				{
					temp.at<uchar>(x,y)=v[8];
				}
			}
			v.clear();
		}
	}
}


int main()
{
	erosion();
	im1=temp.clone();
	dilation();
	im1=temp.clone();
	dilation();
	im1=temp.clone();
	dilation();
	//dilation();
	//dilation();
	namedWindow("lin",WINDOW_NORMAL);
	imshow("lin",temp);
	imshow("own",im);
	//imshow("lin1",im1);
	//imshow("own1",temp1);
	waitKey(0);
	return 0;
}