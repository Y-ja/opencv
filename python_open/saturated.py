import cv2
import numpy as np

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"
# 컬러 이미지 읽기
src = cv2.imread(folder + "img2.bmp", cv2.IMREAD_COLOR)
if src is None:
    print("Error: Could not load image!")
    exit(-1)

# 원본 이미지 복사
bright_src = src.copy()
saturate_src = src.copy()  # 컬러 이미지로 변환할 필요 없음
contrast_src = src.copy()
blurred_src = src.copy()
edge_detected_src = src.copy()

# 밝기 조정
brightness_value = 50  # 밝기 증가 값
bright_src = cv2.add(bright_src, brightness_value)  # 밝기 증가

# 포화도 조정
saturation_value = 1.5  # 포화도 비율 (1.0은 변화 없음)
hsv_image = cv2.cvtColor(saturate_src, cv2.COLOR_BGR2HSV)  # BGR에서 HSV로 변환
h, s, v = cv2.split(hsv_image)  # HSV 채널 분리
s = np.clip(s * saturation_value, 0, 255).astype(np.uint8)  # 포화도 조정
saturate_src = cv2.merge((h, s, v))  # 채널 병합
saturate_src = cv2.cvtColor(saturate_src, cv2.COLOR_HSV2BGR)  # HSV에서 BGR로 변환

# 대비 조정
alpha = 1.5  # 대비 증가 값
beta = 0  # 밝기 변화 값
contrast_src = cv2.convertScaleAbs(contrast_src, alpha=alpha, beta=beta)  # 대비 조정

# 흐림 효과 (Gaussian Blur)
blurred_src = cv2.GaussianBlur(src, (15, 15), 0)  # 흐림 효과

# 엣지 검출 (Canny)
edge_detected_src = cv2.Canny(src, 100, 200)  # 엣지 검출

# 결과 이미지 보여주기
cv2.imshow("Original", src)
cv2.imshow("Brightened", bright_src)
cv2.imshow("Saturated", saturate_src)
cv2.imshow("Contrast Adjusted", contrast_src)
cv2.imshow("Blurred", blurred_src)
cv2.imshow("Edge Detected", edge_detected_src)

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()
