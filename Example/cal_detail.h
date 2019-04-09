#ifndef CAL_DETAIL_H
#define CAL_DETAIL_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QLineEdit>
class cal_detail : public QWidget
{
    Q_OBJECT
public:
    explicit cal_detail(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLabel* _nationLabel;
    QLabel* _provinceLabel;
    QLabel* _cityLabel;
    QLabel* _instroductLabel;

    QComboBox* _nationComboBox;
    QComboBox* _provinceComboBox;
    QLineEdit* _cityComboBox;
    QTextEdit* _instroductTextEdit;

    QGridLayout* _detailMainLayout;
};

#endif // CAL_DETAIL_H
