#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main() {
    // 첫 번째 이미지 읽기 (컬러로)
    Mat src = imread(folder + "img2.bmp", IMREAD_COLOR);
    
    if (src.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    // BGR 채널 분리
    vector<Mat> bgr;
    split(src, bgr);

    // 빈 채널 생성
    Mat empty(src.rows, src.cols, CV_8UC1, Scalar(0));

    // 각 채널만 포함된 이미지 생성
    vector<Mat> b_planes[3];
    b_planes[0] = {bgr[0], empty.clone(), empty.clone()}; // Blue Channel
    b_planes[1] = {empty.clone(), bgr[1], empty.clone()}; // Green Channel
    b_planes[2] = {empty.clone(), empty.clone(), bgr[2]}; // Red Channel

    Mat bsrc, gsrc, rsrc;
    merge(b_planes[0], bsrc); // Blue Channel
    merge(b_planes[1], gsrc); // Green Channel
    merge(b_planes[2], rsrc); // Red Channel

    // 채널 이름
    string channelNames[] = {"Blue Channel", "Green Channel", "Red Channel"};

    // 각각의 채널 이미지를 표시
    imshow(channelNames[0], bgr[0]); // B 채널
    imshow(channelNames[1], bgr[1]); // G 채널
    imshow(channelNames[2], bgr[2]); // R 채널

    // 각 채널만 포함된 이미지 표시
    imshow("Blue Channel Only", bsrc);
    imshow("Green Channel Only", gsrc);
    imshow("Red Channel Only", rsrc);
    
    // 원본 이미지를 표시
    imshow("Original Image", src);
    
    waitKey(0); // 키 입력 대기
    return 0;
}
