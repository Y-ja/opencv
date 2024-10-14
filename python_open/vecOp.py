import cv2
import numpy as np

def main():
    # Vec3b와 Scalar 예시
    p1 = np.zeros(3, dtype=np.uint8)  # 3채널 BGR 벡터 초기화
    p2 = np.array([0, 0, 255], dtype=np.uint8)  # 빨간색

    p1[0] = 255  # 파란색 채널 설정

    print("p1 ->", p1)
    print("p2 ->", p2)

    gray = np.array([128], dtype=np.uint8)  # 회색
    print("gray ->", gray)

    # Airy Blue로 초기화된 Mat 객체 생성
    img1 = np.full((400, 400, 3), (240, 248, 255), dtype=np.uint8)  # 3채널 (BGR)
    img2 = np.full((400, 400), 200, dtype=np.uint8)                   # 1채널 (Gray)
    img3 = np.full((400, 400, 3), (240, 248, 255), dtype=np.uint8)  # 3채널 (BGR)
    img4 = np.full((400, 400), 200, dtype=np.uint8)                   # 1채널 (Gray)
    img5 = np.full((400, 400, 3), (240, 248, 255), dtype=np.uint8)  # 3채널 (BGR)

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
