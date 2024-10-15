#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main() {
    // 이미지 읽기
    Mat src = imread(folder + "img.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    // Hough 변환을 위한 이진 이미지 생성
    Mat binary;
    threshold(src, binary, 128, 255, THRESH_BINARY);

    // Hough 변환으로 선 검출
    vector<Vec2f> lines;
    HoughLines(binary, lines, 1, CV_PI / 180, 100);

    // 선을 그릴 이미지 생성
    Mat lineImage = Mat::zeros(src.size(), CV_8UC3);

    // Hough 선 그리기
    for (const auto& lineP : lines) {
        float rho = lineP[0];
        float theta = lineP[1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a * rho, y0 = b * rho;
        pt1.x = cvRound(x0 + 1000 * (-b));
        pt1.y = cvRound(y0 + 1000 * (a));
        pt2.x = cvRound(x0 - 1000 * (-b));
        pt2.y = cvRound(y0 - 1000 * (a));
        line(lineImage, pt1, pt2, Scalar(0, 0, 255), 1, LINE_AA); // 선 그리기
    }

    // 결과 표시
    imshow("Original Image", src);
    imshow("Hough Lines", lineImage);

    waitKey(0); // 키 입력 대기
    return 0;
}
