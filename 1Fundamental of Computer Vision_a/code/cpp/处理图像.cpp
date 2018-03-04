#include "cv.h"
#include<opencv.hpp>
#include "highgui.h"
#include "iostream"
using namespace std;
//载入一副图像并进行平滑处理
void image_handel(IplImage *image)
{
	//create two window to show some images of inputing or outputing
	cvNamedWindow("example-in",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("example-out", CV_WINDOW_AUTOSIZE);
	cvShowImage("example-in", image);//display the inputing image
	//create an image to hold the smoothed output
	IplImage *out = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 3);//pram1 get the size of image
	//pram2 说明每个通道的像素点的类型  pram3 说明了通道的总数  当前的图像为3通道  每个通道为8位  图像大小同image
	//do the smoothing
	cvSmooth(image, out, CV_GAUSSIAN, 3, 3);
	//show the smoothed image in the output window
	cvShowImage("example-out", out);
	//be tidy (清理内存)
	cvWaitKey(0);
	cvDestroyAllWindows();
}

//使用cvPyrDown函数创建一副宽度和高度为输入图像一半的图像
IplImage *doPyrDown(IplImage *in, int filter = CV_GAUSSIAN_5x5)
{
	//设置断言  确定图像的大小可以整数减半
	assert(in->width % 2 == 0 && in->height % 2 == 0);
	IplImage *out = cvCreateImage(cvSize(in->width/2, in->height/2),in->depth,in->nChannels);
	cout << in->width << "  " << in->width / 2 << endl;
	cvPyrDown(in, out, filter);
	return out;
}
void test1(IplImage *img)
{
	cvNamedWindow("Input", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Output", CV_WINDOW_AUTOSIZE);
	cvShowImage("Input", img);
	cvShowImage("Output", doPyrDown(img));
	cvWaitKey(0); //必需的
	cvReleaseImage(&img);
	cvDestroyWindow("Input");
}

/*
    cvCreateImage(size,depth,channels);函数的用法
    size 图像宽、高.
　　depth 图像元素的位深度，可以是下面的其中之一：
  　IPL_DEPTH_8U - 无符号8位整型
	IPL_DEPTH_8S - 有符号8位整型
	IPL_DEPTH_16U - 无符号16位整型
	IPL_DEPTH_16S - 有符号16位整型
	IPL_DEPTH_32S - 有符号32位整型
	IPL_DEPTH_32F - 单精度浮点数
	IPL_DEPTH_64F - 双精度浮点数
	channels：
	每个元素（像素）通道号.可以是 1, 2, 3 或 4.通道是交叉存取的，例如通常的彩色图像数据排列是：b0 g0 r0 b1 g1 r1 ... 
		虽然通常 IPL 图象格式可以存贮非交叉存取的图像，并且一些OpenCV 也能处理他, 但是这个函数只能创建交叉存取图像.
*/

//cvcanny边缘检测将输出写入一个单通道（灰度级）图像
IplImage *doCanny(IplImage *in,double lowThresh,double highThresh,double aperdure=3)
{
	if (in->nChannels!=1)
	{
		cout << "图像的通道不为1" << endl;
		return 0;
	}
	IplImage *out = cvCreateImage(cvGetSize(in), IPL_DEPTH_8U, 1);
	cvCanny(in, out, lowThresh, highThresh, aperdure);
	return (out);
}
void test2(IplImage *img1, IplImage *img)
{
	cvNamedWindow("Input", CV_WINDOW_AUTOSIZE);
	cvShowImage("Input", img1);
	cvNamedWindow("Output1", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Output2", CV_WINDOW_NORMAL);
	cvShowImage("Output1", img);
	cvShowImage("Output2", doCanny(img,40,80));
	cvWaitKey(0); //必需的
	cvReleaseImage(&img);
	cvDestroyAllWindows();
}
/*
将彩色图像转为灰度图像
    cvCvtColor(原始图像,目标图像,CV_BGR2GRAY); 记住第三个参数是CV_BGR2GRAY；
还有就是原始图像是RGB的，所以应该是三通道的，目标图像是转换成的灰度图，所以定义的时候是单通道的。
*/
int main11()
{
	IplImage *img = cvLoadImage("D:\\opencv\\pic\\katun.jpg", 1);//tree.jpg文件放在了pic文件夹里面
	//image_handel(img);
	//test1(img);
	IplImage *img1 = cvLoadImage("D:\\opencv\\pic\\katun.jpg", 1);
	IplImage *img2 = cvCreateImage(cvSize(img1->width, img1->height), IPL_DEPTH_8U, 1);//创建单通道图像容器
    cvCvtColor(img1, img2, CV_RGB2GRAY);//将RGB图像转换为单通道图像
	test2(img1,img2);
	return 0;
}