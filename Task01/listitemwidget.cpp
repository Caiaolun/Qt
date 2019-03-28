#include "listitemwidget.h"
#include <QGridLayout>


listItemWidget::listItemWidget()
{

}

void listItemWidget::SetPictureImage(QString strPicture)
{

}
void listItemWidget::SetItemTitle(QString title)
{

}

void listItemWidget::SetItemDetails(QString detals)
{

}
void listItemWidget::ShowDeleteButton()
{

}
void listItemWidget::HideDeleteButton()
{

}
void listItemWidget::OndeleteButtonClickedSignal()
{

}
void listItemWidget::LoadLayout()
{
    _pInformWidget = new QWidget(this);
    _pInformWidget->setAutoFillBackground(true);
    _pInformWidget->setGeometry(0,0,BACKGROUND_WIDTH,90);

    QGridLayout* pLayout = new QGridLayout(_pInformWidget);

    pLayout->setVerticalSpacing(1);
    pLayout->setContentsMargins(5, 5, 5, 5);
}
