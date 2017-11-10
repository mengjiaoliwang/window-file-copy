#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
void test1() throw() //异常的接口声明  只许抛出int类型   throw()不允许抛出任何类型的异常
{
    //throw 1;
    throw 3.14;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    try
    {
        test1();
    }
    catch(int)
    {
        qDebug() << "捕获int类型异常";
    }
    catch(...)
    {
         qDebug() << "捕获其他类型异常";
    }


    return a.exec();
}
