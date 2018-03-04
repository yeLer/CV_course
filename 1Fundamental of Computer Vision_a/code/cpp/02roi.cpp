#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;


void main()
{
	Mat pImg = imread("D:\\opencv\\pic\\katun.jpg", 1);
	//≈–∂œ «∑Òº”‘ÿÕº∆¨
	if (!pImg.data)
	{
		cout << "can't read the pic file!" << endl;
	}
	Rect rect(180,200,200,200);
	Mat roi = Mat(pImg, rect);
	//…ÓøΩ±¥Õº∆¨
	Mat pImgRect = pImg.clone();
	rectangle(pImgRect, rect, Scalar(0, 255, 0), 1);
	imshow("img with roi rect", pImgRect);
	imshow("roi", roi);
	waitKey(0);
}
