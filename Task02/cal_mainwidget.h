#ifndef CAL_MAINWIDGET_H
#define CAL_MAINWIDGET_H

#include <QWidget>
#include <QPoint>
#include "cal_tablewidget.h"


#define BACKGROUND_WIDTH 436
#define BACKGROUND_HEIGHT 859


class cal_mainwidget : public QWidget
{
    Q_OBJECT
public:
    explicit cal_mainwidget(QWidget *parent = 0);

    void CreateTableWidget();
private:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
signals:

public slots:

private:
    QPoint _point;
    cal_tablewidget _mainTableWidge;
};

#endif // CAL_MAINWIDGET_H
