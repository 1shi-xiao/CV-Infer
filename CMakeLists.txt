# CMake version
cmake_minimum_required(VERSION 3.20)
# project name
project(Sample)

# opencv
set(OpenCV_DIR ${PROJECT_SOURCE_DIR}//third_parties//opencv-4.10.0//build//)
# onnxruntime library-dir
set(ONNXRuntime_LIB ${PROJECT_SOURCE_DIR}//third_parties//onnxruntime//bin//onnxruntime.dll)
# onnxruntime include-dir
set(ONNXRuntime_INCLUDE_DIR ${PROJECT_SOURCE_DIR}//third_parties//onnxruntime//include//)

find_package(OpenCV)

# include
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${ONNXRuntime_INCLUDE_DIR})

# add a target exe
add_executable(${PROJECT_NAME}  .//src//main.cpp)
# linclude library
target_include_directories(${PROJECT_NAME} PUBLIC ${ONNXRuntime_INCLUDE_DIR})
# link library
target_link_libraries(${PROJECT_NAME}  
    ${OpenCV_LIBS} 
    ${ONNXRuntime_LIB}
)

# 复制库文件到可执行文件目录
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}\\bin)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${PROJECT_SOURCE_DIR}\\third_parties\\opencv-4.10.0\\build\\bin\\libopencv_core4100.dll
                ${PROJECT_SOURCE_DIR}\\third_parties\\opencv-4.10.0\\build\\bin\\libopencv_highgui4100.dll
                ${PROJECT_SOURCE_DIR}\\third_parties\\opencv-4.10.0\\build\\bin\\libopencv_imgcodecs4100.dll
                ${PROJECT_SOURCE_DIR}\\third_parties\\opencv-4.10.0\\build\\bin\\libopencv_imgproc4100.dll
                ${PROJECT_SOURCE_DIR}\\third_parties\\onnxruntime\\bin\\onnxruntime.dll
                $<TARGET_FILE_DIR:${PROJECT_NAME}>)