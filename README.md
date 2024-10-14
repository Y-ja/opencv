# OpenCV
- OpenCV (Open Source Computer Vision Library)는 실시간 컴퓨터 비전 및 기계 학습을 위한 강력한 라이브러리로, 다양한 이미지 및 비디오 처리 작업을 지원합니다. 이 라이브러리는 이미지 처리, 객체 인식, 비디오 분석, 기계 학습 알고리즘 등 다양한 기능을 제공하여 다양한 응용 프로그램에서 활용됩니다.
주요 기능

- 이미지 처리 🖼️: 필터링, 변환, 색상 공간 변환 등 다양한 이미지 처리 기능을 제공합니다.
- 객체 인식 🔍: 얼굴 인식, 자동차 인식 등 다양한 객체 인식 알고리즘을 지원합니다.
- 비디오 캡처 및 분석 🎥: 웹캠 또는 비디오 파일에서 실시간으로 영상을 캡처하고 분석할 수 있습니다.
- 기계 학습 알고리즘 지원 🤖: 다양한 머신 러닝 모델과 알고리즘을 사용할 수 있습니다.
- 여러 플랫폼에서 사용 가능 💻: Windows, Linux, macOS에서 모두 사용할 수 있어, 유연성과 호환성이 뛰어납니다.

## 설치 방법
### Python 🐍

- OpenCV를 Python에서 사용하려면 opencv-python 패키지를 설치하면 됩니다.
```
pip install opencv-python

```

### 기본 사용 예시 (Python)

```
import cv2

# 이미지 불러오기
image = cv2.imread('image.jpg')

# 이미지 표시
cv2.imshow('Image', image)
cv2.waitKey(0)
cv2.destroyAllWindows()

```

## C++ 🚀
- C++에서 OpenCV를 사용하려면 libopencv-dev 패키지를 설치해야 합니다. 

```
sudo apt-get install libopencv-dev

```

### 기본 사용 예시 (C++)
```
#include <opencv2/opencv.hpp>

int main() {
    // 이미지 불러오기
    cv::Mat image = cv::imread("image.jpg");

    // 이미지 표시
    cv::imshow("Image", image);
    cv::waitKey(0);
    return 0;
}

```

## OpenCV의 사용 사례

- 안면 인식 🛡️: 보안 시스템이나 스마트폰 잠금 해제에 사용됩니다.
- 자율주행차 🚗: 주변 객체 인식 및 경로 계획에 활용됩니다.
- 의료 이미지 분석 🏥: X-ray, MRI 이미지 분석에 사용됩니다.
- 스포츠 분석 ⚽: 선수의 움직임 추적 및 분석에 활용됩니다.
- 증강 현실 🌐: 실제 환경에 가상의 정보를 추가하는 데 사용됩니다.