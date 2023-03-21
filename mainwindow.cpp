#include <QApplication>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QHBoxLayout>
#include <QGridLayout>

#include "mainwindow.h"

const int32_t MainWindow::lcd_display_digits = 7;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(),
    mCentralWidget(),
    mCentralWidgetLayout(&mCentralWidget),
    mStartButton("Start"),
    mLCDTimer(lcd_display_digits),
    mActivityWidgetLayout(),
    mDigitalClock(),
    mActivityLog(),
    mHTGrid(),
    mHypovolemiaBox("Hypovolemia"),
    mHypoxiaBox("Hypoxia"),
    mHydrogenIonBox("Hydorgen Ion"),
    mHypothermiaBox("Hypothermia"),
    mTensionBox("Tension"),
    mTamponadeBox("Tamponade"),
    mToxinsBox("Toxins"),
    mHeartbeat(this)
{
    // Configure central widget layout
    mHTGrid.addWidget(&mHypovolemiaBox, 1, 0);
    mHTGrid.addWidget(&mHypoxiaBox, 2, 0);
    mHTGrid.addWidget(&mHydrogenIonBox, 3, 0);
    mHTGrid.addWidget(&mHypothermiaBox, 4, 0);
    mHTGrid.addWidget(&mTensionBox, 5, 0);
    mHTGrid.addWidget(&mTamponadeBox, 6, 0);
    mHTGrid.addWidget(&mToxinsBox, 7, 0);

    mLCDTimer.setSegmentStyle(QLCDNumber::Filled);

    mActivityLog.setReadOnly(true);
    mActivityWidgetLayout.addWidget(&mActivityLog, 0, 0);
    mActivityWidgetLayout.addLayout(&mHTGrid, 0, 1);
    // mActivityWidgetLayout.addWidget(&mActivityLog, 0, 1);
    // mActivityWidgetLayout.addWidget(&mHTBox, 1, 10);

    mCentralWidgetLayout.addWidget(&mStartButton, 0, 0);
    mCentralWidgetLayout.addWidget(&mLCDTimer, 1, 0);
    mCentralWidgetLayout.addLayout(&mActivityWidgetLayout, 2, 0);
    mCentralWidgetLayout.setRowStretch(1, 1);
    mCentralWidgetLayout.setRowStretch(2, 4);
    // End configure central widget layout

    connect(&mHeartbeat, &QTimer::timeout, this, &MainWindow::heartbeat);
    connect(&mStartButton, SIGNAL(clicked()), this, SLOT(onStart()));
    connect(&mHypovolemiaBox, SIGNAL(clicked()), this, SLOT(onHTCheck()));
    connect(&mHydrogenIonBox, SIGNAL(clicked()), this, SLOT(onHTCheck()));
    connect(&mHypothermiaBox, SIGNAL(clicked()), this, SLOT(onHTCheck()));
    connect(&mHypoxiaBox, SIGNAL(clicked()), this, SLOT(onHTCheck()));
    connect(&mTensionBox, SIGNAL(clicked()), this, SLOT(onHTCheck()));
    connect(&mTamponadeBox, SIGNAL(clicked()), this, SLOT(onHTCheck()));
    connect(&mToxinsBox, SIGNAL(clicked()), this, SLOT(onHTCheck()));

    // mCentralWidgetLayout.addWidget(&mDigitalClock);
    setCentralWidget(&mCentralWidget);
    setWindowTitle(tr("CodeApplication"));

    QString text = QString("00:00.0");
    mLCDTimer.display(text);

    mHeartbeat.start(50);
}

MainWindow::~MainWindow()
{
}

void MainWindow::heartbeat()
{
    if(mElapsedTime.isValid()) {
        int64_t elapsed = mElapsedTime.elapsed();
        int ms = elapsed % 1000;
        int s = (elapsed / 1000) % 60;
        int m = (elapsed / 1000) / 60;
        QTime time(0, m, s, ms);
        // QTime time = QTime::currentTime();
        QString text = time.toString("mm:ss.zzz");
        text.chop(2);
        mLCDTimer.display(text);
    } else {
        // Do we need to do something in here?
    }
}

void MainWindow::onStart()
{
    mElapsedTime.start();
    logActivity("Code started");
}

void MainWindow::logActivity(const QString &activity)
{
    QTime activityTime = QTime::currentTime();
    QString activityString = QString("%0: %1").arg(activityTime.toString("hh:mm:ss"), activity);
    mActivityLog.appendPlainText(activityString);
}

void MainWindow::onHTCheck()
{
    QCheckBox *checkbox = qobject_cast<QCheckBox*>(sender());
    if(checkbox) {
        if(checkbox->isChecked()){
            QString eventText = QString("%0 checked").arg(checkbox->text());
            logActivity(eventText);
        } else {
            QString eventText = QString("%0 unchecked").arg(checkbox->text());
            logActivity(eventText);
        }
    } else {
        qDebug("Checkbox widget is invalid");
    }
}
