#include "opencv2/freetype.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

void drawHistogram(const Mat& src, Mat& histImage) {
    // 히스토그램 설정
    const int histSize = 256; // 히스토그램 크기
    float range[] = { 0, 256 }; // 범위
    const float* histRange = { range };
    
    // 히스토그램 계산
    Mat histogram;
    calcHist(&src, 1, 0, Mat(), histogram, 1, &histSize, &histRange);

    // 히스토그램 이미지 초기화
    histImage = Mat::zeros(300, 512, CV_8UC3);

    // 히스토그램 그리기
    for (int i = 1; i < histSize; i++) {
        line(histImage, Point((i - 1) * 2, 300 - cvRound(histogram.at<float>(i - 1))),
             Point(i * 2, 300 - cvRound(histogram.at<float>(i))),
             Scalar(255, 0, 0), 2, 8, 0);
    }
}

int main() {
    // 이미지 읽기
    Mat src = imread(folder + "img2.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    Mat dst;
    // 히스토그램 평활화
    equalizeHist(src, dst);

    // 원본 이미지와 평활화된 이미지 표시
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    imshow("Original Image", src);

    namedWindow("Equalized Image", WINDOW_AUTOSIZE);
    imshow("Equalized Image", dst);

    // 히스토그램 이미지 생성
    Mat histImageSrc, histImageDst;
    drawHistogram(src, histImageSrc);
    drawHistogram(dst, histImageDst);

    // 히스토그램 표시
    namedWindow("Histogram - Original", WINDOW_AUTOSIZE);
    imshow("Histogram - Original", histImageSrc);

    namedWindow("Histogram - Equalized", WINDOW_AUTOSIZE);
    imshow("Histogram - Equalized", histImageDst);

    waitKey(0); // 키 입력 대기
    return 0;
}
