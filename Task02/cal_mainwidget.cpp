#include "cal_mainwidget.h"


#include <QDesktopWidget>
#include <QApplication>
#include <QPainter>
#include <QMouseEvent>
#include <QTableWidget>


cal_mainwidget::cal_mainwidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(BACKGROUND_WIDTH, BACKGROUND_HEIGHT);
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::WindowMinimizeButtonHint);
    setAutoFillBackground(true);
    setAttribute(Qt::WA_TranslucentBackground);
    QDesktopWidget *deskDop = QApplication::desktop();
    int startX = (deskDop->width() - BACKGROUND_WIDTH) / 2;
    int startY = (deskDop->height() - BACKGROUND_HEIGHT) / 2;
    setGeometry(startX, startY, BACKGROUND_HEIGHT, BACKGROUND_HEIGHT);
}

void cal_mainwidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(QRect(0,0,BACKGROUND_WIDTH,BACKGROUND_HEIGHT),QPixmap(":/Resources02/background.png"));
}
void cal_mainwidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - _point);
    }
}
void cal_mainwidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        _point = event->globalPos() - this->frameGeometry().topLeft();
    }
}
void cal_mainwidget::CreateTableWidget()
{

}
