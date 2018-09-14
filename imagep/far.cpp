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
int n;
int x,y,a,b;
vector< pair<int,int> > v;
void dfs(int x,int y,int clr)
{
	pair<int,int> p(x,y);
	stack< pair<int,int> > s;
	s.push(p);
	visited.at<uchar>(x,y)=255;//means visited
	x=y=0;
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
						//int r=n%3;
						temp1.at<Vec3b>(i,j)[clr]=255;
						x=x+i;
						y=y+j;
						count++;

						visited.at<uchar>(i,j)=255;
						pair<int,int> p1(i,j);
						s.push(p1);
					}
			}
		}		
	}
	a=a/count;
	b=b/count;
	pair< int,int> p1(a,b);
	v.push_back(p1);
}

void colour()
{
	int max,clr=0,dist;
	vector< pair<int,int> >::iterator it,it1,a1,a2;
	a1=v.begin();
	for(it=v.begin()+1;it!=v.end();it++)
	{
		dist=sqrt((v[*it].first-v[*it1].first)*(v[*it]first-v[*it1].first)+ (v[*it].second-v[*it1].second)*(v.it.second-v.it1.second));
		if(max< dist )
		{
			dist=max;
			a2=it;			
		}
	}
	dfs(v[*a1].first, v[*a1].first, clr);
	dfs(v[*a2].first, v[*a2].first, clr);

}



int main()
{
	int k=0;n=0;
	for(int i=0;i<im.rows;i++)
	{
		for(int j=0;j<im.cols;j++)
		{
			if(visited.at<uchar>(i,j)==0 && im.at<uchar>(i,j)==0)
			{
				dfs(i,j,0);
				k++;
				n++;
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