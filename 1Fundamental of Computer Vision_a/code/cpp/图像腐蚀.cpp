#include<opencv2/highgui/highgui.hpp>// highguiͷ�ļ�
#include<opencv2\imgproc\imgproc.hpp>
using namespace cv;
int main09()
{
	Mat srcImg = imread("D:\\opencv\\pic\\mogu1.jpg");
	imshow("ͼ��ʴǰ",srcImg);
	//��ʼ��ʴ
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(50, 15));//���帯ʴ��������һ��Ϊ��ʴ��ͼ�Σ��ڶ���Ϊ��ʴ�Ĵ�С
	Mat disImg;
	erode(srcImg, disImg, element);
	imshow("Ч��ͼ", disImg);
	waitKey(0);
	return 0;
}