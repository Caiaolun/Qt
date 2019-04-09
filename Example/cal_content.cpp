#include "cal_content.h"

cal_content::cal_content(QWidget *parent) : QWidget(parent)
{
    _baseInfo = new cal_baseInfo();
    _contact = new cal_contact();
    _detail = new cal_detail();

    _AmendButton = new QPushButton("修改");
    _closeButton = new QPushButton("关闭");

    _buttonLayout = new QHBoxLayout();
    _buttonLayout->addStretch();
    _buttonLayout->addWidget(_AmendButton);
    _buttonLayout->addWidget(_closeButton);

    _stack = new QStackedWidget();
    _stack->setFrameStyle(QFrame::Panel | QFrame::Raised);
    _stack->addWidget(_baseInfo);
    _stack->addWidget(_contact);
    _stack->addWidget(_detail);

    _rightLayout = new QVBoxLayout(this);
    _rightLayout->setMargin(10);
    _rightLayout->setSpacing(15);
    _rightLayout->addWidget(_stack);
    _rightLayout->addLayout(_buttonLayout);

}
