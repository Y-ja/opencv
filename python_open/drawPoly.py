import cv2
import numpy as np

def main():
    # 흰색 배경의 이미지 초기화
    img = np.ones((400, 640, 3), dtype=np.uint8) * 255

    while True:
        # 배경을 흰색으로 초기화
        img[:] = (255, 255, 255)

        # 사각형 그리기 (채워진 사각형)
        cv2.rectangle(img, (50, 100), (150, 200), (0, 255, 0), -1)  # 초록색

        # 원 그리기 (채워진 원)
        cv2.circle(img, (300, 150), 50, (255, 0, 0), -1)  # 파란색

        # 타원 그리기 (채워진 타원)
        cv2.ellipse(img, (450, 150), (60, 30), 0, 0, 360, (0, 0, 255), -1)  # 빨간색

        # 타원의 외곽선 그리기
        cv2.ellipse(img, (450, 150), (60, 30), 0, 0, 360, (0, 0, 0), 2)  # 검은색 외곽선

        # 이미지 표시
        cv2.imshow("Shapes", img)

        # 스페이스 키를 누르면 종료
        if cv2.waitKey(30) == 32:  # 32는 스페이스 키의 ASCII 코드
            break

    cv2.destroyAllWindows()  # 모든 창 닫기

if __name__ == "__main__":
    main()
