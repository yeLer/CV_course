#include <opencv2\opencv.hpp>
using namespace cv;
int main() {
	Mat img = cv::imread("D:\\opencv\\pic\\index.jpg");//读取图片

	imshow("test", img);//显示读取的图片

	waitKey();//等待按键

	return 0;
}