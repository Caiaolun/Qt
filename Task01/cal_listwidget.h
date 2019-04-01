#ifndef CAL_LISTWIDGET_H
#define CAL_LISTWIDGET_H

#include <QListWidget>
#include <QMouseEvent>

#include "cal_listitemwidget.h"

#define BACKGROUND_WIDTH 436
#define BACKGROUND_HEIGHT 859

class cal_listwidget : public QListWidget
{
    Q_OBJECT
public:
    cal_listwidget(QWidget* parent = 0);

signals:
    void ShowDeleteItemSignal(QListWidgetItem* item);
    void HideDeleteItemSignal();

protected:
    void mouseMoveEvent(QMouseEvent* e);
    void mousePressEvent(QMouseEvent* e);

private:
    QPoint _dragPoint;

    QListWidgetItem* _dragItem;
};

#endif // CAL_LISTWIDGET_H
