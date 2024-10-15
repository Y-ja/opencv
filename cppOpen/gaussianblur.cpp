#include "opencv2/freetype.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main() {
    // 첫 번째 이미지 읽기
    Mat src1 = imread(folder + "img7.bmp", IMREAD_GRAYSCALE);
    if (src1.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    // 블러 효과 적용 (가우시안 블러 사용)
    Mat dst;
    int kernelSize = 5; // 커널 크기 (홀수여야 함)
    GaussianBlur(src1, dst, Size(kernelSize, kernelSize), 0); // 시그마 X: 0은 자동 계산

    // 원본 이미지와 블러 이미지 표시
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    imshow("Original Image", src1);

    namedWindow("Blurred Image", WINDOW_AUTOSIZE);
    imshow("Blurred Image", dst);

    waitKey(0); // 키 입력 대기
    return 0;
}
