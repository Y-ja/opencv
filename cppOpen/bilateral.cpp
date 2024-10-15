#include "opencv2/freetype.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main() {
    // 첫 번째 이미지 읽기
    Mat src = imread(folder + "img2.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    // 노이즈 추가
    Mat noise(src.size(), CV_32FC1);
    randn(noise, 0, 10); // 평균 0, 표준편차 10의 가우시안 노이즈 생성

    Mat noisyImage;
    src.convertTo(noisyImage, CV_32F); // src를 CV_32F로 변환
    noisyImage += noise; // 노이즈 추가
    noisyImage.convertTo(noisyImage, src.type()); // 원래 타입으로 변환

    Mat dst1, dst2;
    int sigma = 3;

    // Gaussian 블러 적용
    GaussianBlur(noisyImage, dst1, Size(0, 0), sigma);

    // Bilateral 필터 적용
    bilateralFilter(noisyImage, dst2, -1, 10, 5);

    // 원본 이미지, 노이즈 이미지, Gaussian 블러 이미지, Bilateral 필터 이미지 표시
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    imshow("Original Image", src);

    namedWindow("Noisy Image", WINDOW_AUTOSIZE);
    imshow("Noisy Image", noisyImage);

    namedWindow("Gaussian Blurred Image", WINDOW_AUTOSIZE);
    imshow("Gaussian Blurred Image", dst1);

    namedWindow("Bilateral Filtered Image", WINDOW_AUTOSIZE);
    imshow("Bilateral Filtered Image", dst2);

    waitKey(0); // 키 입력 대기
    return 0;
}
