#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    //LeftLayout
    QLabel* _userNameLabel;
    QLabel* _nameLabel;
    QLabel* _sexLabel;
    QLabel* _departmentLabel;
    QLabel* _ageLabel;
    QLabel* _otherLabel;
    QLineEdit* _userNameLineEdit;
    QLineEdit* _nameLineEdit;
    QComboBox* _sexComboBox;
    QTextEdit* _departmentTextEdit;
    QLineEdit* _ageLineEdit;
    QGridLayout* _leftLayout;

    //rightLayout
    QLabel* _headLabel;
    QLabel* _headIconLabel;
    QPushButton* _updateHeadButton;
    QHBoxLayout* _topRightLayout;
    QLabel* _introductionLabel;
    QTextEdit* _introductionTextEdit;
    QVBoxLayout* _rightLayout;

    //buttomLayout
    QPushButton* _okButton;
    QPushButton* _cancelButton;
    QHBoxLayout* _buttomLayout;

    //topLayout
    QHBoxLayout* _topLayout;

    //mainLayout
    QGridLayout* _mainLayout;
};

#endif // WIDGET_H
