import cv2

def main():
    # GStreamer 파이프라인 생성
    pipeline = "v4l2src device=/dev/video0 ! video/x-raw, width=1280, height=720, framerate=30/1 ! videoconvert ! appsink"
    cap = cv2.VideoCapture(pipeline, cv2.CAP_GSTREAMER)  # GStreamer를 사용하여 비디오 캡처 열기

    if not cap.isOpened():
        print("Video open failed.")
        return -1

    delay = 30  # 프레임 지연 시간을 30ms로 설정

    while True:
        ret, frame = cap.read()  # GStreamer에서 프레임 읽기

        if not ret:
            print("Failed to grab frame.")
            break  # 프레임이 비어있으면 루프 종료

        cv2.imshow("frame", frame)  # 프레임 표시

        if cv2.waitKey(delay) == 27:  # ESC 키를 누르면 종료
            break

    cv2.destroyAllWindows()  # 모든 창 닫기
    cap.release()  # 카메라 리소스 해제

if __name__ == "__main__":
    main()
