#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;
int main()
{
    // Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "test");
    // Ort::SessionOptions session_options;

    // OrtCUDAProviderOptions cuda_options{};

    //构造了Mat类的矩阵头
    Mat image;
    image = imread("hello.png", 1);
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    //将image图片显示在Display Image窗口
    // imshow("Display Image", image);
    //为0，程序不自动退出。若为5000，则程序等待5秒钟自动退出
    waitKey(0);
    //保存图片名字和格式，，，，，保存的图片
    imwrite("test.jpg", image);
    printf("Hello World!\n");
    return 0;
}

