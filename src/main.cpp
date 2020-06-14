#include <iostream>
#include <opencv2/opencv.hpp>

int main() {

	cv::namedWindow("Example-in", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example-out", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture capture;
	// Hopefully, open the camera.
	capture.open(0);

	cv::Mat inputFrame;
	cv::Mat tempFrame;
	cv::Mat outputFrame;
	for (;;) {
		capture >> inputFrame;
		if (inputFrame.empty()) {
			// Ran out of film
			break;
		}

		// Down sample.
		cv::pyrDown(inputFrame, tempFrame);
		// Convert to gray-scale.
		cv::cvtColor(tempFrame, inputFrame, cv::COLOR_BGR2GRAY);
		cv::Canny(inputFrame, outputFrame, 10, 100, 3, true);

		cv::imshow("Example-in", inputFrame);
		cv::imshow("Example-out", outputFrame);

		if (cv::waitKey(33) >= 0) {
			// Quit
			break;
		}
	}

	return 0;
}
