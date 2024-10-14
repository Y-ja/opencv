#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() 
{
    Mat img(400, 640, CV_8UC3, Scalar(255, 255, 255));  // 흰색 배경

    while (true)
    {
        // 배경을 흰색으로 초기화
        img.setTo(Scalar(255, 255, 255));

        // 사각형 그리기 (채워진 사각형)
        rectangle(img, Rect(50, 100, 100, 100), Scalar(0, 255, 0), FILLED);  // 초록색

        // 원 그리기 (채워진 원)
        circle(img, Point(300, 150), 50, Scalar(255, 0, 0), FILLED);  // 파란색

        // 타원 그리기 (채워진 타원)
        ellipse(img, Point(450, 150), Size(60, 30), 0, 0, 360, Scalar(0, 0, 255), FILLED);  // 빨간색

        // 타원의 외곽선 그리기
        ellipse(img, Point(450, 150), Size(60, 30), 0, 0, 360, Scalar(0, 0, 0), 2);  // 검은색 외곽선

        // 이미지 표시
        imshow("Shapes", img);

        // 스페이스 키를 누르면 종료
        if (waitKey(30) == 32) {  // 32는 스페이스 키의 ASCII 코드
            break;
        }
    }

    destroyAllWindows();  // 모든 창 닫기
    return 0;
}
