import cv2
import numpy as np

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"

def draw_histogram(src):
    # 히스토그램 계산
    hist_size = 256
    hist_range = [0, 256]
    histogram = cv2.calcHist([src], [0], None, [hist_size], hist_range)

    # 히스토그램 이미지 초기화
    hist_image = np.zeros((300, 512, 3), dtype=np.uint8)

    # 히스토그램 그리기
    for i in range(1, hist_size):
        cv2.line(hist_image, (2 * (i - 1), 300 - int(histogram[i - 1])),
                 (2 * i, 300 - int(histogram[i])),
                 (255, 0, 0), 2, 8, 0)
    return hist_image

# 이미지 읽기
src = cv2.imread(folder + "img2.bmp", cv2.IMREAD_GRAYSCALE)
if src is None:
    print("Error: Could not load image!")
    exit(-1)

# 히스토그램 평활화
dst = cv2.equalizeHist(src)

# 원본 이미지와 평활화된 이미지 표시
cv2.namedWindow("Original Image", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Original Image", src)

cv2.namedWindow("Equalized Image", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Equalized Image", dst)

# 히스토그램 이미지 생성
hist_image_src = draw_histogram(src)
hist_image_dst = draw_histogram(dst)

# 히스토그램 표시
cv2.namedWindow("Histogram - Original", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Histogram - Original", hist_image_src)

cv2.namedWindow("Histogram - Equalized", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Histogram - Equalized", hist_image_dst)

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()
