// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "digitalclock.h"

#include <QTime>
DigitalClock::DigitalClock(QWidget *parent)
    : QLCDNumber(parent)
    , mTimer(this)
{
    setSegmentStyle(Filled);
    setDigitCount(9);

    connect(&mTimer, &QTimer::timeout, this, &DigitalClock::showTime);
    mElapsedTime.start();
    mTimer.start(75);

    // connect(&mElapsedTime, &QTimer::timeout, this, &DigitalClock::showTime());
    // mElapsedTime.start(50);

    showTime();

    setWindowTitle(tr("Digital Clock"));
    resize(300, 100);
}

void DigitalClock::showTime()
{
    int64_t elapsed = mElapsedTime.elapsed();
    int ms = elapsed % 1000;
    int s = (elapsed / 1000) % 60;
    int m = (elapsed / 1000) / 60;
    QTime time(0, m, s, ms);
    // QTime time = QTime::currentTime();
    QString text = time.toString("mm:ss.z");
    text.chop(2);
    display(text);
}
