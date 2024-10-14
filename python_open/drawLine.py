import cv2
import numpy as np

def main():
    img = np.ones((400, 640, 3), dtype=np.uint8) * 255  # 흰색 배경 초기화
    a = 0

    while True:
        img[:] = (255, 255, 255)  # 배경을 흰색으로 초기화
        cv2.line(img, (50, 100 + a), (500, 100 + a), (55, a // 2 + 50, a // 2), 3)  # 선 그리기
        a += 1
        
        if a > 400:
            a = 0
            
        cv2.imshow("img", img)  # 이미지 표시
        
        if cv2.waitKey(10) == 32:  # 스페이스 키로 종료
            break

    cv2.destroyAllWindows()  # 모든 창 닫기

if __name__ == "__main__":
    main()
