import cv2
import numpy as np

def main():
    path = "/home/test/Desktop/opencv/opencv/cppOpen/build/wolf.bmp"  # 이미지 경로
    img1 = cv2.imread(path)  # 이미지 로드

    # 이미지가 성공적으로 로드되었는지 확인
    if img1 is None:
        print(f"이미지를 로드할 수 없습니다: {path}")
        return -1

    img2 = img1  # img1의 참조를 img2에 할당
    img3 = img1  # img1을 img3에 할당

    img4 = img1.copy()  # img1을 깊은 복사하여 img4에 할당
    img5 = img1.copy()  # img1을 img5에 복사

    img1[:, :] = (0, 255, 255)  # img1의 색상을 변경 (노란색)

    # 각 이미지를 출력
    cv2.imshow("img1", img1)
    cv2.imshow("img2", img2)
    cv2.imshow("img3", img3)
    cv2.imshow("img4", img4)
    cv2.imshow("img5", img5)

    cv2.waitKey(0)  # 키 입력을 기다림
    cv2.destroyAllWindows()  # 모든 창 닫기

if __name__ == "__main__":
    main()
