#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<stdlib.h>
using namespace std;
using namespace cv;

Mat src, src_gray;
Mat dst, detected_edges;
int edgeThresh=1;
int lowThreshold;
int const max_lowThreshold=100;
int ratio=3;
int kernel_size=3;
char* window_name="Edge Map";

void CannyThreshold(int, void *){
	blur(src_gray,detected_edges,Size(3,3));
	Canny(detected_edges,detected_edges,lowThreshold,lowThreshold*ratio, kernel_size);
	dst=Scalar::all(0);
	src.copyTo(dst,detected_edges);
	imshow(window_name,dst);
}

int main(){


	src=imread("images/windows.jpg");
	if(!src.data)
		return -1;
	dst.create(src.size(),src.type());
	cvtColor(src,src_gray,CV_BGR2GRAY);
	namedWindow(window_name,CV_WINDOW_AUTOSIZE);
	createTrackbar("Min Threshold:",window_name,&lowThreshold,max_lowThreshold,CannyThreshold);
	CannyThreshold(0,0);

	while(char(waitKey(0))!='q'){}
	return 0;
}
