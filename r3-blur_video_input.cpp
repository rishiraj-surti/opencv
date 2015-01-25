#include<iostream>
#include<cv.h>
#include<highgui.h>
using namespace std;
using namespace cv;

Mat img_b,img;
void BlurFunc(int k, void *){
	float blur[5][5]={{k,k,k,k,k},{k,k,k,k,k},{k,k,k,k,k},{k,k,k,k,k},{k,k,k,k,k}};
	// simple box kernel

	//float blur[5][5]={{1,4,6,4,1},{4,16,24,16,4},{6,24,36,24,6},{4,16,24,16,4},{1,4,6,4,1}};
	// Guassian kernel

		Mat filter_b=Mat(5,5,CV_32FC1,blur);

		filter2D(img,img_b,-1,filter_b);

 		imshow("Image_B",img_b);


}
int main()
{
	Mat frame;
	VideoCapture cap(0);
//	img=imread("images/image2.jpg");


	namedWindow("Image",CV_WINDOW_AUTOSIZE);

	 	int min=1;
 	int max=10;
 	namedWindow("Image_B",CV_WINDOW_AUTOSIZE);
 	 createTrackbar("Blurring","Image_B",&min,max,BlurFunc);

 	 while(char(waitKey(1))!='q'){
 		BlurFunc(0,0);
 		 cap>>img;

 		imshow("Image",img);
 	 }
 	 return 0;

}
