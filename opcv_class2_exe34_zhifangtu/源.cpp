//直方图是一个简单的表格，表示一个图像中具有某个值的像素的数量。因
//此灰度图像有256个项目，也叫箱子。0号箱子提供值为0的像素的数量，1号箱子提供值为1的像素的数量，等等。
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	float histgram[256] = {0};
	
	cv::Mat dispMat = imread("D:\\1233.jpg");
	
	Mat dispMat_gray;//彩色图像转化成灰度图  
	cvtColor(dispMat, dispMat_gray, COLOR_BGR2GRAY);
	int gray=0;
	int height = dispMat_gray.rows;
	int width = dispMat_gray.cols	;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			gray = dispMat_gray.at<uchar>(j, i);
			histgram [gray] ++;
		}
	}

	for (int a = 0; a <255; a++)
	{
		cv::Point pt1;
		pt1.x = a;
		pt1.y =dispMat.rows;
		cv::Point pt2;
		pt2.x = a;
		pt2.y = (dispMat.rows - histgram[a])/5;
		line(dispMat_gray, pt1, pt2, CV_RGB(255, 0, 0),1, 8, 0);
	}

	

	imshow("src", dispMat_gray);
	waitKey(0);
	return 0;

}