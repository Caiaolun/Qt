#include "cal_contact.h"

cal_contact::cal_contact(QWidget *parent) : QWidget(parent)
{
    _emailLabel = new QLabel("电子邮件: ");
    _addrLabel = new QLabel("联系地址: ");
    _codeLabel = new QLabel("邮政编码: ");
    _moviTellLabel = new QLabel("移动电话: ");
    _proTellLabel = new QLabel("办公电话: ");

    _emailLineEdit = new QLineEdit();
    _addLineEdit = new QLineEdit();
    _codeLineEdit = new QLineEdit();
    _moviTellLineEdit = new QLineEdit();
    _proTellLineEdit = new QLineEdit();

    _moviTellCheckBook = new QCheckBox("接受留言");

    _contactMainLayout = new QGridLayout(this);
    _contactMainLayout->setSpacing(10);
    _contactMainLayout->setMargin(15);

    _contactMainLayout->addWidget(_emailLabel, 0, 0);
    _contactMainLayout->addWidget(_addrLabel, 1, 0);
    _contactMainLayout->addWidget(_codeLabel, 2, 0);
    _contactMainLayout->addWidget(_moviTellLabel, 3, 0);
    _contactMainLayout->addWidget(_proTellLabel, 4, 0);

    _contactMainLayout->addWidget(_emailLineEdit, 0, 1);
    _contactMainLayout->addWidget(_addLineEdit, 1, 1);
    _contactMainLayout->addWidget(_codeLineEdit, 2, 1);
    _contactMainLayout->addWidget(_moviTellLineEdit, 3, 1);
    _contactMainLayout->addWidget(_proTellLineEdit, 4, 1);

    _contactMainLayout->addWidget(_moviTellCheckBook, 3, 2);

    _contactMainLayout->setSizeConstraint(QLayout::SetFixedSize);
}
