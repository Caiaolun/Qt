#ifndef LISTITEMWIDGET_H
#define LISTITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

#define BACKGROUND_WIDTH 436
#define BACKGROUND_HEIGHT 859

class listItemWidget : public QWidget
{
    Q_OBJECT
public:
    listItemWidget();

    void SetPictureImage(QString strPicture);
    void SetItemTitle(QString title);
    void SetItemDetails(QString detals);
    void ShowDeleteButton();
    void HideDeleteButton();

signals:
    void OndeleteButtonClickedSignal();

private:
    void LoadLayout();

private:
    QLabel* _pPictureLabel;
    QLabel* _pTitleLabel;
    QLabel* _pDetailsLabel;

    QWidget* _pInformWidget;
    QWidget* _pDeleteWidget;

    QPushButton* _pDeleteButton;
};

#endif // LISTITEMWIDGET_H
