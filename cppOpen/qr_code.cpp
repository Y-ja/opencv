#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std; 

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main()
{
    // 이미지 파일 열기
    Mat frame = imread(folder + "1vnO4.png");
    
    // QRCodeDetector 객체 생성
    QRCodeDetector detector;

    // QR 코드의 포인트를 저장할 벡터
    vector<Point> points; 
    String info = detector.detectAndDecode(frame, points); // QR 코드 감지 및 디코딩

    if (!info.empty()) {
        // QR 코드의 경계선을 그리기
        polylines(frame, points, true, Scalar(0, 255, 0), 2); // 초록색으로 선 그리기
        cout << "디코딩된 정보: " << info << endl; // 디코딩된 정보 출력
    } else {
        cout << "QR 코드가 감지되지 않았습니다." << endl; // QR 코드가 감지되지 않은 경우
    }

    // 원본 이미지와 감지된 이미지를 표시
    imshow("원본 이미지", frame);

    waitKey(0); // 키 입력 대기
    return 0;
}
