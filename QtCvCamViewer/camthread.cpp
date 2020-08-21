#include "camthread.h"
#include "opencv2/imgproc/types_c.h"

CamThread::CamThread(QObject *parent) : QThread(parent)
{
}

void CamThread::run()
{
	done = false;
	cv::Mat frame;
	cv::VideoCapture cap(0);
	QImage img;
	while (cap.isOpened() && !done) {
		cap >> frame;
		cvtColor(frame, frame, CV_BGR2RGB);
		img = QImage(
			(frame.data), frame.cols, frame.rows,
			static_cast<int>(frame.step),
			QImage::Format_RGB888);
		emit Frame(img);
	}
}
