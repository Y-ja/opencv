import cv2
import numpy as np

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"
src = cv2.imread(folder + "img9.bmp", cv2.IMREAD_COLOR)

if src is None:
    print("Error: Could not load image!")
    exit(-1)

# 전역 변수
src_pts = []
dst_pts = np.float32([[0, 0], [199, 0], [199, 299], [0, 299]])
cnt = 0  # 점의 개수 카운트

def on_mouse(event, x, y, flags, param):
    global cnt
    if event == cv2.EVENT_LBUTTONDOWN:
        if cnt < 4:  # 최대 4개의 점을 선택
            src_pts.append((x, y))
            cnt += 1
            print(f"Point added: ({x}, {y})")
            cv2.circle(src, (x, y), 10, (255, 0, 0), -1)  # 선택한 점을 원으로 표시
            cv2.imshow("src", src)  # 업데이트된 이미지 보여주기

            if cnt == 4:
                # 원근 변환 행렬 계산
                M = cv2.getPerspectiveTransform(np.float32(src_pts), dst_pts)
                dst = cv2.warpPerspective(src, M, (200, 300))  # 원근 변환 적용
                cv2.imshow("dst", dst)
                cnt = 0  # 점 선택 카운터 초기화

# 윈도우 및 콜백 함수 설정
cv2.namedWindow("src")
cv2.setMouseCallback("src", on_mouse)

cv2.imshow("src", src)
cv2.waitKey(0)
cv2.destroyAllWindows()
