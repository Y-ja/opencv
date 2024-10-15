#include "opencv2/freetype.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main() {
    // 첫 번째 이미지 읽기
    Mat src = imread(folder + "img10.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    Point2f srcPts[3], dstPts[3];

    srcPts[0] = Point2f(0, 0);
    srcPts[1] = Point2f(src.cols - 1, 0);
    srcPts[2] = Point2f(src.cols - 1, src.rows - 1);
    
    dstPts[0] = Point2f(src.cols / 2, 0);
    dstPts[1] = Point2f(src.cols - 50, 0);
    dstPts[2] = Point2f(src.cols - 1, src.rows - 1);

    // 아핀 변환 행렬 계산
    Mat M = getAffineTransform(srcPts, dstPts);

    // 아핀 변환을 적용할 출력 이미지 크기 지정
    Mat dst;
    warpAffine(src, dst, M, src.size()); // 첫 번째 변환

    // 회전 변환을 위한 중심점과 행렬 계산
    Point2d cp(src.cols / 2, src.rows / 2);
    Mat M2 = getRotationMatrix2D(cp, 30, 0.6);

    // 첫 번째 변환된 이미지를 회전 변환 적용
    Mat dstRotated;
    warpAffine(dst, dstRotated, M2, src.size()); // 두 번째 변환

    // 원본 이미지와 변환된 이미지 표시
    imshow("Original Image", src);
    imshow("Warped Image", dst);
    imshow("Warped and Rotated Image", dstRotated);
    
    waitKey(0); // 키 입력 대기
    return 0;
}
