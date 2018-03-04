#include<opencv2/highgui/highgui.hpp>// highgui头文件
#include<opencv2\imgproc\imgproc.hpp>
using namespace cv;
int main09()
{
	Mat srcImg = imread("D:\\opencv\\pic\\mogu1.jpg");
	imshow("图像腐蚀前",srcImg);
	//开始腐蚀
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(50, 15));//定义腐蚀参数，第一个为腐蚀的图形，第二个为腐蚀的大小
	Mat disImg;
	erode(srcImg, disImg, element);
	imshow("效果图", disImg);
	waitKey(0);
	return 0;
}