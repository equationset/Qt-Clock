#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>

class Clock : public QWidget
{
    Q_OBJECT
public:
    explicit Clock(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent*event) override;


signals:

};

#endif // CLOCK_H
