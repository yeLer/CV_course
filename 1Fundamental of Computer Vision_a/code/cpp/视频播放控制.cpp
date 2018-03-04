#include "cv.h"
#include "highgui.h"

int g_slider_position = 0;//Ϊ������λ������һ��ȫ�ֱ���
int n = 0;//����һ��ȫ�ֱ��������ƹ�������λ��
CvCapture *g_capture = NULL;//�ص�������Ҫʹ��CvCapture�������������ｫ������Ϊȫ�ֱ���

void onTrackBarSlide(int pos)
{
	cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);//����CvCapture��Ӧ�����ԣ�
	//CV_CAP_PROP_POS_FRAMES��ʾ��֡����Ϊ��Ƶ�Ķ���λ�� 
	n = pos;
	return;
}

int main12(int argvc, char **argv)
{
	cvNamedWindow("example1", CV_WINDOW_NORMAL);//����һ������
    g_capture = cvCreateFileCapture("D:\\opencv\\video\\cplus.wmv");//��ȡ��Ƶ�ļ�
	int frames = cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);//��ȡCvCapture��Ӧ������
	//��ȡ��Ƶ����֡�����Բ�����Ƶ�ļ����п���
	if (frames!=0)
	{
		// "position"��ʾ�����������ƣ�"Example1"��ʾ��������������, g_slider_position��ʾ��������ǰλ�� 
		// frames��ʾ�����������ֵ��onTrackbarSlide��ʾ�������Ļص����������϶�ʱ���ã� 
		cvCreateTrackbar("position", "example1", &g_slider_position, frames, onTrackBarSlide);
	}
	IplImage *frame;//����һ��֡ͼ��ָ��
	while (1)
	{
		frame = cvQueryFrame(g_capture);//cvQueryFrame�������ڽ���Ƶ��һ֡��ͼ�������ڴ棬ÿ�ƶ�һ��
		//frame��ֵ�����1����λ
		if (!frame)
		{
			break;//��Ƶ������ϣ�frameֵΪ0����������
		}
		cvShowImage("example1", frame);//��ʾ��ǰ֡��ͼƬ
		cvSetTrackbarPos("position", "example1", n++);//������example1�����£�position�������ڵ�n��λ��
		char c = cvWaitKey(35);//�ȴ��û���������û�а�����ȴ�35ms
		if (c == 27)//ESC������Ӧ��ASCII��Ϊ27�����û�����ESC�������˴�����ѭ�����˳���Ƶ����
		{
			break;
		}
	}
	return 0;
}