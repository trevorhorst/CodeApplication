#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

// #include <QMainWindow>
#include <QPushButton>
#include <QWindow>

class AnalogClock :
        public QWidget
{
    Q_OBJECT

public:
    AnalogClock(QWidget *parent = nullptr);
    ~AnalogClock();

protected:
    void paintEvent(QPaintEvent *) override;


private:
    QPushButton *mStart;

public slots:
    void handleStart();
};

#endif // ANALOGCLOCK_H
