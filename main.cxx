#include <QApplication>
#include <QStackedWidget>
#include "screenWidget.hxx"

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );
    screenWidget window;

    window.setCurrentWidget( window.signIN );
    window.show();

    return app.exec();
}
