import cv2
import numpy as np

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"
src = cv2.imread(folder + "img2.bmp", cv2.IMREAD_GRAYSCALE)

if src is None:
    print("이미지를 열 수 없거나 찾을 수 없습니다!")
    exit(-1)

# 원본 이미지를 복사하여 표시용 이미지 초기화
display = src.copy()

def on_mouse(event, x, y, flags, param):
    global display

    if event == cv2.EVENT_MOUSEMOVE:
        # 새로운 이미지를 복사하여 표시
        display = src.copy()

        # 사각형 그리기
        cv2.rectangle(display, (x - 20, y - 20), (x + 20, y + 20), (255, 0, 0), 2)

        # 이미지를 업데이트하여 표시
        cv2.imshow("img", display)

# 창을 만들고 마우스 콜백을 설정
cv2.namedWindow("img")
cv2.setMouseCallback("img", on_mouse)

# 이미지 표시
cv2.imshow("img", display)
cv2.waitKey(0)  # 키 입력을 기다립니다.
cv2.destroyAllWindows()
