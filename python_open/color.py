import cv2
import numpy as np

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"

# 이미지 읽기
src = cv2.imread(folder + "img2.bmp", cv2.IMREAD_COLOR)

# (0, 0) 위치의 픽셀 값 출력
pixel = src[0, 0]
print(pixel[0], pixel[1], pixel[2])

# 첫 번째 이미지 표시
cv2.imshow("img1", src)

# 픽셀 값 변경
for i in range(100):
    for j in range(100):
        src[i, j] = [i, j, 0]  # BGR 순서로 픽셀 값 설정

# 두 번째 이미지 표시
cv2.imshow("img2", src)
cv2.waitKey(0)
cv2.destroyAllWindows()
