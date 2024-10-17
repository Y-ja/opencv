#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace cv::ml;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";

Ptr<KNearest> train_knn();
void on_mouse(int event, int x, int y, int flags, void *data);

int main() {
    Ptr<KNearest> knn = train_knn();
    if (!knn) {
        cerr << "KNN 모델 훈련에 실패했습니다." << endl;
        return -1; // KNN 모델이 훈련되지 않으면 종료
    }

    Mat img = Mat::zeros(400, 400, CV_8U);
    namedWindow("img");
    setMouseCallback("img", on_mouse, (void *)&img);

    imshow("img", img);
    waitKey();

    Mat img_resize, img_float, img_flatten, res;
    resize(img, img_resize, Size(20, 20), 0, 0, INTER_AREA);
    img_resize.convertTo(img_float, CV_32F);
    img_flatten = img_float.reshape(1, 1);

    knn->findNearest(img_flatten, 3, res);
    cout << cvRound(res.at<float>(0, 0)) << endl;

    return 0;
}

Ptr<KNearest> train_knn() {
    Mat digits = imread(folder + "digits.png", IMREAD_GRAYSCALE);
    if (digits.empty()) {
        cerr << "이미지를 열 수 없습니다. 경로를 확인하세요: " << folder + "digits.png" << endl;
        return nullptr; // 이미지가 열리지 않으면 nullptr 반환
    }

    Mat train_images(5000, 400, CV_32F);
    Mat train_labels(5000, 1, CV_32S);
    int idx = 0;
    for (int j = 0; j < 50; j++) {
        for (int i = 0; i < 100; i++) {
            if (i * 20 + 20 <= digits.cols && j * 20 + 20 <= digits.rows) {
                Mat roi = digits(Rect(i * 20, j * 20, 20, 20));
                Mat roi_float, roi_flatten;
                roi.convertTo(roi_float, CV_32F);
                roi_flatten = roi_float.reshape(1, 1);

                roi_flatten.copyTo(train_images.row(idx));
                train_labels.at<int>(idx, 0) = j / 5;
                idx++;
            }
        }
    }

    if (idx == 0) {
        cerr << "훈련 데이터가 없습니다. 이미지에서 유효한 ROI를 찾을 수 없습니다." << endl;
        return nullptr; // 유효한 훈련 데이터가 없으면 nullptr 반환
    }

    Ptr<KNearest> knn = KNearest::create();
    knn->train(train_images.rowRange(0, idx), ROW_SAMPLE, train_labels.rowRange(0, idx)); // 유효한 데이터만 사용
    return knn;
}

void on_mouse(int event, int x, int y, int flags, void *data) {
    Mat img = *(Mat *)data;

    static bool flag = false;
    static Point ptPrev;
    if (event == EVENT_LBUTTONDOWN) {
        ptPrev = Point(x, y);
        flag = true;
    }
    else if (event == EVENT_LBUTTONUP) {
        ptPrev = Point(-1, -1);
        flag = false;
    }
    else if (event == EVENT_MOUSEMOVE && (flag)) {
        line(img, ptPrev, Point(x, y), Scalar(255, 255, 255), 20, LINE_AA, 0);
        ptPrev = Point(x, y);
        imshow("img", img);
    }
}
