import cv2
import numpy as np
import freetype

def main():
    green = (0, 255, 0)
    red = (0, 0, 255)
    img = np.ones((400, 640, 3), dtype=np.uint8) * 255  # 흰색 배경 초기화

    text = "안녕 오픈CV!"
    font_path = "/home/test/Desktop/opencv/opencv/cppOpen/build/ProtestStrike-Regular.ttf"
    face = freetype.Face(font_path)
    face.set_char_size(50 * 64)

    a = 0
    while True:
        img[:] = (255, 255, 255)  # 배경을 흰색으로 초기화
        cv2.putText(img, "Hello, OpenCV nice to meet you!", (50 + a, 100), cv2.FONT_HERSHEY_PLAIN, 3, green, lineType=cv2.LINE_AA)

        # FreeType으로 텍스트 그리기
        x, y = 50 + a, 200
        for char in text:
            face.load_char(char)
            bitmap = face.glyph.bitmap
            img[y:y + bitmap.rows, x:x + bitmap.width] = np.array(bitmap.buffer).reshape(bitmap.rows, bitmap.width)[:, :, np.newaxis] * red[2]
            x += bitmap.width  # 다음 문자 위치로 이동

        a += 1
        if a > 400:
            a = 0
        
        cv2.imshow("img", img)  # 이미지 표시
        if cv2.waitKey(10) == 32:  # 스페이스로 종료
            break

    cv2.destroyAllWindows()  # 모든 창 닫기

if __name__ == "__main__":
    main()
