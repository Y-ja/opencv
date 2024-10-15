#include "opencv2/freetype.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main() {
    // 첫 번째 이미지 읽기
    Mat src1 = imread(folder + "img256.bmp", IMREAD_GRAYSCALE);
    // 두 번째 이미지 읽기
    Mat src2 = imread(folder + "square.bmp", IMREAD_GRAYSCALE);

    // 이미지가 제대로 열렸는지 확인
    if (src1.empty() || src2.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    // 두 이미지가 동일한 크기인지 확인
    if (src1.size() != src2.size()) {
        cout << "두 이미지는 동일한 크기여야 합니다!" << endl;
        return -1;
    }

    Mat dst;
    // 논리 AND 처리
    bitwise_and(src1, src2, dst);

    // 결과 이미지 표시
    namedWindow("Image 1", WINDOW_AUTOSIZE);
    imshow("Image 1", src1);

    namedWindow("Image 2", WINDOW_AUTOSIZE);
    imshow("Image 2", src2);

    namedWindow("Logical AND Result", WINDOW_AUTOSIZE);
    imshow("Logical AND Result", dst);

    waitKey(0); // 키 입력 대기
    return 0;
}
