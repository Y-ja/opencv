#include <iostream>
#include "opencv2/opencv.hpp"
#include <string>

int main() {
    std::string imagePath = "lena.bmp";  // 이미지 경로를 std::string으로 정의
    cv::Mat img;
    img = cv::imread(imagePath);  // 경로를 사용하여 이미지 읽기

    if (img.empty()) {
        std::cout << "이미지를 불러오지 못했습니다." << std::endl;
        return -1;  // 오류 코드 반환
    }

    cv::imshow("image", img);
    std::cout << "HELLO OPENCV" << std::endl;

    // 이미지를 저장하는 부분
    std::string outputPath = "output_lena.jpg";  // 저장할 파일 이름을 .jpg로 변경
    cv::imwrite(outputPath, img);  // 이미지를 파일로 저장

    int key = 0;
    // 스페이스바가 눌리면 창을 닫습니다.
    while (key != 32) {  // 32는 스페이스바의 ASCII 값
        key = cv::waitKey(0);
        std::cout << key << std::endl;
    }

    return 0;
}
