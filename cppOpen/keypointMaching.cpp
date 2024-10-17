#include "opencv2/opencv.hpp"
#include <iostream>
#include <algorithm> // std::min을 사용하기 위한 헤더 추가

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main()
{
    // 이미지 파일 열기
    Mat src1 = imread(folder + "box.png", IMREAD_GRAYSCALE);
    Mat src2 = imread(folder + "box_in_scene.png", IMREAD_GRAYSCALE);

    // 이미지 로드 확인
    if (src1.empty() || src2.empty()) {
        cerr << "이미지를 열 수 없습니다. 경로를 확인하세요." << endl;
        return -1;
    }

    // ORB 객체 생성
    Ptr<Feature2D> feature = ORB::create();

    // 키포인트와 디스크립터 저장할 변수
    vector<KeyPoint> key1, key2;
    Mat desc1, desc2;

    // 키포인트 및 디스크립터 계산
    feature->detectAndCompute(src1, Mat(), key1, desc1);
    feature->detectAndCompute(src2, Mat(), key2, desc2);

    // 매칭을 위한 BFMatcher 객체 생성
    BFMatcher matcher(NORM_HAMMING);
    vector<DMatch> matches;
    matcher.match(desc1, desc2, matches);

    // 매칭된 키포인트의 수 출력
    cout << "매칭된 키포인트의 수: " << matches.size() << endl;

    // 매칭 결과를 거리 기준으로 정렬
    sort(matches.begin(), matches.end());

    // 좋은 매칭만 저장할 벡터
    vector<DMatch> good_matches;

    // 상위 N개의 매칭을 good_matches에 추가 (예: 10개)
    const size_t numGoodMatches = 10; // size_t로 변경
    for (size_t i = 0; i < min(numGoodMatches, matches.size()); i++) {
        good_matches.push_back(matches[i]);
    }

    // Homography 계산을 위한 키포인트 좌표 추출
    vector<Point2f> srcPoints, dstPoints;
    for (const auto& match : good_matches) {
        srcPoints.push_back(key1[match.queryIdx].pt);
        dstPoints.push_back(key2[match.trainIdx].pt);
    }

    // Homography 행렬 계산
    Mat homography = findHomography(srcPoints, dstPoints, RANSAC);

    // 원본 이미지에 변환 적용
    Mat warpedImage;
    warpPerspective(src1, warpedImage, homography, src2.size());

    // 원본 이미지와 매칭 결과 이미지 표시
    Mat imgMatches;
    drawMatches(src1, key1, src2, key2, good_matches, imgMatches);

    imshow("Original Image 1", src1);
    imshow("Original Image 2", src2);
    imshow("Good Matches", imgMatches);
    imshow("Warped Image", warpedImage); // 변환된 이미지 표시

    waitKey(0); // 키 입력 대기
    return 0;
}
