#include "view/mainwindow.h"
#include "model/sequenzaDNA.h"
#include "model/sequenzaRNA.h"
#include "model/proteina.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    try{
        QApplication a (argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    } catch(exceptionHandler* e) { std::cout << e->excMessage().toUtf8().constData();}
}

/*
 * Is this the real loss?

    |   ||

    ||  |_

 * Is this just a dead meme?
*/
