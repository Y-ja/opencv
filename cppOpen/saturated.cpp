#include "opencv2/freetype.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main()
{
    // 이미지 읽기
    Mat src = imread(folder + "img2.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Error: Could not load image!" << endl;
        return -1;
    }

    Mat brightSrc, saturateSrc, contrastSrc, blurredSrc, edgeDetectedSrc;
    brightSrc = src.clone();
    saturateSrc = src.clone();
    contrastSrc = src.clone();
    blurredSrc = src.clone();
    edgeDetectedSrc = src.clone();

    // 밝기 조정
    int brightnessValue = 50; // 밝기 증가 값
    for (auto it = brightSrc.begin<uchar>(); it < brightSrc.end<uchar>(); ++it) {
        *it = saturate_cast<uchar>(*it + brightnessValue);  // 밝기 증가
    }

    // 포화도 조정 (그레이스케일 이미지는 포화도가 적용되지 않지만 색상을 위해 사용)
    cvtColor(src, saturateSrc, COLOR_GRAY2BGR); // 컬러 이미지로 변환
    // 포화도 조정
    double saturationValue = 1.5; // 포화도 비율 (1.0은 변화 없음)
    for (int y = 0; y < saturateSrc.rows; y++) {
        for (int x = 0; x < saturateSrc.cols; x++) {
            Vec3b& pixel = saturateSrc.at<Vec3b>(y, x);
            for (int c = 0; c < 3; c++) {
                pixel[c] = saturate_cast<uchar>(pixel[c] * saturationValue); // 포화도 증가
            }
        }
    }

    // 대비 조정
    double alpha = 1.5; // 대비 증가 값
    double beta = 0; // 밝기 변화 값
    contrastSrc.convertTo(contrastSrc, -1, alpha, beta); // 대비 조정

    // 흐림 효과 (Gaussian Blur)
    GaussianBlur(src, blurredSrc, Size(15, 15), 0); // 흐림 효과

    // 엣지 검출 (Canny)
    Canny(src, edgeDetectedSrc, 100, 200); // 엣지 검출

    // 결과 이미지 보여주기
    imshow("Original", src);
    imshow("Brightened", brightSrc);
    imshow("Saturated", saturateSrc);
    imshow("Contrast Adjusted", contrastSrc);
    imshow("Blurred", blurredSrc);
    imshow("Edge Detected", edgeDetectedSrc);

    waitKey(0); // 키 입력 대기
    return 0;
}
