#include <opencv2\opencv.hpp>
using namespace cv;
int main() {
	Mat img = cv::imread("D:\\opencv\\pic\\index.jpg");//��ȡͼƬ

	imshow("test", img);//��ʾ��ȡ��ͼƬ

	waitKey();//�ȴ�����

	return 0;
}