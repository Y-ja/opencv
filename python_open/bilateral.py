import cv2
import numpy as np

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"

# 첫 번째 이미지 읽기
src = cv2.imread(folder + "img2.bmp", cv2.IMREAD_GRAYSCALE)
if src is None:
    print("Error: Could not load image!")
    exit(-1)

# 노이즈 추가
noise = np.random.normal(0, 10, src.shape).astype(np.float32)  # 평균 0, 표준편차 10의 가우시안 노이즈 생성
noisy_image = cv2.convertScaleAbs(src.astype(np.float32) + noise)  # 노이즈 추가 및 타입 변환

# Gaussian 블러 적용
sigma = 3
dst1 = cv2.GaussianBlur(noisy_image, (0, 0), sigma)

# Bilateral 필터 적용
dst2 = cv2.bilateralFilter(noisy_image, d=-1, sigmaColor=10, sigmaSpace=5)

# 원본 이미지, 노이즈 이미지, Gaussian 블러 이미지, Bilateral 필터 이미지 표시
cv2.namedWindow("Original Image", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Original Image", src)

cv2.namedWindow("Noisy Image", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Noisy Image", noisy_image)

cv2.namedWindow("Gaussian Blurred Image", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Gaussian Blurred Image", dst1)

cv2.namedWindow("Bilateral Filtered Image", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Bilateral Filtered Image", dst2)

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()
