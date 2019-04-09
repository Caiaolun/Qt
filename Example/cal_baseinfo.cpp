#include "cal_baseinfo.h"

cal_baseInfo::cal_baseInfo(QWidget* parent) : QWidget(parent)
{
    //leftLayoutSet
    _usernameLabel = new QLabel("用户名: ");
    _nameLabel = new QLabel("姓名: ");
    _sexLabel = new QLabel("性别: ");
    _departmentLabel = new QLabel("部门: ");
    _ageLabel = new QLabel("年龄: ");
    _otherLabel = new QLabel("备注 ");
    _otherLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    _userNameLineEdit = new QLineEdit();
    _nameLineEdit = new QLineEdit();;
    _sexComboBox = new QComboBox();
    _sexComboBox->addItem("女");
    _sexComboBox->addItem("男");

    _departmentTextEdit = new QTextEdit();
    _ageLineEdit = new QLineEdit();;

    _leftLayout = new QGridLayout();
    _leftLayout->addWidget(_usernameLabel, 0, 0);
    _leftLayout->addWidget(_nameLabel, 1, 0);
    _leftLayout->addWidget(_sexLabel, 2, 0);
    _leftLayout->addWidget(_departmentLabel, 3, 0);
    _leftLayout->addWidget(_ageLabel, 4, 0);
    _leftLayout->addWidget(_otherLabel, 5, 0, 1, 2);

    _leftLayout->addWidget(_userNameLineEdit, 0, 1);
    _leftLayout->addWidget(_nameLineEdit, 1, 1);
    _leftLayout->addWidget(_sexComboBox, 2, 1);
    _leftLayout->addWidget(_departmentTextEdit, 3, 1);
    _leftLayout->addWidget(_ageLineEdit, 4, 1);

    _leftLayout->setColumnStretch(1, 3);


    //rightTopLayoutSet
    _headLabel = new QLabel("头像: ");

    _headIconLabel = new QLabel();
    QPixmap icon(":/Image/icon.jpg");
    _headIconLabel->setPixmap(icon);
    _headIconLabel->setFixedSize(icon.width(), icon.height());

    _upDateHeadButton = new QPushButton("更新");

    _rightTopLayout = new QHBoxLayout();
    _rightTopLayout->addWidget(_headLabel);
    _rightTopLayout->addWidget(_headIconLabel);
    _rightTopLayout->addWidget(_upDateHeadButton);
    _rightTopLayout->setSpacing(20);

    //rightLayoutSet
    _instroductionLabel = new QLabel("个人说明: ");
    _instroductionTextEdit = new QTextEdit();

    _rightLayout = new QVBoxLayout();
    _rightLayout->addLayout(_rightTopLayout);
    _rightLayout->addWidget(_instroductionLabel);
    _rightLayout->addWidget(_instroductionTextEdit);

    //baseInfoMainLayoutSet
    _baseInfoMainLayout = new QHBoxLayout(this);
    _baseInfoMainLayout->addLayout(_leftLayout);
    _baseInfoMainLayout->addLayout(_rightLayout);
    _baseInfoMainLayout->setMargin(15);
    _baseInfoMainLayout->setSpacing(10);
    _baseInfoMainLayout->setSizeConstraint(QLayout::SetFixedSize);
}
