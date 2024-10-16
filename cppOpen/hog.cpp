#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std; 

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main()
{
    // 이미지 파일 열기
    Mat frame = imread(folder + "imgss.jpg");
    if (frame.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    // HOGDescriptor 초기화
    HOGDescriptor hog;
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    
    vector<Rect> detected;
    hog.detectMultiScale(frame, detected); // 사람 감지

    // 감지된 영역에 사각형 그리기
    for (const auto& rect : detected) {
        rectangle(frame, rect, Scalar(0, 0, 255), 3);
    }

    // 원본 이미지와 감지된 이미지를 표시
    imshow("Original Image", frame);

    waitKey(0); // 키 입력 대기
    return 0;
}
