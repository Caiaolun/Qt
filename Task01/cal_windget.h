#ifndef CAL_WINDGET_H
#define CAL_WINDGET_H
#include <QWidget>
#include <QMouseEvent>
#include <QListWidgetItem>

#include "cal_listwidget.h"
#include "cal_listitemwidget.h"

#define BACKGROUND_WIDTH 436
#define BACKGROUND_HEIGHT 859

typedef struct listitemstruct
{
    QString _picturePath;
    QString _nameTile;
    QString _personDetails;
}ListItemStruct;

class cal_windget : public QWidget
{
    Q_OBJECT
public:
    cal_windget();
protected:
    void mouseMoveEvent(QMouseEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void paintEvent(QPaintEvent *e);
signals:
    void ShowDeleteItemSignal(QListWidgetItem*);
private slots:
    void OnAddButtonClick();
    void OnShowDeleteItemEvent(QListWidgetItem* item);
    void OnHideDeleteItemEvent();
    void OnDeleteItemWidgetButtonClick();

private:
    void LoadListWidget();
    void LoadContents();

private:
    QPoint _point;
    QList<ListItemStruct*> _contenList;
    cal_listwidget* _pListWidget;
    QListWidgetItem* _currenWidgetItem;
};

#endif // CAL_WINDGET_H
