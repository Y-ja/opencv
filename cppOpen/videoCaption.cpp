#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() 
{
    // GStreamer 파이프라인 생성
    std::string pipeline = "v4l2src device=/dev/video0 ! video/x-raw, width=1280, height=720, framerate=30/1 ! videoconvert ! appsink";
    VideoCapture cap(pipeline, cv::CAP_GSTREAMER);  // GStreamer를 사용하여 비디오 캡처 열기
    Mat frame;

    if (!cap.isOpened()) {
        cerr << "Video open failed.\n";
        return -1;
    }

    int delay = 30;  // 프레임 지연 시간을 30ms로 설정

    while (true) {
        cap >> frame;  // GStreamer에서 프레임 읽기

        if (frame.empty()) {
            cerr << "Failed to grab frame.\n";
            break;  // 프레임이 비어있으면 루프 종료
        }

        imshow("frame", frame);  // 프레임 표시

        if (waitKey(delay) == 27) {  // ESC 키를 누르면 종료
            break;
        }
    }

    destroyAllWindows();  // 모든 창 닫기
    cap.release();  // 카메라 리소스 해제

    return 0;
}
