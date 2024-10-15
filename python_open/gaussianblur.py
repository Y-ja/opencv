import cv2

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"

# 첫 번째 이미지 읽기
src1 = cv2.imread(folder + "img7.bmp", cv2.IMREAD_GRAYSCALE)
if src1 is None:
    print("Error: Could not load image!")
    exit(-1)

# 블러 효과 적용 (가우시안 블러 사용)
kernel_size = 5  # 커널 크기 (홀수여야 함)
dst = cv2.GaussianBlur(src1, (kernel_size, kernel_size), 0)  # 시그마 X: 0은 자동 계산

# 원본 이미지와 블러 이미지 표시
cv2.namedWindow("Original Image", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Original Image", src1)

cv2.namedWindow("Blurred Image", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Blurred Image", dst)

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()
