import cv2
import numpy as np

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"

# 전역 변수로 src 선언
src = cv2.imread(folder + "img.bmp", cv2.IMREAD_GRAYSCALE)

if src is None:
    print("이미지를 열 수 없거나 찾을 수 없습니다!")
    exit(-1)

low_threshold = 50  # Canny 엣지 검출의 초기 임계값
max_low_threshold = 100  # 트랙바 최대 값
canny_ratio = 3  # 고정 비율
kernel_size = 3  # 소벨 커널 크기

# Canny 엣지 검출 및 Hough 선 검출 함수
def process_image(*args):
    global low_threshold
    edges = cv2.Canny(src, low_threshold, low_threshold * canny_ratio, kernel_size)  # 경계 검출

    # HoughLinesP로 선 검출
    lines = cv2.HoughLinesP(edges, 1, np.pi / 180, 100, minLineLength=50, maxLineGap=10)

    # 선을 그릴 이미지 생성
    line_image = np.zeros_like(src)

    # Hough 선 그리기
    if lines is not None:
        for detected_line in lines:
            x1, y1, x2, y2 = detected_line[0]
            cv2.line(line_image, (x1, y1), (x2, y2), (0, 0, 255), 2, cv2.LINE_AA)

    # 원본 이미지와 Hough 선이 그려진 이미지 표시
    cv2.imshow("Original Image", src)
    cv2.imshow("Canny Edges", edges)
    cv2.imshow("Hough Lines", line_image)

# 트랙바 생성
cv2.namedWindow("dst1")
cv2.createTrackbar("Canny Threshold", "dst1", low_threshold, max_low_threshold, process_image)

# 처음에 한 번 이미지 처리
process_image()

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()
