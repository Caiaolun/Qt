#include "cal_content.h"
#include <QSplitter>
#include <QApplication>
#include <QListWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplitter* splitterMain = new QSplitter(Qt::Horizontal, 0);

    QListWidget* list = new QListWidget(splitterMain);
    list->insertItem(0, "基本信息");
    list->insertItem(1, "联系方式");
    list->insertItem(2, "详细资料");

    cal_content* content = new cal_content(splitterMain);
    QObject::connect(list, SIGNAL(currentRowChanged(int)), content->_stack, SLOT(setCurrentIndex(int)));



    splitterMain->show();
    return a.exec();
}
