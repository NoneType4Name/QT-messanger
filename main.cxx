#include <QApplication>
#include <QStackedWidget>
#include <QDebug>
#include "screenWidget.hxx"
#include "webSocket.hxx"
#include <boost/asio.hpp>
#include <boost/asio/use_awaitable.hpp>

namespace
{
    boost::asio::io_context io {};
    clientSocket sock { io };
    struct _
    {
        _()
        {
        }
        ~_()
        {
            sock.close();
        }
    } _;
} // namespace

int main( int argc, char *argv[] )
{
    sock.connect( "127.0.0.1", "1023" );
    io.run();
    // sock.write( "data" );
    // io.run();
    // boost::asio::streambuf buff;
    // sock.readCall( buff, []( boost::system::error_code error, std::size_t size, boost::asio::streambuf *b )
    //                { qDebug() << b << size;} );
    // io.run();
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
