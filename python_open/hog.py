import cv2

# 이미지 파일 경로 설정
folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"
image_path = folder + "imgss.jpg"

# 이미지 파일 열기
frame = cv2.imread(image_path)
if frame is None:
    print("이미지를 열 수 없거나 찾을 수 없습니다!")
    exit(-1)

# HOGDescriptor 초기화 및 사람 감지기 설정
hog = cv2.HOGDescriptor()
hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())

# 사람 감지
detected, _ = hog.detectMultiScale(frame)

# 감지된 영역에 사각형 그리기
for (x, y, w, h) in detected:
    cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 3)

# 원본 이미지와 감지된 이미지를 표시
cv2.imshow("Original Image", frame)

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()  # 모든 윈도우 닫기
