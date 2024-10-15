import cv2

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"

# 첫 번째 이미지 읽기
src1 = cv2.imread(folder + "img2.bmp", cv2.IMREAD_GRAYSCALE)
if src1 is None:
    print("Error: Could not load image!")
    exit(-1)

# 블러 효과 적용 (가우시안 블러 사용)
dst = cv2.GaussianBlur(src1, (5, 5), 0)  # 커널 크기: 5x5

# 원본 이미지와 블러 이미지 표시
cv2.namedWindow("Original Image", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Original Image", src1)

cv2.namedWindow("Blurred Image", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Blurred Image", dst)

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()
