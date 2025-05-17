cmake_minimum_required(VERSION 3.10)
project(mygame)

set(CMAKE_CXX_STANDARD 17)

# include 디렉토리 추가
include_directories(include external)

# 소스 파일 모음
file(GLOB SOURCES "src/*.cpp")

# 실행 파일 생성
add_executable(mygame ${SOURCES})