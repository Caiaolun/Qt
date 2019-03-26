#include "widget.h"
#include <QCheckBox>
#include <QHBoxLayout>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    _list = new QListWidget(this);
    _delButton = new QPushButton("", this);
    _addButton = new QPushButton("", this);

    pix1 = new QPixmap(":/images/addition.png");
    pix2 = new QPixmap(":/images/delete.png");
    pix3 = new QPixmap(":/images/return.png");
    pix4 = new QPixmap(":/images/Sunyanzi.jpg");
    pix5 = new QPixmap(":/images/Guilunmei.jpeg");

    _addIcon = new QIcon(":/images/addition.png");
    _delIcon = new QIcon(":/images/delete.png");
    _guiIcon = new QIcon(*pix5);
    _sunIcon = new QIcon(*pix4);

    Item1 = new QListWidgetItem(*_sunIcon, "孙燕姿");
    Item2 = new QListWidgetItem(*_guiIcon, "桂纶镁");

    _delButton->setGeometry(QRect(230, 440, 60,60));
    _addButton->setGeometry(QRect(170, 440, 60,60));

    _addButton->setIcon(*_addIcon);
    _delButton->setIcon(*_delIcon);

    _delButton->setIconSize(QSize(100,100));
    _addButton->setIconSize(QSize(100,100));

    _delButton->setFlat(true);
    _addButton->setFlat(true);

    //设置成列表显示
    _list->setViewMode(QListView::ListMode);
    //去掉QListWidget的蓝色边框 **特别烦人的蓝色边框**
    _list->setAttribute(Qt::WA_MacShowFocusRect, 0);
    //QListWidgetItem的图片大小问题
    //图片的大小是由listWidget的setIconSize设定的，而不是ListWidgetItem的SetIcon设定的
    _list->setIconSize(QSize(100,100));
    _list->setWordWrap(true);

    _list->setGeometry(0, 0, 300,440);
    _list->show();


    //信号槽函数加载在指针的按钮
    connect(_addButton,SIGNAL(clicked()),this,SLOT(Onclict_add()));
    connect(_delButton,SIGNAL(clicked()),this,SLOT(Onclict_del()));
}

Widget::~Widget()
{

}
void Widget::Onclict_add()
{
//    QListView
    QListWidgetItem *item=new QListWidgetItem(_list,0);
    item->setIcon(*_sunIcon);

    item->setSizeHint(QSize(80,80));
    QWidget *w = new QWidget(_list);
    QVBoxLayout *layout=new QVBoxLayout(w);
    QLabel *title=new QLabel(w);
    QLabel *text=new QLabel(w);
    title->setText("title");
    title->setFont(QFont("Microsoft YaHei", 20, 75));

    text->setText("Text");
    layout->addWidget(title);
    layout->addWidget(text);
    w->setLayout(layout);
    w->show();

    _list->setItemWidget(item,w);
}
void Widget::Onclict_del()
{
    int n = _list->count();//获取item的总数
    if(n < 0)
    {
        return;
    }
    int ret = _list->currentRow();//获取当前鼠标所选行
    QListWidgetItem *item = _list->takeItem(ret);//删除该行
    delete item;
}
void Widget::Onclict_Alldel()
{
    int n=_list->count();//获取item的总数
    //删去所有item
    for(int i=0;i<n;i++)
    {
        /*
         使用takeItem(row)函数将QListWidget中的第row个item移除，
         移除需要使用delete手动释放其在堆上占用的空间
        */
        QListWidgetItem *item = _list->takeItem(0); //这里是0，不是i，因为每移除一个item都会导致每个item的row发生变化
        delete item;
    }
}

