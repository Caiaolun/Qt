#ifndef CAL_CONTACT_H
#define CAL_CONTACT_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QGridLayout>

class cal_contact : public QWidget
{
    Q_OBJECT
public:
    explicit cal_contact(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLabel* _emailLabel;
    QLabel* _addrLabel;
    QLabel* _codeLabel;
    QLabel* _moviTellLabel;
    QLabel* _proTellLabel;

    QLineEdit* _emailLineEdit;
    QLineEdit* _addLineEdit;
    QLineEdit* _codeLineEdit;
    QLineEdit* _moviTellLineEdit;
    QLineEdit* _proTellLineEdit;

    QCheckBox* _moviTellCheckBook;

    QGridLayout* _contactMainLayout;
};

#endif // CAL_CONTACT_H
