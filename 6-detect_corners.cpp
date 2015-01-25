#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<stdlib.h>
using namespace std;
using namespace cv;

Mat img, img_g;
int main()
{
	img=imread("images/squares.jpg");
	cvtColor(img,img_g,CV_RGB2GRAY);
	vector<Point2d> corners;
	float quality=0.01;
	int min_distance=10, max_corners=50;

	goodFeaturesToTrack(img_g,corners,max_corners, quality, min_distance);

	Mat img_corners=img.clone();

	int i;
	for(i=0;i<corners.size();i++)
		circle(img_corners,corners[i],4,CV_RGB(255,0,0),-1);
	namedWindow("Image");

	imshow("Image",img_corners);



	while(char(waitKey(1))!='q'){}
	return 0;

}
