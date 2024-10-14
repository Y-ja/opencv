#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() 
{
    Vec3b p1, p2(0, 0, 255);
    p1[0] = 255;

    cout << "p1 -> " << p1 << endl;
    cout << "p2 -> " << p2 << endl;

    Scalar gray = 128;
    cout << "gray -> " << gray << endl;

    // Airy Blue로 초기화된 Mat 객체 생성
    Mat img1 = Mat(400, 400, CV_8UC3, Scalar(240, 248, 255));  // 3채널 (BGR)
    Mat img2 = Mat(400, 400, CV_8UC1, Scalar(200));             // 1채널 (Gray)
    Mat img3 = Mat(400, 400, CV_8UC3, Scalar(240, 248, 255));  // 3채널 (BGR)
    Mat img4 = Mat(400, 400, CV_8UC1, Scalar(200));             // 1채널 (Gray)
    Mat img5 = Mat(400, 400, CV_8UC3, Scalar(240, 248, 255));  // 3채널 (BGR)

    // 각 이미지를 출력
    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("img4", img4);
    imshow("img5", img5);

    waitKey(0);  // 키 입력을 기다림
    return 0;
}
