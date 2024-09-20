#include "mainwindow.h"

#include <QApplication>
#include "extern.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.on_start_monitor_clicked();
    w.show();
    a.exec();

    return 0;
}
