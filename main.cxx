#include <QApplication>
#include <QStackedWidget>
#include "signINwidget.hxx"
#include "signupwidget.hxx"

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    QStackedWidget window;
    auto signIN = new signINWidget( window );
    auto signUP = new signUPwidget( window );

    window.addWidget( signIN );
    window.addWidget( signUP );

    window.setCurrentIndex( 0 );
    window.show();

    return a.exec();
}
