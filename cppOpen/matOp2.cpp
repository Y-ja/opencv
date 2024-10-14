#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() 
{
    String path = "/home/test/Desktop/opencv/opencv/cppOpen/build/wolf.bmp";  // 이미지 경로
    Mat img1 = imread(path);  // 이미지 로드

    // 이미지가 성공적으로 로드되었는지 확인
    if (img1.empty()) {
        cout << "이미지를 로드할 수 없습니다: " << path << endl;
        return -1;
    }

    Mat img2 = img1;          // img1의 참조를 img2에 할당
    Mat img3;
    img3 = img1;              // img1을 img3에 할당

    Mat img4 = img1.clone();  // img1을 깊은 복사하여 img4에 할당
    Mat img5;
    img1.copyTo(img5);       // img1을 img5에 복사

    img1.setTo(Scalar(0, 255, 255)); // img1의 색상을 변경

    // 각 이미지를 출력
    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("img4", img4);
    imshow("img5", img5);

    waitKey(0);  // 키 입력을 기다림
    return 0;
}
