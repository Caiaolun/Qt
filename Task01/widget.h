#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPoint>

#define BACKGROUND_WIDTH 436
#define BACKGROUND_HEIGHT 859

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    //信号槽定义函数
    void OnAddButtonClick();
    void OnShowDeleteItemEvent();
    void OnHideDeleteButtonEvent();
    void OnDeleteItemWidgetButton();

private:
    void LoadLostWidget();
    void LoadContents();

    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    QPoint   _lastMouseSit;

};

#endif // WIDGET_H
