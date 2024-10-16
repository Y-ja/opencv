import cv2
import cv2.aruco as aruco
import numpy as np

# 이미지 파일 경로 설정
folder = "/home/test/Desktop/opencv/opencv/cppOpen/build/data/"
image_path = folder + "markers.jpg"

# 이미지 파일 열기
src = cv2.imread(image_path, cv2.IMREAD_COLOR)
if src is None:
    print("이미지를 열 수 없습니다.")
    exit(-1)

# 결과 이미지 표시
cv2.imshow("Original Image", src)

# ArUco 마커 탐지
markerIds, markerCorners, _ = aruco.detectMarkers(src, aruco.Dictionary_get(aruco.DICT_4X4_250))

# 마커가 탐지되었는지 확인
if markerIds is not None:
    # 탐지된 마커 그리기
    aruco.drawDetectedMarkers(src, markerCorners, markerIds)
    
    # 카메라 매트릭스 및 왜곡 계수 (예시 값 사용)
    cameraMatrix = np.array([[1000, 0, src.shape[1] / 2],
                              [0, 1000, src.shape[0] / 2],
                              [0, 0, 1]], dtype=float)
    distCoeffs = np.zeros((5, 1))  # 왜곡 계수 초기화
    
    # 포즈 추정
    rvecs, tvecs, _ = aruco.estimatePoseSingleMarkers(markerCorners, 0.05, cameraMatrix, distCoeffs)

    # 각 마커의 포즈를 그리기
    for i in range(len(markerIds)):
        aruco.drawAxis(src, cameraMatrix, distCoeffs, rvecs[i], tvecs[i], 0.1)  # 축 그리기
    
    # 결과 이미지 출력
    cv2.imshow("Detected Markers", src)
else:
    print("마커가 감지되지 않았습니다.")  # 마커가 감지되지 않은 경우

cv2.waitKey(0)  # 키 입력 대기
cv2.destroyAllWindows()  # 모든 윈도우 닫기
