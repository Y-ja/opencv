import cv2
import numpy as np

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"

# 첫 번째 이미지 읽기
src1 = cv2.imread(folder + "img7.bmp", cv2.IMREAD_GRAYSCALE)
if src1 is None:
    print("Error: Could not load image!")
    exit(-1)

# 엠보스 필터 정의
emboss_kernel = np.array([[-1, -1, 0],
                           [-1, 0, 1],
                           [0, 1, 1]], dtype=np.float32)

# 엠보스 효과 적용
dst = cv2.filter2D(src1, cv2.CV_8U, emboss_kernel)

# 원본 이미지와 엠보스 이미지 표시
cv2.namedWindow("Original Image", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Original Image", src1)

cv2.namedWindow("Embossed Image", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Embossed Image", dst)

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()
