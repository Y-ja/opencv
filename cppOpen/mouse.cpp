#include "opencv2/freetype.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";
Mat src, display;

void onMouse(int event, int x, int y, int flags, void* data) {
    if (event == EVENT_MOUSEMOVE) {
        // 새로운 이미지를 복사하여 표시
        display = src.clone();

        // 사각형 그리기
        rectangle(display, Point(x - 20, y - 20), Point(x + 20, y + 20), Scalar(255, 0, 0), 2);

        // 이미지를 업데이트하여 표시
        imshow("img", display);
    }
}

int main() {
    src = imread(folder + "img2.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    // 원본 이미지를 복사하여 표시용 이미지 초기화
    display = src.clone();

    namedWindow("img");
    setMouseCallback("img", onMouse);

    imshow("img", display);
    waitKey(0); // 키 입력을 기다립니다.

    return 0;
}
