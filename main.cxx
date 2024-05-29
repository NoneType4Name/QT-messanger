#include <QApplication>
#include <QStackedWidget>
#include "screenWidget.hxx"

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );
    screenWidget window;

    window.setCurrentWidget( window.mainWidget );
    window.mainWidget->previews->createPreviewDown( "NoneType4Name.", "std::string lastMessage", "16.05" );
    window.mainWidget->previews->createPreviewDown( "cuvi", "я твою семью Смартфон vivo", "15:30" );
    window.mainWidget->messages->createMessageDown( "Привет!.", "15:30", 1 );
    window.mainWidget->messages->createMessageDown( "Я всю твою семью вырежу, а потом и к тебе вернусь!!!\nСмартфон vivo", "15:30", 0 );
    window.show();

    return app.exec();
}
