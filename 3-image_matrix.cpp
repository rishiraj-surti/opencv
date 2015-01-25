#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<stdlib.h>
using namespace std;
using namespace cv;
int main(){

	Mat img=Mat(500,500,CV_32FC3,Scalar(300,400,500));
	namedWindow("Image");
	imshow("Image",img);

	while(char(waitKey(0))!='q'){}
	return 0;
}
