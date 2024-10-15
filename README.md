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
- 드론 비전 🦅: 드론의 자동 비행 및 장애물 회피에 활용됩니다.
- 산업 자동화 🏭: 제품 검사 및 품질 관리에 사용됩니다.

## OpenCV 주요 함수 목록

## 기본 함수

## 📸 이미지 읽기
- imread(filename): 주어진 파일 이름의 이미지를 읽어 Mat 객체로 반환합니다.

```
import cv2

image = cv2.imread('image.jpg')

```
## 🖼️ 이미지 표시
- imshow(window_name, image): 지정된 창에 이미지를 표시합니다.
```
cv2.imshow('Image', image)
cv2.waitKey(0)
cv2.destroyAllWindows()

```

## ⏳ 키 입력 대기
- waitKey(delay): 지정된 밀리초(ms) 동안 키 입력을 대기하며, 입력된 키의 ASCII 값을 반환합니다. 0을 주면 무한 대기합니다.

```
key = cv2.waitKey(0)

```

## ❌ 모든 창 닫기

- destroyAllWindows(): 모든 OpenCV 창을 닫습니다.
```
cv2.destroyAllWindows()

```

## 📹 기본 카메라 열기

- VideoCapture(index): 비디오 파일이나 카메라에서 비디오 스트림을 캡처하는 클래스입니다.
```
cap = cv2.VideoCapture(0)

```

## 🎥 비디오 파일 생성
- VideoWriter(filename, fourcc, fps, frameSize): 비디오 파일을 생성하는 클래스입니다.

```
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('output.avi', fourcc, 20.0, (640, 480))
```

## draw 함수

## 🔵 파란색 선
- line(image, pt1, pt2, color, thickness): 두 점 사이에 선을 그립니다.

```
cv2.line(image, (50, 50), (200, 50), (255, 0, 0), 2)

```

## 🟩 초록색 사각형
- rectangle(image, pt1, pt2, color, thickness): 사각형을 그립니다.
```
cv2.rectangle(image, (50, 50), (200, 150), (0, 255, 0), 3)

```

## 🔴 빨간색 원
- circle(image, center, radius, color, thickness): 원을 그립니다.
```
cv2.circle(image, (150, 100), 50, (0, 0, 255), -1)

```

## 🟡 노란색 타원
- ellipse(image, center, axes, angle, startAngle, endAngle, color, thickness): 타원을 그립니다.
```
cv2.ellipse(image, (150, 100), (100, 50), 0, 0, 180, (255, 255, 0), 2)

```

## ⚪ 흰색 텍스트
- putText(image, text, org, fontFace, fontScale, color, thickness): 이미지를 표시할 텍스트를 그립니다.
```
cv2.putText(image, 'Hello, OpenCV!', (50, 250), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)

```

## waitKeyEx 함수
## ⏳ 키 입력 대기
- waitKeyEx(delay): 키 입력을 대기하며, 더 많은 기능을 제공합니다.
```
key = cv2.waitKeyEx(0)

```

OpenCV 주요 함수 목록
기본 함수

    imread(filename): 주어진 파일 이름의 이미지를 읽어 Mat 객체로 반환합니다.
    예시: 📸 이미지 읽기

    python

import cv2

image = cv2.imread('image.jpg')

imshow(window_name, image): 지정된 창에 이미지를 표시합니다.
예시: 🖼️ 이미지 표시

python

cv2.imshow('Image', image)
cv2.waitKey(0)
cv2.destroyAllWindows()

waitKey(delay): 지정된 밀리초(ms) 동안 키 입력을 대기하며, 입력된 키의 ASCII 값을 반환합니다. 0을 주면 무한 대기합니다.
예시: ⏳ 키 입력 대기

python

key = cv2.waitKey(0)

destroyAllWindows(): 모든 OpenCV 창을 닫습니다.
예시: ❌ 모든 창 닫기

python

cv2.destroyAllWindows()

VideoCapture(index): 비디오 파일이나 카메라에서 비디오 스트림을 캡처하는 클래스입니다.
예시: 📹 기본 카메라 열기

python

cap = cv2.VideoCapture(0)

VideoWriter(filename, fourcc, fps, frameSize): 비디오 파일을 생성하는 클래스입니다.
예시: 🎥 비디오 파일 생성

python

    fourcc = cv2.VideoWriter_fourcc(*'XVID')
    out = cv2.VideoWriter('output.avi', fourcc, 20.0, (640, 480))

draw 함수

    line(image, pt1, pt2, color, thickness): 두 점 사이에 선을 그립니다.
    예시: 🔵 파란색 선

    python

cv2.line(image, (50, 50), (200, 50), (255, 0, 0), 2)

rectangle(image, pt1, pt2, color, thickness): 사각형을 그립니다.
예시: 🟩 초록색 사각형

python

cv2.rectangle(image, (50, 50), (200, 150), (0, 255, 0), 3)

circle(image, center, radius, color, thickness): 원을 그립니다.
예시: 🔴 빨간색 원

python

cv2.circle(image, (150, 100), 50, (0, 0, 255), -1)

ellipse(image, center, axes, angle, startAngle, endAngle, color, thickness): 타원을 그립니다.
예시: 🟡 노란색 타원

python

cv2.ellipse(image, (150, 100), (100, 50), 0, 0, 180, (255, 255, 0), 2)

putText(image, text, org, fontFace, fontScale, color, thickness): 이미지를 표시할 텍스트를 그립니다.
예시: ⚪ 흰색 텍스트

python

    cv2.putText(image, 'Hello, OpenCV!', (50, 250), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)

waitKeyEx 함수

    waitKeyEx(delay): 키 입력을 대기하며, 더 많은 기능을 제공합니다.
    예시: ⏳ 키 입력 대기

    python

    key = cv2.waitKeyEx(0)

## 마우스 콜백 함수

## 🖱️ 클릭한 위치 출력
- 콜백 함수: 마우스 이벤트를 처리하는 사용자 정의 함수로, 마우스 클릭이나 이동 시 특정 동작을 수행합니다.

```
def mouse_callback(event, x, y, flags, param):
    if event == cv2.EVENT_LBUTTONDOWN:
        print(f"Mouse clicked at ({x}, {y})")

cv2.setMouseCallback('Image', mouse_callback)

```

## 대비 함수

## 📊 히스토그램 계산
- 히스토그램: 이미지의 밝기 분포를 나타냅니다.

```
hist = cv2.calcHist([image], [0], None, [256], [0, 256])

```
## ✨ 히스토그램 평활화
히스토그램 평활화: 이미지의 대비를 향상시킵니다.

```
equalized_image = cv2.equalizeHist(image)

```
## 📈 대비 증가
스트레칭: 이미지의 명암을 조절하여 대비를 증가시킵니다.

```
stretched = cv2.normalize(image, None, 0, 255, cv2.NORM_MINMAX)

```
