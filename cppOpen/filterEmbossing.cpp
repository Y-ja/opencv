#include "opencv2/freetype.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main() {
    // 첫 번째 이미지 읽기
    Mat src1 = imread(folder + "img4.bmp", IMREAD_GRAYSCALE);
    if (src1.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    // 이미지 데이터를 벡터로 변환
    vector<uchar> imageData(src1.total());
    src1.copyTo(Mat(imageData).reshape(1, src1.rows));

    // 엠보스 필터 정의
    float data[] = { -1, -1,  0,
                     -1,  0,  1,
                      0,  1,  1 };

    Mat embossKernel(3, 3, CV_32F, data);

    // 엠보스 효과 적용
    Mat dst;
    filter2D(src1, dst, CV_8U, embossKernel);

    // 결과를 벡터로 변환
    vector<uchar> embossedData(dst.total());
    dst.copyTo(Mat(embossedData).reshape(1, dst.rows));

    // 원본 이미지와 엠보스 이미지 표시
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    imshow("Original Image", src1);

    namedWindow("Embossed Image", WINDOW_AUTOSIZE);
    imshow("Embossed Image", dst);

    waitKey(0); // 키 입력 대기
    return 0;
}
