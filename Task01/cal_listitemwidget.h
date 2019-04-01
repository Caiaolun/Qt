#ifndef CAL_LISTITEMWIDGET_H
#define CAL_LISTITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>


#define BACKGROUND_WIDTH 436
#define BACKGROUND_HEIGHT 859

#define DELETEBUTTON_WIDTH 145

class cal_listitemwidget : public QWidget
{
    Q_OBJECT
public:
    cal_listitemwidget();

    void SetPictureImage(QString pictureStr);
    void SetItemTitle(QString title);
    void SetItemDetails(QString details);
    void ShowDeleteButton();
    void HideDeleteButton();

signals:
    void OnDeleteButtonClickSignal();

protected slots:
    void OnDeteleButtonSelected();

private:
    void LoadLayou();
private:
    QLabel* _pPictureLabel;
    QLabel* _pTitleLabel;
    QLabel* _pDetailsLabel;

    QWidget* _pInfoWidget;
    QWidget* _pDeleteWidget;

    QPushButton* _pDeleteButton;
};

#endif // CAL_LISTITEMWIDGET_H
