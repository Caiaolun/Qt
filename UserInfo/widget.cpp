#include "widget.h"

#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("UserInfo");

    //leftLayoutSet
    _userNameLabel = new QLabel("用户名: ");
    _userNameLineEdit = new QLineEdit();

    _nameLabel = new QLabel("姓名: ");
    _nameLineEdit = new QLineEdit();

    _sexLabel = new QLabel("性别: ");
    _sexComboBox = new QComboBox();
    _sexComboBox->addItem("女");
    _sexComboBox->addItem("男");

    _departmentLabel = new QLabel("部门: ");
    _departmentTextEdit = new QTextEdit();

    _ageLabel = new QLabel("年龄: ");
    _ageLineEdit = new QLineEdit();

    _otherLabel = new QLabel("具备: ");
    _otherLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    _leftLayout = new QGridLayout();
    _leftLayout->addWidget(_userNameLabel, 0, 0);
    _leftLayout->addWidget(_userNameLineEdit, 0, 1);

    _leftLayout->addWidget(_nameLabel, 1, 0);
    _leftLayout->addWidget(_nameLineEdit, 1, 1);

    _leftLayout->addWidget(_sexLabel, 2, 0);
    _leftLayout->addWidget(_sexComboBox, 2, 1);

    _leftLayout->addWidget(_departmentLabel, 3, 0);
    _leftLayout->addWidget(_departmentTextEdit, 3, 1);

    _leftLayout->addWidget(_ageLabel, 4, 0);
    _leftLayout->addWidget(_ageLineEdit, 4, 1);

    _leftLayout->addWidget(_otherLabel, 5, 0, 1, 2);

//    _leftLayout->setColumnStretch(1, 3);

    //rightLayoutSet
    _headLabel = new QLabel("头像: ");

    _headIconLabel = new QLabel();
    QPixmap icon(":/Image/icon.jpg");
    _headIconLabel->setPixmap(icon);
    _headIconLabel->resize(icon.width(), icon.height());

    _updateHeadButton = new QPushButton("更新");

    _topRightLayout = new QHBoxLayout();
    _topRightLayout->setSpacing(20);    //Set constrol and cinstrol width 20
    _topRightLayout->addWidget(_headLabel);
    _topRightLayout->addWidget(_headIconLabel);
    _topRightLayout->addWidget(_updateHeadButton);


    _introductionLabel =  new QLabel("个人说明");
    _introductionTextEdit = new QTextEdit();

    _rightLayout = new QVBoxLayout();
    _rightLayout->setMargin(10);    //Set constrol with mainwidget width and height 10
    _rightLayout->addLayout(_topRightLayout);
    _rightLayout->addWidget(_introductionLabel);
    _rightLayout->addWidget(_introductionTextEdit);

    //topLayoutSet
    _topLayout = new QHBoxLayout();
    _topLayout->addLayout(_leftLayout);
    _topLayout->addLayout(_rightLayout);

    //buttomLayoutSet
    _okButton = new QPushButton("确定");

    _cancelButton = new QPushButton("取消");

    _buttomLayout = new QHBoxLayout();
    _buttomLayout->addStretch();    // buttomLayou add Stretch
    _buttomLayout->addWidget(_okButton);
    _buttomLayout->addWidget(_cancelButton);


    //mainLayoutSet
    _mainLayout = new QGridLayout(this);
    _mainLayout->setMargin(15);
    _mainLayout->setSpacing(10);
    _mainLayout->addLayout(_topLayout, 0, 0);
    _mainLayout->addLayout(_buttomLayout, 1, 0, 1, 2);
    _mainLayout->setSizeConstraint(QLayout::SetFixedSize);    // Set mainwidget fixed size

}

Widget::~Widget()
{

}
