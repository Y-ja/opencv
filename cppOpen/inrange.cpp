#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main() {
    // 첫 번째 이미지 읽기 (컬러로)
    Mat src = imread(folder + "img2.bmp", IMREAD_COLOR);
    
    if (src.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    // 이미지 색 공간 변환 (BGR -> HSV)
    Mat hsv;
    cvtColor(src, hsv, COLOR_BGR2HSV);

    // Hue 범위 설정
    int lowerHue = 40; // 하한
    int upperHue = 80; // 상한

    // Hue 범위에 해당하는 마스크 생성
    Mat dst;
    inRange(hsv, Scalar(lowerHue, 5, 0), Scalar(upperHue, 255, 255), dst);

    // 원본 이미지와 필터링된 이미지를 표시
    imshow("Original Image", src);
    imshow("Filtered Image", dst);

    waitKey(0); // 키 입력 대기
    return 0;
}
