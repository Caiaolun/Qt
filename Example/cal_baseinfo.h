#ifndef CAL_BASEINFO_H
#define CAL_BASEINFO_H

#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

class cal_baseInfo : public QWidget
{
    Q_OBJECT
public:
    explicit cal_baseInfo(QWidget* parent = nullptr);
private:
    //leftLayout
    QLabel* _usernameLabel;
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

    //rightTopLayout
    QLabel* _headLabel;
    QLabel* _headIconLabel;
    QPushButton* _upDateHeadButton;
    QHBoxLayout* _rightTopLayout;

    //rightLayout
    QLabel* _instroductionLabel;
    QTextEdit* _instroductionTextEdit;
    QVBoxLayout* _rightLayout;

    //baseInfoMainLayout
    QHBoxLayout* _baseInfoMainLayout;
};

#endif // CAL_BASEINFO_H
