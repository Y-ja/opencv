#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std; 

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main()
{
    // 이미지 파일 열기
    Mat src = imread(folder + "imag.jpg", IMREAD_GRAYSCALE);
    
    // 이미지 로드 여부 확인
    if (src.empty()) {
        cerr << "이미지를 열 수 없습니다. 경로를 확인하세요: " << folder + "imga.jpg" << endl;
        return -1; // 오류 발생 시 종료
    }

    // 키포인트 저장할 벡터
    vector<KeyPoint> keypoint;
    FAST(src, keypoint, 60, true); // FAST 감지 수행

    // 첫 번째 키포인트가 존재하는 경우에만 원을 그림
    if (!keypoint.empty()) {
        Point pt(static_cast<int>(keypoint[0].pt.x), static_cast<int>(keypoint[0].pt.y));
        circle(src, pt, 10, Scalar(255), -1); // 흰색 원으로 그리기
    }

    // 원본 이미지와 감지된 이미지를 표시
    imshow("Original Image", src);
    waitKey(0); // 키 입력 대기
    return 0;
}
