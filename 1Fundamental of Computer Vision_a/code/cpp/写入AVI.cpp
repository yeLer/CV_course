#include "highgui.h"
#include "cv.h"

int main07()
{
	//CvCapture是一个结构体，用来保存图像捕获的信息，就像一种数据类型（如int，char等）只是存放的内容不一样，
	//在OpenCv中，它最大的作用就是处理视频时（程序是按一帧一帧读取），让程序读下一帧的位置，CvCapture结构中，
	//每获取一帧后，这些信息都将被更新，获取下一帧回复。
	CvCapture *capture = 0;
	return 0;
}