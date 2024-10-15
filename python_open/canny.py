import cv2
import numpy as np

# 이미지 경로 설정
folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"
src = cv2.imread(folder + "img.bmp", cv2.IMREAD_GRAYSCALE)

if src is None:
    print("Error: Could not load image!")
    exit(-1)

# 첫 번째 Canny 엣지 검출
dst1 = cv2.Canny(src, 50, 150)  # 경계 검출 강도 조정

# 이미지에 Gaussian 블러를 적용한 후 Canny 엣지 검출
blurred = cv2.GaussianBlur(src, (5, 5), 1.5)  # 블러 적용
dst2 = cv2.Canny(blurred, 50, 150)  # 동일한 파라미터 사용

# 원본 이미지와 두 개의 Canny 이미지를 표시
cv2.imshow("Original Image", src)
cv2.imshow("Canny Image 1", dst1)
cv2.imshow("Canny Image 2 (Blurred)", dst2)

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()
