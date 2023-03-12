#include <QApplication>

#include "mainwindow.h"
#include "digitalclock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DigitalClock clock;
    clock.show();
    // MainWindow w;
    // w.show();
    return a.exec();
}
