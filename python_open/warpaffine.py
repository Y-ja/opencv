import cv2
import numpy as np

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"

# 첫 번째 이미지 읽기
src = cv2.imread(folder + "img10.bmp", cv2.IMREAD_GRAYSCALE)
if src is None:
    print("Error: Could not load image!")
    exit(-1)

# 소스 포인트 정의
src_pts = np.float32([
    [0, 0],
    [src.shape[1] - 1, 0],
    [src.shape[1] - 1, src.shape[0] - 1]
])

# 대상 포인트 정의
dst_pts = np.float32([
    [src.shape[1] / 2, 0],
    [src.shape[1] - 50, 0],
    [src.shape[1] - 1, src.shape[0] - 1]
])

# 아핀 변환 행렬 계산
M = cv2.getAffineTransform(src_pts, dst_pts)

# 아핀 변환 적용
dst = cv2.warpAffine(src, M, (src.shape[1], src.shape[0]))

# 회전 변환을 위한 중심점과 행렬 계산
center_point = (src.shape[1] / 2, src.shape[0] / 2)
M2 = cv2.getRotationMatrix2D(center_point, 30, 0.6)

# 첫 번째 변환된 이미지를 회전 변환 적용
dst_rotated = cv2.warpAffine(dst, M2, (src.shape[1], src.shape[0]))

# 원본 이미지와 변환된 이미지 표시
cv2.imshow("Original Image", src)
cv2.imshow("Warped Image", dst)
cv2.imshow("Warped and Rotated Image", dst_rotated)

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()
