#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.setFixedSize(300, 500);

    //w.setWindowFlag(Qt::FramelessWindowHint);

    w.show();
    return a.exec();
}
