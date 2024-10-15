#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main() {
    // 첫 번째 이미지 읽기
    Mat src = imread(folder + "img.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    Mat dst1, dst2;

    // 첫 번째 Canny 엣지 검출
    Canny(src, dst1, 50, 150); // 경계 검출 강도 조정

    // 이미지에 Gaussian 블러를 적용한 후 Canny 엣지 검출
    Mat blurred;
    GaussianBlur(src, blurred, Size(5, 5), 1.5); // 블러 적용
    Canny(blurred, dst2, 50, 150); // 동일한 파라미터 사용, 다른 이미지에 적용

    // 원본 이미지와 두 Canny 이미지를 표시
    imshow("Original Image", src);
    imshow("Canny Image 1", dst1);
    imshow("Canny Image 2 (Blurred)", dst2);

    waitKey(0); // 키 입력 대기
    return 0;
}
