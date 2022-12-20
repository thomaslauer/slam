#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

int main(int argc, char** argv) {
    std::cout << "Hello world" << std::endl;
    std::cout << argc << std::endl;
    std::cout << argv[0] << std::endl;


    cv::VideoCapture vc(0);

    cv::Mat frame;

    while(1) {
        vc.read(frame);

        if (frame.empty()) {
            std::cout << "Frame is empty, returning" << std::endl;
            break;
        }
        cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);

        cv::imshow("Live", frame);

        if (cv::waitKey(1000 / 30) > 0) {
            break;
        }
    }



    return 0;
}