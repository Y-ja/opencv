#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;  // std 네임스페이스 추가

int main() {
    cv::Point p1(1, 1);          // cv::Point 초기화
    cv::Point2d p2(1.1, 2.1);    // cv::Point2d 초기화

    // Size 객체 배열 초기화
    Size sizes[] = { Size(640, 480), Size(800, 600), Size(1024, 768), Size(1920, 1080) };

    std::cout << "p1: " << p1 << std::endl;  // cv::Point 출력
    std::cout << "p2: " << p2 << std::endl;  // cv::Point2d 출력

    // Size와 Aspect Ratio 출력
    for (const auto& s : sizes) {
        double aspectRatio = static_cast<double>(s.width) / s.height;
        std::cout << "Size: " << s << " Aspect Ratio: " << aspectRatio << std::endl;
    }

    // Rect 객체 초기화
    Rect r1(10, 10, 100, 100);                // x, y, width, height
    Rect r2(20, 20, 40, 50);                  // x, y, width, height
    Rect r3(Point(20, 20), Size(40, 50));    // 시작점과 크기로 초기화
    Rect r4(p1, Size(30, 30));                // p1을 기준으로 크기 30x30의 Rect

    // Rect 객체 출력
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r3: " << r3 << endl;
    cout << "r4: " << r4 << endl;

    return 0;
}
