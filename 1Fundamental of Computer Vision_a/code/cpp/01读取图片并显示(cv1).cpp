#include "highgui.h"
/**
读取图片并显示出来
*/
int main(int argc,char **argv)
{
	//IplImage *img = cvLoadImage(argv[1]);//cvLoadImage函数将图像文件加载至内存
	IplImage *img = cvLoadImage("D:\\opencv\\pic\\yelele.jpg",1);
	IplImage *img1 = cvLoadImage("D:\\opencv\\pic\\index.jpg", 1);
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);//cvNamedWindow作为一个高层调用接口，由highgui.h库提供，
	//用于在屏幕上创建一个窗口，第一个参数为窗口的名称，第二个参数则定义了窗口的变换，参数0表示窗口大小不变
	//参数CV_WINDOW_AUTOSIZE（1）表示窗口大小随着图片的大小进行自适应
	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example1", img);//指明在哪个窗口显示哪个图片
	cvShowImage("Example2", img1);//指明在哪个窗口显示哪个图片
	cvWaitKey(0);//使程序暂停，等待用户的按键操作，当该参数设置为0或者负数则等待用户进行按键操作，
	//当设置为正数时需要等待以毫秒计数的时间
	cvReleaseImage(&img);//释放指向图片的指针
	cvReleaseImage(&img1);
	cvDestroyWindow("Example1");//销毁显示图像的窗口
	cvDestroyWindow("Example2");
	return 0;
}