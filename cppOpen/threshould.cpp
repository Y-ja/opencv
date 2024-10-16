#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main()
{
    // 첫 번째 이미지 읽기 (그레이스케일로)
    Mat src = imread(folder + "img2.bmp", IMREAD_GRAYSCALE);
    Mat dst, dst2;

    if (src.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    // Otsu의 이진화 적용
    threshold(src, dst, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // 적응형 이진화 적용
    adaptiveThreshold(src, dst2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 2);

    // 결과 이미지 표시
    imshow("Original Image", src);
    imshow("Binary Image (Otsu)", dst);
    imshow("Adaptive Binary Image", dst2);

    waitKey();
    return 0;
}
