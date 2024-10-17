import cv2
import numpy as np

# 이미지 경로 설정
folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"

def load_model():
    model_path = folder + "mnist_cnn.pb"
    net = cv2.dnn.readNet(model_path)
    if net.empty():
        raise Exception(f"신경망 모델을 로드할 수 없습니다. 경로: {model_path}")
    return net

def on_mouse(event, x, y, flags, param):
    img = param['img']

    if event == cv2.EVENT_LBUTTONDOWN:
        param['drawing'] = True
        param['pt_prev'] = (x, y)
    elif event == cv2.EVENT_LBUTTONUP:
        param['drawing'] = False
        param['pt_prev'] = (-1, -1)
    elif event == cv2.EVENT_MOUSEMOVE and param['drawing']:
        cv2.line(img, param['pt_prev'], (x, y), (255, 255, 255), 20, cv2.LINE_AA)
        param['pt_prev'] = (x, y)
        cv2.imshow("img", img)

def main():
    net = load_model()

    img = np.zeros((400, 400), dtype=np.uint8)
    cv2.namedWindow("img")

    param = {
        'img': img,
        'drawing': False,
        'pt_prev': (0, 0)
    }
    cv2.setMouseCallback("img", on_mouse, param)

    cv2.imshow("img", img)
    cv2.waitKey(0)  # wait for a key press to continue

    # 이미지 크기를 28x28로 조정하고 blob 생성
    img_resize = cv2.resize(img, (28, 28))
    blob = cv2.dnn.blobFromImage(img_resize, 1 / 255.0, (28, 28), (0, 0, 0), True, False)

    net.setInput(blob)
    prob = net.forward()

    # 최대 확률 및 해당 클래스 계산
    maxVal = np.max(prob)
    digit = np.argmax(prob)

    print(f"{digit} ({maxVal * 100:.2f}%)")

if __name__ == "__main__":
    main()
