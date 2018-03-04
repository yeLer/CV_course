#include "cv.h"
#include<opencv.hpp>
#include "highgui.h"
#include "iostream"
using namespace std;
//����һ��ͼ�񲢽���ƽ������
void image_handel(IplImage *image)
{
	//create two window to show some images of inputing or outputing
	cvNamedWindow("example-in",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("example-out", CV_WINDOW_AUTOSIZE);
	cvShowImage("example-in", image);//display the inputing image
	//create an image to hold the smoothed output
	IplImage *out = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 3);//pram1 get the size of image
	//pram2 ˵��ÿ��ͨ�������ص������  pram3 ˵����ͨ��������  ��ǰ��ͼ��Ϊ3ͨ��  ÿ��ͨ��Ϊ8λ  ͼ���Сͬimage
	//do the smoothing
	cvSmooth(image, out, CV_GAUSSIAN, 3, 3);
	//show the smoothed image in the output window
	cvShowImage("example-out", out);
	//be tidy (�����ڴ�)
	cvWaitKey(0);
	cvDestroyAllWindows();
}

//ʹ��cvPyrDown��������һ����Ⱥ͸߶�Ϊ����ͼ��һ���ͼ��
IplImage *doPyrDown(IplImage *in, int filter = CV_GAUSSIAN_5x5)
{
	//���ö���  ȷ��ͼ��Ĵ�С������������
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
	cvWaitKey(0); //�����
	cvReleaseImage(&img);
	cvDestroyWindow("Input");
}

/*
    cvCreateImage(size,depth,channels);�������÷�
    size ͼ�����.
����depth ͼ��Ԫ�ص�λ��ȣ����������������֮һ��
  ��IPL_DEPTH_8U - �޷���8λ����
	IPL_DEPTH_8S - �з���8λ����
	IPL_DEPTH_16U - �޷���16λ����
	IPL_DEPTH_16S - �з���16λ����
	IPL_DEPTH_32S - �з���32λ����
	IPL_DEPTH_32F - �����ȸ�����
	IPL_DEPTH_64F - ˫���ȸ�����
	channels��
	ÿ��Ԫ�أ����أ�ͨ����.������ 1, 2, 3 �� 4.ͨ���ǽ����ȡ�ģ�����ͨ���Ĳ�ɫͼ�����������ǣ�b0 g0 r0 b1 g1 r1 ... 
		��Ȼͨ�� IPL ͼ���ʽ���Դ����ǽ����ȡ��ͼ�񣬲���һЩOpenCV Ҳ�ܴ�����, �����������ֻ�ܴ��������ȡͼ��.
*/

//cvcanny��Ե��⽫���д��һ����ͨ�����Ҷȼ���ͼ��
IplImage *doCanny(IplImage *in,double lowThresh,double highThresh,double aperdure=3)
{
	if (in->nChannels!=1)
	{
		cout << "ͼ���ͨ����Ϊ1" << endl;
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
	cvWaitKey(0); //�����
	cvReleaseImage(&img);
	cvDestroyAllWindows();
}
/*
����ɫͼ��תΪ�Ҷ�ͼ��
    cvCvtColor(ԭʼͼ��,Ŀ��ͼ��,CV_BGR2GRAY); ��ס������������CV_BGR2GRAY��
���о���ԭʼͼ����RGB�ģ�����Ӧ������ͨ���ģ�Ŀ��ͼ����ת���ɵĻҶ�ͼ�����Զ����ʱ���ǵ�ͨ���ġ�
*/
int main11()
{
	IplImage *img = cvLoadImage("D:\\opencv\\pic\\katun.jpg", 1);//tree.jpg�ļ�������pic�ļ�������
	//image_handel(img);
	//test1(img);
	IplImage *img1 = cvLoadImage("D:\\opencv\\pic\\katun.jpg", 1);
	IplImage *img2 = cvCreateImage(cvSize(img1->width, img1->height), IPL_DEPTH_8U, 1);//������ͨ��ͼ������
    cvCvtColor(img1, img2, CV_RGB2GRAY);//��RGBͼ��ת��Ϊ��ͨ��ͼ��
	test2(img1,img2);
	return 0;
}