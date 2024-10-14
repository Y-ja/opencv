import cv2
import numpy as np

def main():
    # 3채널 이미지로 초기화 (어두운 빨간색)
    img1 = np.full((400, 640, 3), (10, 0, 0), dtype=np.uint8)
    # 단일 채널 이미지로 초기화 (검정색)
    img2 = np.full((400, 640), 0, dtype=np.uint8)
    # 3채널 이미지로 초기화 (파란색)
    img3 = np.full((400, 640, 3), (255, 0, 0), dtype=np.uint8)
    # 3채널 이미지로 초기화 (초록색)
    img4 = np.full((400, 640, 3), (0, 255, 0), dtype=np.uint8)
    # 단일 채널 이미지로 초기화 (검정색)
    img5 = np.full((400, 640), 0, dtype=np.uint8)
    # 단일 채널 이미지로 초기화 (흰색)
    img6 = np.full((400, 640), 255, dtype=np.uint8)

    # 각 이미지를 출력
    cv2.imshow("img1", img1)
    cv2.imshow("img2", img2)
    cv2.imshow("img3", img3)
    cv2.imshow("img4", img4)
    cv2.imshow("img5", img5)
    cv2.imshow("img6", img6)

    cv2.waitKey(0)  # 키 입력을 기다림
    cv2.destroyAllWindows()  # 모든 창 닫기

if __name__ == "__main__":
    main()
