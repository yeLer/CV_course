#include "highgui.h"
int main04(int argvc, char **argv)
{
	cvNamedWindow("example1", CV_WINDOW_AUTOSIZE);//����һ������
	CvCapture *capture = cvCreateFileCapture("D:\\opencv\\video\\cplus.wmv");//ͨ����������ȷ��Ҫ��ȡ����Ƶ�ļ���
	//����һ��ָ�����Ƶ�ļ���ָ��
	IplImage *frame;//����һ��֡ͼ��ָ��
	while (1)
	{
		frame = cvQueryFrame(capture);//cvQueryFrame�������ڽ���Ƶ��һ֡��ͼ�������ڴ�
		if (!frame)
		{
			break;
		}
		cvShowImage("example1", frame);//��ʾ��ǰ֡��ͼƬ
		char c = cvWaitKey(35);//�ȴ��û���������û�а�����ȴ�35ms
		if (c==27)//ESC������Ӧ��ASCII��Ϊ27�����û�����ESC�������˴�����ѭ�����˳���Ƶ����
		{
			break;
		}
	}
	cvReleaseCapture(&capture);//�ͷ�CvCapture�ṹ�Ŀռ�
	cvDestroyWindow("example1");//���ٴ�����Դ
	return 0;
}