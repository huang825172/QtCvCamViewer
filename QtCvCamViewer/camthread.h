#pragma once

#include <QThread>
#include <QtWidgets/QWidget>
#include "opencv.hpp"

class CamThread : public QThread
{
	Q_OBJECT

public:
	CamThread(QObject *parent);

	void run();
	bool done;

signals:
	void Frame(QImage f);
};
