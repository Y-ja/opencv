import cv2
import numpy as np

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"

# 첫 번째 이미지 읽기 (컬러로)
src = cv2.imread(folder + "img2.bmp", cv2.IMREAD_COLOR)

if src is None:
    print("이미지를 열 수 없거나 찾을 수 없습니다!")
    exit(-1)

# 이미지 색 공간 변환 (BGR -> HSV)
hsv = cv2.cvtColor(src, cv2.COLOR_BGR2HSV)

# Hue 범위 설정
lower_hue = 40  # 하한
upper_hue = 80   # 상한

# Hue 범위에 해당하는 마스크 생성
dst = cv2.inRange(hsv, (lower_hue, 5, 0), (upper_hue, 255, 255))

# 원본 이미지와 필터링된 이미지를 표시
cv2.imshow("Original Image", src)
cv2.imshow("Filtered Image", dst)

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()
