#include "highgui.h"
int main04(int argvc, char **argv)
{
	cvNamedWindow("example1", CV_WINDOW_AUTOSIZE);//创建一个窗口
	CvCapture *capture = cvCreateFileCapture("D:\\opencv\\video\\cplus.wmv");//通过参数设置确定要读取的视频文件，
	//返回一个指向该视频文件的指针
	IplImage *frame;//定义一个帧图像指针
	while (1)
	{
		frame = cvQueryFrame(capture);//cvQueryFrame函数用于将视频下一帧的图像载入内存
		if (!frame)
		{
			break;
		}
		cvShowImage("example1", frame);//显示当前帧的图片
		char c = cvWaitKey(35);//等待用户按键，若没有按键则等待35ms
		if (c==27)//ESC按键对应的ASCII码为27，当用户按下ESC按键，此处结束循环，退出视频播放
		{
			break;
		}
	}
	cvReleaseCapture(&capture);//释放CvCapture结构的空间
	cvDestroyWindow("example1");//销毁窗体资源
	return 0;
}