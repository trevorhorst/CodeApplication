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
    mToxinsBox("Toxins")
{
    // Configure central widget layout
    mHTGrid.addWidget(&mHypovolemiaBox, 1, 0);
    mHTGrid.addWidget(&mHypoxiaBox, 2, 0);
    mHTGrid.addWidget(&mHydrogenIonBox, 3, 0);
    mHTGrid.addWidget(&mHypothermiaBox, 4, 0);
    mHTGrid.addWidget(&mTensionBox, 5, 0);
    mHTGrid.addWidget(&mTamponadeBox, 6, 0);
    mHTGrid.addWidget(&mToxinsBox, 7, 0);

    mActivityWidgetLayout.addWidget(&mDigitalClock, 0, 0);
    mActivityWidgetLayout.addWidget(&mActivityLog, 1, 0);
    mActivityWidgetLayout.addLayout(&mHTGrid, 0, 1);
    // mActivityWidgetLayout.addWidget(&mActivityLog, 0, 1);
    // mActivityWidgetLayout.addWidget(&mHTBox, 1, 10);

    mCentralWidgetLayout.addWidget(&mStartButton, 0, 0);
    mCentralWidgetLayout.addLayout(&mActivityWidgetLayout, 1, 0);
    // End configure central widget layout

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
}

MainWindow::~MainWindow()
{
}

void MainWindow::onStart()
{
    mActivityLog.appendPlainText("Start Button Pressed");
    qDebug("Start Button Pressed");
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
