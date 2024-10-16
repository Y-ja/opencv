import cv2

folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"

# 이미지 읽기
src = cv2.imread(folder + "imgn.jpg", cv2.IMREAD_COLOR)

if src is None:
    print("이미지를 열 수 없거나 찾을 수 없습니다!")
    exit(-1)

# Haar Cascade 분류기 로드
classifier = cv2.CascadeClassifier(folder + "haarcascade_frontalface_default.xml")
if classifier.empty():
    print("Haar Cascade 분류기를 로드할 수 없습니다!")
    exit(-1)

# 얼굴 감지
faces = classifier.detectMultiScale(src, scaleFactor=1.1, minNeighbors=3, minSize=(30, 30))

# 얼굴 주변에 박스 그리기
for (x, y, w, h) in faces:
    cv2.rectangle(src, (x, y), (x + w, y + h), (255, 0, 0), 2)  # 빨간색 박스

# 결과 이미지 표시
cv2.imshow("Original Image", src)
cv2.waitKey(0)
cv2.destroyAllWindows()
