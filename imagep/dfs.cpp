#include <iostream>
#include <stack>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
Mat im=imread("/Users/Anusha/Desktop/ip/dfs_path.jpg",0);
Mat visited(im.rows,im.cols,CV_8UC1,Scalar(0));
Mat temp1(im.rows,im.cols,CV_8UC3,Scalar(0,0,0));
Mat temp(im.rows,im.cols,CV_8UC1,Scalar(0));
int x=0;

void dfs(int x,int y)
{
	pair<int,int> p(x,y);
	stack< pair<int,int> > s;
	s.push(p);
	visited.at<uchar>(x,y)=255;//means visited
	while(!s.empty())
	{
		p=s.top();
		s.pop();
		for(int i=p.first-1;i<=p.first+1;i++)
		{
			for(int j=p.second-1;j<=p.second+1;j++)
			{
				if(i>=0 && i<im.rows && j>=0 && j<im.cols)
					if(visited.at<uchar>(i,j)==0 && im.at<uchar>(i,j)==0)				
					{
						temp.at<uchar>(i,j)=255;
						int b=x%3;
						temp1.at<Vec3b>(i,j)[b]=255;

						visited.at<uchar>(i,j)=255;
						pair<int,int> p1(i,j);
						s.push(p1);
					}
			}
		}		
	}
}

int main()
{
	int k=0;
	for(int i=0;i<im.rows;i++)
	{
		for(int j=0;j<im.cols;j++)
		{
			if(visited.at<uchar>(i,j)==0 && im.at<uchar>(i,j)==0)
			{
				dfs(i,j);
				x++;
				k++;
			}
		}
	}
	cout<<k<<endl;
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",visited);
	imshow("show",temp1);
	imshow("lin",temp);
	waitKey(0);
	return 0;
}