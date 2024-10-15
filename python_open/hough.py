import cv2
import numpy as np

# 이미지 경로 설정
folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"
src = cv2.imread(folder + "img.bmp", cv2.IMREAD_GRAYSCALE)

if src is None:
    print("Error: Could not load image!")
    exit(-1)

# Hough 변환을 위한 이진 이미지 생성
_, binary = cv2.threshold(src, 128, 255, cv2.THRESH_BINARY)

# Hough 변환으로 선 검출
lines = cv2.HoughLines(binary, 1, np.pi / 180, 100)

# 선을 그릴 이미지 생성
line_image = np.zeros((src.shape[0], src.shape[1], 3), dtype=np.uint8)

# Hough 선 그리기
if lines is not None:
    for line in lines:
        rho, theta = line[0]  # rho와 theta 추출
        a = np.cos(theta)
        b = np.sin(theta)
        x0 = a * rho
        y0 = b * rho
        pt1 = (int(x0 + 1000 * (-b)), int(y0 + 1000 * (a)))
        pt2 = (int(x0 - 1000 * (-b)), int(y0 - 1000 * (a)))
        cv2.line(line_image, pt1, pt2, (0, 0, 255), 1, cv2.LINE_AA)  # 선 그리기

# 결과 표시
cv2.imshow("Original Image", src)
cv2.imshow("Hough Lines", line_image)

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()
