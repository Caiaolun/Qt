#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QListWidgetItem>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);

    ~Widget();
     void Onclict_Alldel();

private slots:
    //信号槽定义函数
    void Onclict_add();
    void Onclict_del();

private:

    QPushButton* _addButton;
    QPushButton* _delButton;

    QIcon* _addIcon;
    QIcon* _delIcon;
    QIcon* _guiIcon;
    QIcon* _sunIcon;

    QPixmap* pix1;
    QPixmap* pix2;
    QPixmap* pix3;
    QPixmap* pix4;
    QPixmap* pix5;

    QListWidget* _list;
    QListWidgetItem* Item1;
    QListWidgetItem* Item2;

};

#endif // WIDGET_H
