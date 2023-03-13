#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QLCDNumber>
#include <QObject>
#include <QHBoxLayout>
#include <QElapsedTimer>
#include <QTimer>


class DigitalClock :
        public QLCDNumber
{
public:
    DigitalClock(QWidget *parent = nullptr);

private slots:
    void showTime();
    QTimer mTimer;
    QElapsedTimer mElapsedTime;
};


#endif // DIGITALCLOCK_H
