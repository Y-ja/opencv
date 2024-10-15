#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/";
void onMouse(int event, int x, int y, int flags, void *data);

Mat src;
Point2f srcPts[4], dstPts[4];
int cnt = 0; // 전역으로 cnt를 관리

int main()
{
    src = imread(folder + "img9.bmp", IMREAD_COLOR);
    if (src.empty()) {
        cout << "이미지를 열 수 없거나 찾을 수 없습니다!" << endl;
        return -1;
    }

    namedWindow("src");
    setMouseCallback("src", onMouse);
    imshow("src", src);
    waitKey();
    return 0;
}

void onMouse(int event, int x, int y, int flags, void *data)
{
    switch (event)
    {
    case EVENT_LBUTTONDOWN:
        if (cnt < 4) { // cnt가 4보다 작은 경우에만
            srcPts[cnt++] = Point2f(x, y);
            cout << "Point added: (" << x << ", " << y << ")" << endl;
            circle(src, Point(x, y), 10, Scalar(255, 0, 0), -1);
            imshow("src", src); // 원본 이미지를 업데이트

            if (cnt == 4)
            {
                dstPts[0] = Point2f(0, 0);
                dstPts[1] = Point2f(199, 0);
                dstPts[2] = Point2f(199, 299);
                dstPts[3] = Point2f(0, 299);

                Mat M = getPerspectiveTransform(srcPts, dstPts);
                Mat dst;
                warpPerspective(src, dst, M, Size(200, 300));
                imshow("dst", dst);
                cnt = 0; // 점 추가 카운터 초기화
            }
        } else {
            cout << "4개의 점이 이미 선택되었습니다." << endl;
        }
        break;
    }
}
