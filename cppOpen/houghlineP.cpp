#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

Mat src; // 전역 변수로 src 선언
int lowThreshold = 50; // Canny 엣지 검출의 초기 임계값
const int maxLowThreshold = 100; // 트랙바 최대 값
const int cannyRatio = 3; // 고정 비율
const int kernel_size = 3; // 소벨 커널 크기

// Canny 엣지 검출 및 Hough 선 검출 함수
void processImage(int, void*) {
    Mat edges;
    Canny(src, edges, lowThreshold, lowThreshold * cannyRatio, kernel_size); // 경계 검출

    // HoughLinesP로 선 검출
    vector<Vec4i> lines;
    HoughLinesP(edges, lines, 1, CV_PI / 180, 100, 50, 10); // HoughLinesP 적용

    // 선을 그릴 이미지 생성
    Mat lineImage = Mat::zeros(src.size(), CV_8UC3);
    
    // Hough 선 그리기
    for (const auto& detectedLine : lines) {
        line(lineImage, Point(detectedLine[0], detectedLine[1]), Point(detectedLine[2], detectedLine[3]), Scalar(0, 0, 255), 2, LINE_AA);
    }

    // 원본 이미지와 Hough 선이 그려진 이미지 표시
    imshow("Original Image", src);
    imshow("Canny Edges", edges);
    imshow("Hough Lines", lineImage);
}

int main() {
    // 첫 번째 이미지 읽기
    src = imread(folder + "img.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    namedWindow("dst1");
    createTrackbar("Canny Threshold", "dst1", &lowThreshold, maxLowThreshold, processImage);
    
    // 처음에 한 번 이미지 처리
    processImage(0, 0);

    waitKey(0); // 키 입력 대기
    return 0;
}
