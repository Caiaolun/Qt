#include "cal_listwidget.h"


cal_listwidget::cal_listwidget(QWidget* parent) : QListWidget(parent)
{
    setAttribute(Qt::WA_MacShowFocusRect, 0);
}
void cal_listwidget::mouseMoveEvent(QMouseEvent* e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        QPoint diffPoints = e->pos() - _dragPoint;

        if(diffPoints.x() < -80)
        {
            if(_dragItem != NULL)
            {
                emit ShowDeleteItemSignal(_dragItem);
            }
        }
        else
        {
            emit HideDeleteItemSignal();
        }
        QListWidget::mouseMoveEvent(e);
    }
}
void cal_listwidget::mousePressEvent(QMouseEvent* e)
{
    if(e->button() == Qt::LeftButton)
    {
        _dragPoint = e->pos();
        _dragItem = this->itemAt(e->pos());
        emit HideDeleteItemSignal();
    }

    QListWidget::mousePressEvent(e);
}

