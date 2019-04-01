#include <QApplication>

#include "cal_windget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    cal_windget w;

    w.show();

    return a.exec();
}
