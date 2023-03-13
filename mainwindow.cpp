#include <QApplication>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QHBoxLayout>
#include <QGridLayout>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(),
    mCentralWidget(),
    mCentralWidgetLayout(&mCentralWidget),
    mStartButton("Start"),
    mDigitalClock()
{
    connect(&mStartButton, SIGNAL(clicked()), this, SLOT(onStart()));

    mCentralWidgetLayout.addWidget(&mStartButton);
    mCentralWidgetLayout.addWidget(&mDigitalClock);
    setCentralWidget(&mCentralWidget);
    setWindowTitle(tr("CodeApplication"));
}

MainWindow::~MainWindow()
{
}

void MainWindow::onStart()
{
    qDebug("Start Button Pressed");
}
