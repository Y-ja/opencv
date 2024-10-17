import cv2

# 이미지 파일 경로 설정
folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"
image_path = folder + "imag.jpg"

# 이미지 파일 열기 (그레이스케일로)
src = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)

# 이미지 로드 여부 확인
if src is None:
    print("이미지를 열 수 없습니다. 경로를 확인하세요:", image_path)
    exit(-1)  # 오류 발생 시 종료

# 키포인트 저장할 리스트
keypoints = cv2.FastFeatureDetector_create()
keypoint = keypoints.detect(src, None)  # FAST 감지 수행

# 첫 번째 키포인트가 존재하는 경우에만 원을 그림
if keypoint:
    pt = (int(keypoint[0].pt[0]), int(keypoint[0].pt[1]))
    cv2.circle(src, pt, 10, (255,), -1)  # 흰색 원으로 그리기

# 원본 이미지와 감지된 이미지를 표시
cv2.imshow("Original Image", src)
cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()  # 모든 윈도우 닫기
