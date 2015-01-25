#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<stdlib.h>
using namespace std;
using namespace cv;
int main(){
	Mat frame;
	VideoCapture cap(0);
	namedWindow("Video");
	while(char(waitKey(1))!='q'){
		cap>>frame;
		imshow("Video",frame);
	}
	return 0;
}
