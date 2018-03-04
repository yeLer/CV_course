#include "cv.h"
#include "highgui.h"

int g_slider_position = 0;//为滚动条位置设置一个全局变量
int n = 0;//定义一个全局变量，控制滚动条的位置
CvCapture *g_capture = NULL;//回调函数需要使用CvCapture变量，所以这里将其提升为全局变量

void onTrackBarSlide(int pos)
{
	cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);//设置CvCapture对应的属性，
	//CV_CAP_PROP_POS_FRAMES表示以帧数作为视频的读入位置 
	n = pos;
	return;
}

int main12(int argvc, char **argv)
{
	cvNamedWindow("example1", CV_WINDOW_NORMAL);//创建一个窗口
    g_capture = cvCreateFileCapture("D:\\opencv\\video\\cplus.wmv");//读取视频文件
	int frames = cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);//获取CvCapture对应的属性
	//获取视频的总帧数，对播放视频文件进行控制
	if (frames!=0)
	{
		// "position"表示滚动条的名称，"Example1"表示滚动条所属窗口, g_slider_position表示滚动条当前位置 
		// frames表示滚动条的最大值，onTrackbarSlide表示滚动条的回调函数（被拖动时调用） 
		cvCreateTrackbar("position", "example1", &g_slider_position, frames, onTrackBarSlide);
	}
	IplImage *frame;//定义一个帧图像指针
	while (1)
	{
		frame = cvQueryFrame(g_capture);//cvQueryFrame函数用于将视频下一帧的图像载入内存，每移动一次
		//frame的值会减少1个单位
		if (!frame)
		{
			break;//视频播放完毕，frame值为0，结束进程
		}
		cvShowImage("example1", frame);//显示当前帧的图片
		cvSetTrackbarPos("position", "example1", n++);//设置在example1窗口下，position滚动条在第n个位置
		char c = cvWaitKey(35);//等待用户按键，若没有按键则等待35ms
		if (c == 27)//ESC按键对应的ASCII码为27，当用户按下ESC按键，此处结束循环，退出视频播放
		{
			break;
		}
	}
	return 0;
}