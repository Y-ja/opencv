#include "opencv2/opencv.hpp"
#include "opencv2/aruco.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

int main()
{
    // 이미지 파일 열기
    Mat src = imread(folder + "markers.jpg", IMREAD_COLOR);
    if (src.empty()) {
        cerr << "이미지를 열 수 없습니다." << endl;
        return -1;
    }

    // 결과 이미지 표시
    imshow("Original Image", src);

    // ArUco 마커 탐지
    vector<int> markerIds;
    vector<vector<Point2d>> markerCorners;
    
    // 미리 정의된 ArUco 사전 가져오기
    Ptr<aruco::Dictionary> dictionary = aruco::getPredefinedDictionary(aruco::DICT_4X4_250);
    
    // 마커 탐지
    aruco::detectMarkers(src, dictionary, markerCorners, markerIds);

    // 마커가 탐지되었는지 확인
    if (!markerIds.empty()) {
        // 탐지된 마커 그리기
        aruco::drawDetectedMarkers(src, markerCorners, markerIds);
        
        // 카메라 매트릭스 및 왜곡 계수 (예시 값 사용)
        Mat cameraMatrix = (Mat_<double>(3, 3) << 1000, 0, src.cols / 2, 
                                                    0, 1000, src.rows / 2, 
                                                    0, 0, 1);
        Mat distCoeffs = Mat::zeros(5, 1, CV_64F); // 왜곡 계수 초기화
        
        vector<Vec3d> rvecs, tvecs; // 회전 벡터와 변환 벡터
        
        // 포즈 추정
        aruco::estimatePoseSingleMarkers(markerCorners, 0.05, cameraMatrix, distCoeffs, rvecs, tvecs);

        // 각 마커의 포즈를 그리기
        for (size_t i = 0; i < markerIds.size(); i++) {
            aruco::drawAxis(src, cameraMatrix, distCoeffs, rvecs[i], tvecs[i], 0.1); // 축 그리기
        }
        
        // 결과 이미지 출력
        imshow("Detected Markers", src);
    } else {
        cout << "마커가 감지되지 않았습니다." << endl; // 마커가 감지되지 않은 경우
    }

    waitKey(0); // 키 입력 대기
    return 0;
}
