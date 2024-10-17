import cv2
import numpy as np

# 이미지 파일 경로 설정
folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"
image_path1 = folder + "box.png"
image_path2 = folder + "box_in_scene.png"

# 이미지 파일 열기 (그레이스케일)
src1 = cv2.imread(image_path1, cv2.IMREAD_GRAYSCALE)
src2 = cv2.imread(image_path2, cv2.IMREAD_GRAYSCALE)

# 이미지 로드 확인
if src1 is None or src2 is None:
    print("이미지를 열 수 없습니다. 경로를 확인하세요.")
    exit(-1)

# ORB 객체 생성
orb = cv2.ORB_create()

# 키포인트와 디스크립터 저장할 변수
key1, desc1 = orb.detectAndCompute(src1, None)  # src1의 키포인트 및 디스크립터 계산
key2, desc2 = orb.detectAndCompute(src2, None)  # src2의 키포인트 및 디스크립터 계산

# 매칭을 위한 BFMatcher 객체 생성
matcher = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck=True)
matches = matcher.match(desc1, desc2)

# 매칭된 키포인트의 수 출력
print("매칭된 키포인트의 수:", len(matches))

# 매칭 결과를 거리 기준으로 정렬
matches = sorted(matches, key=lambda x: x.distance)

# 좋은 매칭만 저장할 벡터
numGoodMatches = 10  # 상위 N개의 매칭
good_matches = matches[:numGoodMatches]

# Homography 계산을 위한 키포인트 좌표 추출
srcPoints = np.float32([key1[m.queryIdx].pt for m in good_matches]).reshape(-1, 2)
dstPoints = np.float32([key2[m.trainIdx].pt for m in good_matches]).reshape(-1, 2)

# Homography 행렬 계산
homography, _ = cv2.findHomography(srcPoints, dstPoints, cv2.RANSAC)

# 원본 이미지에 변환 적용
warpedImage = cv2.warpPerspective(src1, homography, (src2.shape[1], src2.shape[0]))

# 원본 이미지와 매칭 결과 이미지 표시
imgMatches = cv2.drawMatches(src1, key1, src2, key2, good_matches, None)

cv2.imshow("Original Image 1", src1)
cv2.imshow("Original Image 2", src2)
cv2.imshow("Good Matches", imgMatches)
cv2.imshow("Warped Image", warpedImage)  # 변환된 이미지 표시

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()  # 모든 윈도우 닫기
