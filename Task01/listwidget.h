#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QListWidget>
#include <QMouseEvent>

#define BACKGROUND_WIDTH 436
#define BACKGROUND_HEIGHT 859

class listWidget : public QListWidget
{
    Q_OBJECT
public:
    listWidget();

signals:
    void ShowDeleteItemSignal(QListWidgetItem* item);
    void HideDeleteButtonSignal();

protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);

private:
    QPoint* _pDragPoint;
    QListWidgetItem* _pDragItem;
};

#endif // LISTWIDGET_H
