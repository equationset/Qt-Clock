#include "clock.h"
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QColor>
#include <QTime>


static QPoint sed[4]={QPoint(0,-70),QPoint(2,0),QPoint(0,10),QPoint(-2,0)};
static QPoint min[4]={QPoint(0,-60),QPoint(4,0),QPoint(0,12),QPoint(-4,0)};
static QPoint hour[4]={QPoint(0,-50),QPoint(6,0),QPoint(0,13),QPoint(-6,0)};


Clock::Clock(QWidget *parent) : QWidget(parent)
{
QTimer*timer=new QTimer(this);
connect(timer,SIGNAL(timeout()),this,SLOT(update));
timer->start(1000);
}

void Clock::paintEvent(QPaintEvent *parent)
{
    QPainter painter(this);
    QTime time=QTime::currentTime();

    painter.translate(100,100);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::red);
    painter.setPen(Qt::red);
    painter.save();
    painter.rotate(6.0*time.second());
    painter.drawConvexPolygon(sed,4);
    painter.restore();


    painter.setBrush(Qt::blue);
    painter.setPen(Qt::blue);
    painter.save();
    painter.rotate(6.0*time.minute()+time.second()/60);
    painter.drawConvexPolygon(min,4);
    painter.restore();


    painter.setBrush(Qt::black);
    painter.setPen(Qt::black);
    painter.save();
    painter.rotate(30*time.hour()+time.minute()/60);
    painter.drawConvexPolygon(hour,4);
    painter.restore();


    for(int i=0;i<12;i++)
    {
        painter.drawLine(0,-98,0,-90);
        painter.rotate(6);
    for(int j=0;j<4;j++)
        {
            painter.drawLine(0,-98,0,-97);
         painter.rotate(6);
        }
    }
}
