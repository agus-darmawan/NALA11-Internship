#include <QtWidgets/QApplication>
// #include "include/mainwindow.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "MATERI_3");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}