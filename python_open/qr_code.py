import cv2

# 이미지 파일 경로 설정
folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"
image_path = folder + "1vnO4.png"

# 이미지 파일 열기
frame = cv2.imread(image_path)

# QRCodeDetector 객체 생성
detector = cv2.QRCodeDetector()

# QR 코드의 디코딩된 정보와 포인트를 얻기
info, points, _ = detector.detectAndDecode(frame)

if points is not None:
    # QR 코드의 경계선을 그리기
    points = points.astype(int)  # 포인트를 정수형으로 변환
    cv2.polylines(frame, [points], isClosed=True, color=(0, 255, 0), thickness=2)  # 초록색으로 선 그리기
    print("디코딩된 정보:", info)  # 디코딩된 정보 출력
else:
    print("QR 코드가 감지되지 않았습니다.")  # QR 코드가 감지되지 않은 경우

# 원본 이미지와 감지된 이미지를 표시
cv2.imshow("원본 이미지", frame)

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()  # 모든 윈도우 닫기
