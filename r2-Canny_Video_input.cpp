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

VideoCapture cap(0);


double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video
Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));
VideoWriter oVideoWriter1 ("output.avi", CV_FOURCC('P','I','M','1'), 20, frameSize, true);
VideoWriter oVideoWriter2 ("input.avi", CV_FOURCC('P','I','M','1'), 20, frameSize, true);


void CannyThreshold(int, void *){
	blur(src_gray,detected_edges,Size(3,3));
	Canny(detected_edges,detected_edges,lowThreshold,lowThreshold*ratio, kernel_size);
	dst=Scalar::all(0);
	src.copyTo(dst,detected_edges);
	imshow(window_name,dst);
	oVideoWriter1.write(dst);
}



int main(){

	Mat frame;
//	src=imread("images/windows.jpg");
	namedWindow(window_name,CV_WINDOW_AUTOSIZE);
	namedWindow("Video");
	createTrackbar("Min Threshold:",window_name,&lowThreshold,max_lowThreshold,CannyThreshold);


	while(char(waitKey(1))!='q'){
		cap>>src;
	//	CannyThreshold(0,0);
/*		if(!src.data)
				return -1;*/
		imshow("Video",src);
		oVideoWriter1.write(src);
		dst.create(src.size(),src.type());
		cvtColor(src,src_gray,CV_BGR2GRAY);
		CannyThreshold(0,0);
	}
	return 0;
}
