#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "digitalclock.h"

class MainWindow :
        public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onStart();

private:
    QWidget mCentralWidget;
    QGridLayout mCentralWidgetLayout;
    QPushButton mStartButton;
    DigitalClock mDigitalClock;

};
#endif // MAINWINDOW_H
