#include "mainwindow.h"
#include "Controller.h"
#include "Tests.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Tests T;
    T.TestAll();

    Controller C("BakeryInfo.csv");

    MainWindow w(&C);
    w.setStyleSheet("QMainWindow {background: #FFCEA6;}");
    w.show();
    return a.exec();
}
