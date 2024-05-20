#include "mainwindow.h"
#include <QApplication>
#include <QStackedWidget>
#include "registerWindow.h"

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    QStackedWidget window;
    auto screen    = new mainWindow( window );
    auto regWindow = new registerWindow( window );

    window.addWidget( screen );
    window.addWidget( regWindow );

    window.setCurrentIndex( 0 );
    window.showMaximized();

    return a.exec();
}
