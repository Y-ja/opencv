#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace cv::dnn;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

Net load_model() {
    String model_path = folder + "mnist_cnn.pb";
    Net net = readNet(model_path);
    if (net.empty()) {
        cerr << "신경망 모델을 로드할 수 없습니다. 경로: " << model_path << endl;
        exit(-1);
    }
    return net;
}

void on_mouse(int event, int x, int y, int flags, void *data);

int main() {
    Net net = load_model();

    Mat img = Mat::zeros(400, 400, CV_8U);
    namedWindow("img");
    setMouseCallback("img", on_mouse, (void *)&img);

    imshow("img", img);
    waitKey(0); // wait for a key press to continue

    // 이미지 크기를 28x28로 조정하고 blob 생성
    Mat img_resize;
    resize(img, img_resize, Size(28, 28), 0, 0, INTER_AREA);
    Mat blob = blobFromImage(img_resize, 1 / 255.f, Size(28, 28), Scalar(), true, false);

    net.setInput(blob);
    Mat prob = net.forward();

    double maxVal;
    Point maxLoc;
    minMaxLoc(prob, NULL, &maxVal, NULL, &maxLoc);
    int digit = maxLoc.x;

    cout << digit << " (" << maxVal * 100 << "%)" << endl;

    return 0;
}

void on_mouse(int event, int x, int y, int flags, void *data) {
    Mat img = *(Mat *)data;

    static bool flag = false;
    static Point ptPrev;
    if (event == EVENT_LBUTTONDOWN) {
        ptPrev = Point(x, y);
        flag = true;
    } else if (event == EVENT_LBUTTONUP) {
        ptPrev = Point(-1, -1);
        flag = false;
    } else if (event == EVENT_MOUSEMOVE && (flag)) {
        line(img, ptPrev, Point(x, y), Scalar(255, 255, 255), 20, LINE_AA, 0);
        ptPrev = Point(x, y);
        imshow("img", img);
    }
}
