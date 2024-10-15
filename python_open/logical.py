import cv2

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"

# 첫 번째 이미지 읽기
src1 = cv2.imread(folder + "img256.bmp", cv2.IMREAD_GRAYSCALE)
# 두 번째 이미지 읽기
src2 = cv2.imread(folder + "square.bmp", cv2.IMREAD_GRAYSCALE)

# 이미지가 제대로 열렸는지 확인
if src1 is None or src2 is None:
    print("Error: Could not load images!")
    exit(-1)

# 두 이미지가 동일한 크기인지 확인
if src1.shape != src2.shape:
    print("Error: The two images must be of the same size!")
    exit(-1)

# 논리 AND 처리
dst = cv2.bitwise_and(src1, src2)

# 결과 이미지 표시
cv2.namedWindow("Image 1", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Image 1", src1)

cv2.namedWindow("Image 2", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Image 2", src2)

cv2.namedWindow("Logical AND Result", cv2.WINDOW_AUTOSIZE)
cv2.imshow("Logical AND Result", dst)

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()
