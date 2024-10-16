import cv2
import numpy as np

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"

# 첫 번째 이미지 읽기 (컬러로)
src = cv2.imread(folder + "img2.bmp", cv2.IMREAD_COLOR)

if src is None:
    print("이미지를 열 수 없거나 찾을 수 없습니다!")
    exit(-1)

# BGR 채널 분리
bgr = cv2.split(src)

# 빈 채널 생성
empty = np.zeros(src.shape[:2], dtype=np.uint8)

# 각 채널만 포함된 이미지 생성
bsrc = cv2.merge([bgr[0], empty, empty])  # Blue Channel
gsrc = cv2.merge([empty, bgr[1], empty])  # Green Channel
rsrc = cv2.merge([empty, empty, bgr[2]])  # Red Channel

# 채널 이름
channel_names = ["Blue Channel", "Green Channel", "Red Channel"]

# 각각의 채널 이미지를 표시
cv2.imshow(channel_names[0], bgr[0])  # B 채널
cv2.imshow(channel_names[1], bgr[1])  # G 채널
cv2.imshow(channel_names[2], bgr[2])  # R 채널

# 각 채널만 포함된 이미지 표시
cv2.imshow("Blue Channel Only", bsrc)
cv2.imshow("Green Channel Only", gsrc)
cv2.imshow("Red Channel Only", rsrc)

# 원본 이미지를 표시
cv2.imshow("Original Image", src)

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()
