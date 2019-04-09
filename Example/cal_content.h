#ifndef CAL_CONTENT_H
#define CAL_CONTENT_H

#include <QWidget>

#include "cal_baseinfo.h"
#include "cal_contact.h"
#include "cal_detail.h"

#include <QStackedWidget>

class cal_content : public QWidget
{
    Q_OBJECT
public:
    explicit cal_content(QWidget *parent = nullptr);

signals:

public slots:

public:
    cal_baseInfo* _baseInfo;
    cal_contact* _contact;
    cal_detail* _detail;

    QPushButton* _AmendButton;
    QPushButton* _closeButton;

    QHBoxLayout* _buttonLayout;

    QStackedWidget* _stack;

    QVBoxLayout* _rightLayout;
};

#endif // CAL_CONTENT_H
