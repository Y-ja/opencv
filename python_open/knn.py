import cv2
import numpy as np

# 이미지 경로 설정
folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"

def train_knn():
    digits = cv2.imread(folder + "digits.png", cv2.IMREAD_GRAYSCALE)
    if digits is None:
        print("이미지를 열 수 없습니다. 경로를 확인하세요:", folder + "digits.png")
        return None

    train_images = np.zeros((5000, 400), dtype=np.float32)
    train_labels = np.zeros((5000, 1), dtype=np.int32)
    idx = 0

    for j in range(50):
        for i in range(100):
            if i * 20 + 20 <= digits.shape[1] and j * 20 + 20 <= digits.shape[0]:
                roi = digits[j * 20:j * 20 + 20, i * 20:i * 20 + 20]
                roi_float = roi.astype(np.float32).flatten()

                train_images[idx] = roi_float
                train_labels[idx] = j // 5
                idx += 1

    if idx == 0:
        print("훈련 데이터가 없습니다. 이미지에서 유효한 ROI를 찾을 수 없습니다.")
        return None

    # KNN 모델 훈련
    knn = cv2.ml.KNearest_create()
    knn.train(train_images[:idx], cv2.ml.ROW_SAMPLE, train_labels[:idx])
    return knn

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
    knn = train_knn()
    if knn is None:
        return -1  # KNN 모델이 훈련되지 않으면 종료

    img = np.zeros((400, 400), dtype=np.uint8)
    cv2.namedWindow("img")

    param = {
        'img': img,
        'drawing': False,
        'pt_prev': (0, 0)
    }
    cv2.setMouseCallback("img", on_mouse, param)

    cv2.imshow("img", img)
    cv2.waitKey(0)

    # 이미지 크기 조정 및 데이터 전처리
    img_resize = cv2.resize(img, (20, 20))
    img_float = img_resize.astype(np.float32).flatten().reshape(1, -1)

    # KNN을 사용하여 예측
    _, result, _, _ = knn.findNearest(img_float, k=3)
    print("예측된 숫자:", int(result[0][0]))

if __name__ == "__main__":
    main()
