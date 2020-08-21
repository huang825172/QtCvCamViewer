#pragma once

#include <QtWidgets/QWidget>
#include "ui_qtcvcamviewer.h"
#include "opencv.hpp"
#include "camthread.h"

class QtCvCamViewer : public QWidget
{
    Q_OBJECT

public:
    QtCvCamViewer(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtCvCamViewerClass ui;
	CamThread *ct;

private slots:
	void on_StartButton_clicked();
	void on_EndButton_clicked();
	void dealFrame(QImage f);

protected:
	void closeEvent(QCloseEvent *event);
};
