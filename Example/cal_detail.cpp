#include "cal_detail.h"

cal_detail::cal_detail(QWidget *parent) : QWidget(parent)
{
    _nationLabel = new QLabel("国家/地址: ");
    _provinceLabel = new QLabel("省份: ");
    _cityLabel = new QLabel("城市: ");
    _instroductLabel = new QLabel("个人说明: ");

    _nationComboBox = new QComboBox();
    _nationComboBox->addItem("中国");
    _nationComboBox->addItem("美国");
    _nationComboBox->addItem("英国");

    _provinceComboBox = new QComboBox();
    _provinceComboBox->addItem("江苏省");
    _provinceComboBox->addItem("广东省");
    _provinceComboBox->addItem("山东省");

    _cityComboBox = new QLineEdit();
    _instroductTextEdit = new QTextEdit();

    _detailMainLayout = new QGridLayout(this);
    _detailMainLayout->setMargin(15);
    _detailMainLayout->setSpacing(10);

    _detailMainLayout->addWidget(_nationLabel, 0, 0);
    _detailMainLayout->addWidget(_provinceLabel, 1, 0);
    _detailMainLayout->addWidget(_cityLabel, 2, 0);
    _detailMainLayout->addWidget(_instroductLabel, 3, 0);

    _detailMainLayout->addWidget(_nationComboBox, 0, 1);
    _detailMainLayout->addWidget(_provinceComboBox, 1, 1);
    _detailMainLayout->addWidget(_cityComboBox, 2, 1);
    _detailMainLayout->addWidget(_instroductTextEdit, 3, 1);

    _detailMainLayout->setSizeConstraint(QLayout::SetFixedSize);

}
