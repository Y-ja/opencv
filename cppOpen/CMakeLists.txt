cmake_minimum_required(VERSION 3.0)
project(helloOpen)

# OpenCV 패키지를 찾습니다
find_package(OpenCV REQUIRED)

# 실행 파일을 생성합니다
add_executable(main helloOpen.cpp)

# OpenCV 라이브러리를 링크합니다
target_link_libraries(main ${OpenCV_LIBS})
