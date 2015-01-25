#include<iostream>
#include<cv.h>
#include<highgui.h>
using namespace std;
using namespace cv;

Mat img,img2,img3;
Mat st_elem_erode, st_elem_dilate;

int k_erode,k_dilate;
void ontrackbar_erode(int pos, void *){
	k_erode=pos;
	st_elem_erode=getStructuringElement(MORPH_RECT,Size(k_erode,k_erode));

}
void ontrackbar_dilate(int pos, void *){
	k_dilate=pos;
	st_elem_dilate=getStructuringElement(MORPH_RECT,Size(k_dilate,k_dilate));

}
int main()
{
	VideoCapture cap(0);

	k_erode=5;
	k_dilate=5;
	int min=1,max=20;
	img=imread("images/j.jpg");

	namedWindow("Image");
	namedWindow("Image2");
	namedWindow("Image3");

	createTrackbar("Erode","Image2",&min,max,ontrackbar_erode);
	createTrackbar("Dilate","Image3",&min,max,ontrackbar_dilate);



	while(char(waitKey(1))!='q'){
		cap>>img;
		//ontrackbar_erode(0,0);
		//ontrackbar_dilate(0,0);
		erode(img,img2,st_elem_erode);
		dilate(img,img3,st_elem_dilate);


		imshow("Image",img);
		imshow("Image2",img2);
		imshow("Image3",img3);

	}

	return 0;

}
