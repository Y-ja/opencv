import cv2
import numpy as np

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"

# 첫 번째 이미지 읽기 (그레이스케일로)
src = cv2.imread(folder + "img2.bmp", cv2.IMREAD_GRAYSCALE)

if src is None:
    print("이미지를 열 수 없거나 찾을 수 없습니다!")
    exit(-1)

# Otsu의 이진화 적용
_, dst = cv2.threshold(src, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)

# 적응형 이진화 적용
dst2 = cv2.adaptiveThreshold(src, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 11, 2)

# 결과 이미지 표시
cv2.imshow("Original Image", src)
cv2.imshow("Binary Image (Otsu)", dst)
cv2.imshow("Adaptive Binary Image", dst2)

cv2.waitKey(0)
cv2.destroyAllWindows()
