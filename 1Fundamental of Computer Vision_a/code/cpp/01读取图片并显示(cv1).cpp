#include "highgui.h"
/**
��ȡͼƬ����ʾ����
*/
int main(int argc,char **argv)
{
	//IplImage *img = cvLoadImage(argv[1]);//cvLoadImage������ͼ���ļ��������ڴ�
	IplImage *img = cvLoadImage("D:\\opencv\\pic\\yelele.jpg",1);
	IplImage *img1 = cvLoadImage("D:\\opencv\\pic\\index.jpg", 1);
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);//cvNamedWindow��Ϊһ���߲���ýӿڣ���highgui.h���ṩ��
	//��������Ļ�ϴ���һ�����ڣ���һ������Ϊ���ڵ����ƣ��ڶ������������˴��ڵı任������0��ʾ���ڴ�С����
	//����CV_WINDOW_AUTOSIZE��1����ʾ���ڴ�С����ͼƬ�Ĵ�С��������Ӧ
	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example1", img);//ָ�����ĸ�������ʾ�ĸ�ͼƬ
	cvShowImage("Example2", img1);//ָ�����ĸ�������ʾ�ĸ�ͼƬ
	cvWaitKey(0);//ʹ������ͣ���ȴ��û��İ������������ò�������Ϊ0���߸�����ȴ��û����а���������
	//������Ϊ����ʱ��Ҫ�ȴ��Ժ��������ʱ��
	cvReleaseImage(&img);//�ͷ�ָ��ͼƬ��ָ��
	cvReleaseImage(&img1);
	cvDestroyWindow("Example1");//������ʾͼ��Ĵ���
	cvDestroyWindow("Example2");
	return 0;
}