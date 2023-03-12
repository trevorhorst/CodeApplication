#include <QApplication>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QHBoxLayout>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // Set layout
    layout()->addWidget(&mDigitalClock);


    setWindowTitle(tr("CodeApplication"));
    resize(200, 200);
}

MainWindow::~MainWindow()
{
}
