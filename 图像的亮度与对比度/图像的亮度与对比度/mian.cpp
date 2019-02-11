#include <iostream>
#include <opencv2\opencv.hpp>
using namespace std;
using namespace cv;
int main(int argc,char** argv) {
	Mat src1,dst1;
	string src_img = "https://github.com/du1009963012/openCV2/blob/master/ConsoleApplication1/ConsoleApplication1/back_image_9.jpg";
	src1 = imread("back_image_9.jpg");
	resize(src1,src1,src1.size()/3);
	//src1.convertTo(src1,CV_32F);
	dst1.create(src1.size(),src1.type());
	if (!src1.data) {
		cout << "文件不存在！";
		return 0;
	}
	int changes = src1.channels();
	float alpha = 0.8;
	float bate = 0;
	for (int row = 0; row < src1.rows;row++) {
		uchar* src1_row = src1.ptr<uchar>(row);//指针图像操作
		uchar* dst1_row = dst1.ptr<uchar>(row);//
		for (int col = 0; col < src1.cols;col++) {
			if (src1.channels() == 3) {

				dst1_row[col*dst1.channels()] =saturate_cast<uchar>(src1_row[col*dst1.channels()] * alpha + bate);
				dst1_row[col*dst1.channels() +1] = saturate_cast<uchar>(src1_row[col  *dst1.channels() +1] * alpha + bate);
				dst1_row[col*dst1.channels() +2] = saturate_cast<uchar>(src1_row[col  *dst1.channels() +2] * alpha + bate);
				
				/*float b = src1.at<Vec3b>(row, col)[0];//使用openCV自带的函数对像素进行操作
				float g = src1.at<Vec3b>(row, col)[1];
				float r = src1.at<Vec3b>(row, col)[2];
				
				dst1.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b*alpha + bate);
				dst1.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g*alpha + bate);
				dst1.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r*alpha + bate);*/
			}
			else if (src1.channels() == 1) {
				dst1_row[col ] = saturate_cast<uchar>(src1_row[col ] * alpha + bate);
			/*	dst1.at<uchar>(row, col)= saturate_cast<uchar>(src1.at<uchar>(row, col)* alpha + bate);*/
			}

		}
	}

	namedWindow("src",WINDOW_AUTOSIZE);
	imshow("src1",src1);
	imshow("dst1",dst1);
	waitKey(0);
	return 0;
}