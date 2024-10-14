#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() 
{
    Mat img1 = Mat(400, 640, CV_8UC3, Scalar(10, 0, 0));  // 3채널 이미지로 초기화
    Mat img2 = Mat(400, 640, CV_8UC1, Scalar(0));          // 단일 채널 이미지로 초기화
    Mat img3 = Mat(400, 640, CV_8UC3, Scalar(255, 0, 0));  // 3채널 이미지로 초기화 (파란색)
    Mat img4 = Mat(Size(640, 400), CV_8UC3, Scalar(0, 255, 0));  // 3채널 이미지로 초기화 (초록색)

    Mat img5 = Mat(400, 640, CV_8UC1, Scalar(0));          // 단일 채널 이미지로 초기화 (검정색)
    Mat img6 = Mat(400, 640, CV_8UC1, Scalar(255));        // 단일 채널 이미지로 초기화 (흰색)

    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("img4", img4);
    imshow("img5", img5);
    imshow("img6", img6);
    waitKey(0);
    return 0;
}
