#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main()
{
    Mat src = imread(folder + "imgn.jpg", IMREAD_COLOR);

    if (src.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    // Haar Cascade 분류기 로드
    CascadeClassifier classifier(folder + "haarcascade_frontalface_default.xml");
    if (classifier.empty()) {
        cout << "Haar Cascade 분류기를 로드할 수 없습니다!" << endl;
        return -1;
    }

    // 얼굴 감지
    vector<Rect> faces;
    classifier.detectMultiScale(src, faces, 1.1, 3, 0, Size(30, 30));

    // 얼굴 주변에 박스 그리기
    for (const auto& face : faces) {
        rectangle(src, face, Scalar(255, 0, 0), 2); // 빨간색 박스
    }

    // 결과 이미지 표시
    imshow("Original Image", src);
    waitKey();
    return 0;
}
