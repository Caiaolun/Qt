#include "cal_listitemwidget.h"



#include <QGridLayout>
#include <QPixmap>

cal_listitemwidget::cal_listitemwidget()
{
    LoadLayou();
}



void cal_listitemwidget::OnDeteleButtonSelected()
{
    emit OnDeleteButtonClickSignal();
}
void cal_listitemwidget::SetPictureImage(QString pictureStr)
{
    QPixmap pixmap(pictureStr);
    if(_pPictureLabel == NULL || pixmap.isNull())
    {
        return;
    }
    _pPictureLabel->setPixmap(pixmap.scaled(_pPictureLabel->width(), _pPictureLabel->height(),
                                            Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void cal_listitemwidget::LoadLayou()
{
    _pInfoWidget = new QWidget(this);
    _pInfoWidget->setAutoFillBackground(true);
    _pInfoWidget->setGeometry(0 ,0 ,BACKGROUND_WIDTH, 90);

    QGridLayout* pLayout = new QGridLayout(_pInfoWidget);
    pLayout->setVerticalSpacing(1);
    pLayout->setContentsMargins(5, 5, 5, 5);

    _pPictureLabel = new QLabel(this);
    _pPictureLabel->setFixedSize(90, 90);

    _pTitleLabel = new QLabel(this);
    _pTitleLabel->setFont(QFont("Arial-Bold", 25, 50));

    _pDetailsLabel = new QLabel(this);
    _pDetailsLabel->setFont(QFont("Arial-Bold", 15, 50));

    pLayout->addWidget(_pPictureLabel, 0, 0, 2, 1);
    pLayout->addWidget(_pTitleLabel, 0, 1, Qt::AlignLeft);
    pLayout->addWidget(_pDetailsLabel, 1, 1, 1, 1, Qt::AlignLeft);

    _pInfoWidget->setLayout(pLayout);

    _pDeleteButton = new QPushButton(this);
    _pDeleteButton->setIcon(QIcon(":/Image/img_delete.png"));
    _pDeleteButton->setIconSize(QSize(DELETEBUTTON_WIDTH,90));
    _pDeleteButton->setFixedSize(QSize(DELETEBUTTON_WIDTH, 90));
    _pDeleteButton->setAutoFillBackground(true);
    _pDeleteButton->setFlat(true);
    _pDeleteButton->setGeometry(BACKGROUND_WIDTH - DELETEBUTTON_WIDTH - 40, 0, DELETEBUTTON_WIDTH, 90);
    _pDeleteButton->setHidden(true);

    connect(_pDeleteButton, SIGNAL(clicked()), SLOT(OnDeteleButtonSelected()));
}
void cal_listitemwidget::HideDeleteButton()
{
    _pInfoWidget->setGeometry(0, 0, BACKGROUND_WIDTH, 90);
    _pDeleteButton->setHidden(true);
}
void cal_listitemwidget::ShowDeleteButton()
{
    if(_pInfoWidget == NULL)
    {
        return;
    }
    _pInfoWidget->setGeometry(-DELETEBUTTON_WIDTH, 0, BACKGROUND_WIDTH, 90);
    _pDeleteButton->setHidden(false);
}
void cal_listitemwidget::SetItemDetails(QString detailsStr)
{
    if(_pDetailsLabel == NULL)
    {
        return;
    }
    _pDetailsLabel->setText(detailsStr);
}

void cal_listitemwidget::SetItemTitle(QString title)
{
    if(title == NULL)
    {
        return;
    }
    _pTitleLabel->setText(title);
}
