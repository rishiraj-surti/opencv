#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<stdlib.h>
using namespace std;
using namespace cv;

int min_distance, max_corners;
void ontrackbar_mindistance(int pos, void *){
	min_distance=pos;
}

void ontrackbar_maxcorners(int pos, void *){
	max_corners=pos;
}
Mat img, img_g;
int main()
{
	VideoCapture cap(0);

	//	img=imread("images/squares.jpg");

	vector<Point2d> corners;
	float quality=0.01;
	min_distance=10;
	max_corners=100;

	int min=1;
	int max=200;

	namedWindow("Image");

	createTrackbar("Min_distance","Image",&min,max,ontrackbar_mindistance);
	ontrackbar_mindistance(10,0);
	createTrackbar("Max corners","Image",&min, max, ontrackbar_maxcorners);
	ontrackbar_maxcorners(50,0);
	while(char(waitKey(1))!='q'){

		cap>>img;
		cvtColor(img,img_g,CV_RGB2GRAY);
		goodFeaturesToTrack(img_g,corners,max_corners, quality, min_distance);
		Mat img_corners=img.clone();

		int i;
		for(i=0;i<corners.size();i++)
			circle(img_corners,corners[i],4,CV_RGB(255,0,0),-1);
		imshow("Image",img_corners);

	}
	return 0;

}
