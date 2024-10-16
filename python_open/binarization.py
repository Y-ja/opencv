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

# 형태학적 변환을 위한 커널 생성
kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (5, 5))

# Morphological Open 및 Close
morphOpen = cv2.morphologyEx(dst, cv2.MORPH_OPEN, kernel)
morphClose = cv2.morphologyEx(dst2, cv2.MORPH_CLOSE, kernel)

# 결과 이미지 표시
cv2.imshow("Original Image", src)
cv2.imshow("Otsu Image", dst)
cv2.imshow("Adaptive Image", dst2)
cv2.imshow("Morphological Open", morphOpen)
cv2.imshow("Morphological Close", morphClose)

cv2.waitKey(0)
cv2.destroyAllWindows()
