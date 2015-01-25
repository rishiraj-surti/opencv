#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<stdlib.h>
using namespace std;
using namespace cv;
Mat img;

bool lup=false, ldown=false;
Point corner1, corner2;
Rect box;

static void mouse_callback(int event, int x, int y, int, void * ){

	if(event==EVENT_LBUTTONDOWN){
		ldown=true;
		corner1.x=x;
		corner1.y=y;
	}
	if(event==EVENT_LBUTTONUP){
		lup=true;
		corner2.x=x;
		corner2.y=y;
	}
	if(ldown==true && lup==false){
		Point pt;
		pt.x=x;
		pt.y=y;

		Mat local_img=img.clone();
		rectangle(local_img,corner1,pt, Scalar(0,0,255));
		imshow("Image",local_img);
	}
	if(ldown==true && lup==true){

		box.width=abs(corner1.x-corner2.x);
		box.height=abs(corner1.y-corner2.y);
		box.x=min(corner1.x, corner2.x);
		box.y=min(corner1.y, corner2.y);

		Mat crop(img,box);
		namedWindow("Crop");
		imshow("Crop",crop);
		ldown=false;
		lup=false;
	}
}
int main(){
	img=imread("images/image2.jpg");
	namedWindow("Image");
	imshow("Image",img);
	setMouseCallback("Image",mouse_callback);
	while(char(waitKey(0))!='q'){}
	return 0;
}
