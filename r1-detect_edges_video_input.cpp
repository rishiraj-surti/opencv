#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<stdlib.h>
using namespace std;
using namespace cv;
int main(){

	Mat img_v, img_h, img;
	Mat frame;
	VideoCapture cap(0);

	float vertical_fk[5][5]={{0,0,0,0,0},{0,0,0,0,0},{-1,-2,6,-2,-1},{0,0,0,0,0},{0,0,0,0,0}};
	float horizontal_fk[5][5]={{0,0,-1,0,0},{0,0,-2,0,0},{0,0,6,0,0},{0,0,-2,0,0},{0,0,-1,0,0}};

	Mat filter_v=Mat(5,5,CV_32FC1, vertical_fk);
	Mat filter_h=Mat(5,5,CV_32FC1, horizontal_fk);

	namedWindow("Image");
	namedWindow("Image_V");
	namedWindow("Image_H");


	while(char(waitKey(1))!='q'){
		cap>>frame;
		cvtColor(frame,img,CV_RGB2GRAY);
		filter2D(img,img_h,-1,filter_h);
		filter2D(img,img_v,-1,filter_v);

		imshow("Image",img);
		imshow("Image_V",img_v);
		imshow("Image_H",img_h);

	}
	return 0;
}
