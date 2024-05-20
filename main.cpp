#include "mainwindow.h"
#include <QApplication>
#include <QStackedWidget>

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    QStackedWidget window;
    auto screen = new mainWindow;

    window.addWidget( screen );
    window.setCurrentIndex( 0 );
    window.showMaximized();

    return a.exec();
}
