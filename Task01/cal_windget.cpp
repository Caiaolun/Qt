#include <QPainter>
#include <QDesktopWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTime>

#include "cal_windget.h"
#include "cal_listwidget.h"
#include "cal_listitemwidget.h"

cal_windget::cal_windget()
{
    setFixedSize(BACKGROUND_WIDTH, BACKGROUND_HEIGHT);
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::WindowMinimizeButtonHint);
    setAutoFillBackground(true);
    setAttribute(Qt::WA_TranslucentBackground);
    QDesktopWidget *deskDop = QApplication::desktop();
    int startX = (deskDop->width() - BACKGROUND_WIDTH) / 2;
    int startY = (deskDop->height() - BACKGROUND_HEIGHT) / 2;
    setGeometry(startX, startY, BACKGROUND_HEIGHT, BACKGROUND_HEIGHT);

    LoadListWidget();
}

void cal_windget::mouseMoveEvent(QMouseEvent* e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        move(e->globalPos() - _point);
    }
}
void cal_windget::mousePressEvent(QMouseEvent* e)
{
    if(e->button() == Qt::LeftButton)
    {
        _point = e->globalPos() - this->frameGeometry().topLeft();
    }
}
void cal_windget::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(QRect(0,0,BACKGROUND_WIDTH,BACKGROUND_HEIGHT),QPixmap(":/Image/img_background.png"));
}
void cal_windget::OnAddButtonClick()
{
    QTime t = QTime::currentTime();
    qsrand(t.msec() + t.second() * 1000);
    int rand_num = qrand() % 3;

    if((rand_num >= 0) && (rand_num < 3))
    {
        ListItemStruct* pContent = _contenList.at(rand_num);
        if(pContent != NULL)
        {
            QListWidgetItem* pListWidgetItem = new QListWidgetItem(_pListWidget);
            pListWidgetItem->setSizeHint(QSize(0, 90));

            cal_listitemwidget* pItemWidget = new cal_listitemwidget();
            pItemWidget->SetPictureImage(pContent->_picturePath);
            pItemWidget->SetItemTitle(pContent->_nameTile);
            pItemWidget->SetItemDetails(pContent->_personDetails);
            connect(pItemWidget, SIGNAL(OnDeleteButtonClickSignal()), this, SLOT(OnDeleteItemWidgetButtonClick()));

            _pListWidget->addItem(pListWidgetItem);
            _pListWidget->setItemWidget(pListWidgetItem, pItemWidget);
        }
    }

}
void cal_windget::OnShowDeleteItemEvent(QListWidgetItem* item)
{
    if(item == NULL)
    {
        return;
    }

    cal_listitemwidget* pItemWidget = (cal_listitemwidget*)_pListWidget->itemWidget(item);
    if(pItemWidget == NULL)
    {
        return;
    }
    pItemWidget->ShowDeleteButton();

    _currenWidgetItem = item;
}
void cal_windget::OnHideDeleteItemEvent()
{
    if(_pListWidget == NULL)
    {
        return;
    }
    for(int i = 0; i < _pListWidget->count(); i++)
    {
        QListWidgetItem* pListItem = (QListWidgetItem*)_pListWidget->item(i);
        if(pListItem != NULL)
        {
            cal_listitemwidget* pItemWidget = (cal_listitemwidget*)_pListWidget->itemWidget(pListItem);
            if(pItemWidget != NULL)
            {
                pItemWidget->HideDeleteButton();
            }
        }
    }
}
void cal_windget::OnDeleteItemWidgetButtonClick()
{
    if(_currenWidgetItem == NULL)
    {
        return;
    }
    _pListWidget->removeItemWidget(_currenWidgetItem);

    cal_listitemwidget* pItemWidget = (cal_listitemwidget*)_pListWidget->itemWidget(_currenWidgetItem);
    if(pItemWidget == NULL)
    {
        delete pItemWidget;
    }
    delete _currenWidgetItem;
}
void cal_windget::LoadListWidget()
{
    QVBoxLayout* pVBoxLayout = new QVBoxLayout(this);
    pVBoxLayout->setContentsMargins(28, 70, 32, 55);
    pVBoxLayout->setSpacing(0);

    QHBoxLayout* pHBoxLayout = new QHBoxLayout();
    pHBoxLayout->setContentsMargins(0, 0, 15, 12);
    pHBoxLayout->setSpacing(0);

    QPushButton* addItemButton = new QPushButton();
    addItemButton->setIcon(QIcon(":/Image/img_add.png"));
    addItemButton->setIconSize(QSize(25, 25));
    addItemButton->setFixedSize(QSize(25, 25));
    addItemButton->setAutoFillBackground(true);
    addItemButton->setStyleSheet("QPushButton{background: transparent;}");

    connect(addItemButton, SIGNAL(clicked()), this, SLOT(OnAddButtonClick()));

    pHBoxLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Fixed));
    pHBoxLayout->addWidget(addItemButton);

    pVBoxLayout->addLayout(pHBoxLayout);

    _pListWidget = new cal_listwidget(this);
    _pListWidget->setFocusPolicy(Qt::NoFocus);
    _pListWidget->setCursor(Qt::ArrowCursor);

    connect(_pListWidget, SIGNAL(ShowDeleteItemSignal(QListWidgetItem*)), this, SLOT(OnShowDeleteItemEvent(QListWidgetItem*)));
    connect(_pListWidget, SIGNAL(HideDeleteItemSignal()), this, SLOT(OnHideDeleteItemEvent()));

    pVBoxLayout->addWidget(_pListWidget, Qt::AlignCenter);

    setLayout(pVBoxLayout);
    LoadContents();

}
void cal_windget::LoadContents()
{
    ListItemStruct* pContent1 = new ListItemStruct();
    pContent1->_picturePath = ":/Image/img_p0.png";
    pContent1->_nameTile = "库克";
    pContent1->_personDetails = "苹果ceo";
    _contenList.append(pContent1);

    ListItemStruct* pContent2 = new ListItemStruct();
    pContent2->_picturePath = ":/Image/img_p1.png";
    pContent2->_nameTile = "章子怡";
    pContent2->_personDetails = "演员A";
    _contenList.append(pContent2);

    ListItemStruct* pContent3 = new ListItemStruct();
    pContent3->_picturePath = ":/Image/img_p2.png";
    pContent3->_nameTile = "汪峰";
    pContent3->_personDetails = "演员A老公";
    _contenList.append(pContent3);

    ListItemStruct* pContent4 = new ListItemStruct();
    pContent4->_picturePath = ":/Image/img_p3.png";
    pContent4->_nameTile = "赵薇";
    pContent4->_personDetails = "割韭菜";
    _contenList.append(pContent4);

    ListItemStruct* pContent5 = new ListItemStruct();
    pContent5->_picturePath = ":/Image/img_p4.png";
    pContent5->_nameTile = "王力宏";
    pContent5->_personDetails = "歌手";
    _contenList.append(pContent5);

    ListItemStruct* pContent6 = new ListItemStruct();
    pContent6->_picturePath = ":/Image/img_p5.png";
    pContent6->_nameTile = "任泉";
    pContent6->_personDetails = "演员B";
    _contenList.append(pContent6);

    ListItemStruct* pContent7 = new ListItemStruct();
    pContent7->_picturePath = ":/Image/img_p6.png";
    pContent7->_nameTile = "秦岚";
    pContent7->_personDetails = "演员C";
    _contenList.append(pContent7);
}
