#include "paintwidget.h"
#include "clock.h"

PaintWidget::PaintWidget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(800,800);
    Clock*pclock=new Clock(this);
    pclock->resize(600,600);
    pclock->move(100,100);
}

PaintWidget::~PaintWidget()
{
}

