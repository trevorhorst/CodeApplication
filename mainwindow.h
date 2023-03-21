#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QCheckBox>
#include <QPlainTextEdit>
#include <QLCDNumber>
#include <QElapsedTimer>

#include "digitalclock.h"


class MainWindow :
        public QMainWindow
{
    Q_OBJECT

    static const int32_t lcd_display_digits;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onStart();
    void onHTCheck();
    void logActivity(const QString &activity);

    void heartbeat();

private:
    QWidget mCentralWidget;
    QGridLayout mCentralWidgetLayout;

    QPushButton mStartButton;
    QLCDNumber mLCDTimer;

    // Activity Grid
    QGridLayout mActivityWidgetLayout;
    DigitalClock mDigitalClock;
    QPlainTextEdit mActivityLog;

    // H & T Grid
    QGridLayout mHTGrid;
    QCheckBox mHypovolemiaBox;
    QCheckBox mHypoxiaBox;
    QCheckBox mHydrogenIonBox;
    QCheckBox mHypothermiaBox;
    QCheckBox mTensionBox;
    QCheckBox mTamponadeBox;
    QCheckBox mToxinsBox;

    QTimer mHeartbeat;
    QElapsedTimer mElapsedTime;
};
#endif // MAINWINDOW_H
