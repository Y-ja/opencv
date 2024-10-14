import cv2

def main():
    img = cv2.imread("/home/test/Desktop/opencv/opencv/cppOpen/build/lena.bmp")
    if img is not None:
        cv2.imshow("image", img)
        cv2.waitKey(0)  # 키 입력을 기다립니다.
        cv2.destroyAllWindows()  # 모든 창을 닫습니다.
    else:
        print("이미지를 불러오지 못했습니다.")

if __name__ == "__main__":
    main()
