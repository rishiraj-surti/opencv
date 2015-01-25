#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<stdlib.h>
using namespace std;
using namespace cv;

Mat frame, frame_threshold;
int rgb_slider=0;
int low_slider=30, high_slider=100;

int low_r=30, low_g=30, low_b=30, high_r=100, high_g=100, high_b=100;

void on_rgb_trackbar(int , void *){
	switch(rgb_slider){
	case 0:
		setTrackbarPos("Low threshold","segmentation",low_r);
		setTrackbarPos("High threshold","segmentation",high_r);
		break;
	case 1:
		setTrackbarPos("Low threshold", "segmentation", low_g);
		setTrackbarPos("High threshold", "segmentation", high_g);
		break;
	case 2:
		setTrackbarPos("Low threshold", "segmentation", low_b);
		setTrackbarPos("High threshold", "segmentation", high_b);
		break;
	}
}

void on_low_thresh_trackbar(int, void *){
	switch(rgb_slider){
	case 0:
		low_r=min(high_slider-1, low_slider);
		setTrackbarPos("Low threshold","segmentation", low_r);
		break;
	case 1:
		low_g=min(high_slider-1, low_slider);
		setTrackbarPos("Low threshold", "segmentation",low_g);
		break;
	case 2:
		low_b=min(high_slider-1, low_slider);
		setTrackbarPos("Low threshold", "segmentation", low_b);
		break;
	}
}

void on_high_thresh_trackbar(int, void *){
	switch(rgb_slider){
	case 0:
		high_r=max(high_slider, low_slider+1);
		setTrackbarPos("High threshold", "segmentation",high_r);
		break;
	case 1:
		high_g=max(high_slider, low_slider+1);
		setTrackbarPos("High threshold", "segmentation", high_g);
		break;
	case 2:
		high_b=max(high_slider, low_slider+1);
		setTrackbarPos("High threshold", "segmentation", high_b);
		break;
	}
}

int main()
{
	VideoCapture cap(0);
	namedWindow("video");
	namedWindow("segmentation");

	createTrackbar("0:R\n1:G\n3:B","segmentation",&rgb_slider, 2, on_rgb_trackbar);

	createTrackbar("Low threshold","segmentation", &low_slider, 255, on_low_thresh_trackbar);

	createTrackbar("High threshold","segmentation",&high_slider,255, on_high_thresh_trackbar);

	while(char(waitKey(1))!='q'){
		cap>>frame;
		if(frame.empty())
			break;
		inRange(frame,Scalar(low_b,low_g,low_r), Scalar(high_b,high_g,high_r),frame_threshold);
		imshow("video",frame);
		imshow("segmentation",frame_threshold);
	}
	return 0;

}
