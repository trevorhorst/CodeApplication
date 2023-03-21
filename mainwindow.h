#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QCheckBox>
#include <QPlainTextEdit>

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
    void onHTCheck();
    void logActivity(const QString &activity);

private:
    QWidget mCentralWidget;
    QGridLayout mCentralWidgetLayout;

    QPushButton mStartButton;

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


};
#endif // MAINWINDOW_H
