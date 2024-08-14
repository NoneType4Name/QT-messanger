#include <qcoreevent.h>
#include <thread>
#include <QApplication>
#include <QStackedWidget>
#include <QDebug>
#include <QDir>
#include <QStandardPaths>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/asio/use_awaitable.hpp>
#include <boost/json.hpp>
#include "messenger.hxx"
#include "screenWidget.hxx"

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );
    messenger::websocket.connect();
    messenger::configsPath = app.applicationDirPath();
    messenger::configsPath.mkdir( "configs" );
    messenger::configsPath.cd( "configs" );
    screenWidget window;
    // window.mainWidget->previews->createPreviewDown( "NoneType4Name.", "std::string lastMessage", "16.05" );
    // window.mainWidget->previews->createPreviewDown( "cuvi", "я твою семью Смартфон vivo", "15:30" );
    // window.mainWidget->messages->createMessageDown( "Привет!.", "15:30", 1 );
    // window.mainWidget->messages->createMessageDown "Я всю твою семью вырежу, а потом и к тебе вернусь!!!\nСмартфон vivo", "15:30", 0 );
    std::thread websock_thread { [ & ]()
                                 { messenger::io.run(); } };
    auto err { app.exec() };
    app.processEvents();
    websock_thread.join();
    return err;
}
