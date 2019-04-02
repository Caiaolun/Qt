#include "cal_mainwidget.h".h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    cal_mainwidget w;
    w.show();

    return a.exec();
}
