#include "qtcvcamviewer.h"
#include "stdafx.h"
#include "opencv.hpp"
#include "opencv2/imgproc/types_c.h"

QtCvCamViewer::QtCvCamViewer(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	ct = new CamThread(this);
	connect(ct, SIGNAL(Frame(QImage)), this, SLOT(dealFrame(QImage)));
}

void QtCvCamViewer::on_StartButton_clicked()
{
	ct->start();
}

void QtCvCamViewer::on_EndButton_clicked()
{
	ui.imageLabel->clear();
	ct->done = true;
	ct->wait();
}

void QtCvCamViewer::dealFrame(QImage img)
{
	if (!ct->done) {
		img = img.scaled(ui.imageLabel->width(), ui.imageLabel->height());
		ui.imageLabel->setPixmap(QPixmap::fromImage(img));
		ui.imageLabel->resize(ui.imageLabel->pixmap()->size());
	}
}

void QtCvCamViewer::closeEvent(QCloseEvent *event)
{
	ct->done = true;
	ct->wait();
	delete ct;
}