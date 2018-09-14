#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <time.h>

using namespace std;
using namespace cv;

Mat shuffle(Mat img)
{
    srand(time(NULL));
    Mat img1(img.rows,img.cols,CV_8UC3);
    int occ[9]={0,0,0,0,0,0,0,0,0};
    int rn;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            
            while(1)
            {

                rn=rand()%9;
                if(occ[rn]==0)
                    break;
            }
            occ[rn]=1;
            int k=rn/3;
            int l=rn%3;
            for(int m=k*img.rows/3;m<(k*img.rows/3+img.rows/3);m++)
                for(int n=l*img.cols/3;n<(l*img.cols/3+img.cols/3);n++)
                    for(int o=0;o<3;o++)
                        img1.at<Vec3b>(m,n)[o]=img.at<Vec3b>(i*img.rows/3+m-k*img.rows/3,j*img.cols/3+n-l*img.cols/3)[o];
        }
        return img1;
}

Mat arrange(Mat img, Mat img1)
{
    int i,j;
    double minv, maxv;
    Point max,min;
    Mat tem(img.rows/3, img.cols/3,CV_8UC3),result(img.rows-tem.rows+1,img.cols-tem.cols+1,CV_8UC1), img2(img.rows,img.cols,CV_8UC3);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            for(int k=i*tem.rows; k<i*tem.rows+tem.rows; k++)
                for(int l=j*tem.cols; l<j*tem.cols+tem.cols; l++)
                    for(int m=0;m<3;m++)
                        tem.at<Vec3b>(k-i*tem.rows,l-j*tem.cols)[m]=img1.at<Vec3b>(k,l)[m];
            matchTemplate( img,tem,result, CV_TM_SQDIFF );
            minMaxLoc(result,&minv,&maxv,&min,&max);
            for(int k=min.y;k<min.y+tem.rows;k++)
                for(int l=min.x;l<min.x+tem.cols;l++)
                    for(int m=0;m<3;m++)
                        img2.at<Vec3b>(k,l)[m]=img1.at<Vec3b>(i*img.rows/3+k-min.y,j*img.cols/3+l-min.x)[m];
        }

    return img2;
}


int main()
{
    Mat img=imread("/Users/Anusha/Desktop/ip/ps1.jpg",1),img1(img.rows,img.cols,CV_8UC3),img2(img.rows,img.cols,CV_8UC3);
    namedWindow("Original Image",WINDOW_NORMAL);
    imshow("Original",img);
    waitKey(0);

    img1=shuffle(img);
    namedWindow("Shuff",WINDOW_NORMAL);
    imshow("Shuff",img1);
    waitKey(0);
    
    img2=arrange(img, img1);
    namedWindow("Arranged",WINDOW_NORMAL);
    imshow("Arranged",img2);
    waitKey(0);
    
    return 0;
}
