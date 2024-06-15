#include <QApplication>
#include <QStackedWidget>
#include <QDebug>
#include "screenWidget.hxx"
// #include "webSocket.hxx"
#include <boost/asio.hpp>
#include <boost/asio/use_awaitable.hpp>
#include <future>

namespace
{
    boost::asio::io_context io;
    boost::asio::ip::tcp::socket sock( io );
    boost::asio::ip::tcp::resolver resolver( io );
    // clientSocket sock { io, "127.0.0.1", "1023" };
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
    std::array<char, 10> data( { 'd', 'a', 't', 'a', 0, 0, 0, 0, 0, 0 } );
    QApplication app( argc, argv );
    screenWidget window;
    sock.connect( resolver.resolve( "127.0.0.1", "1023" )->endpoint() );
    sock.write_some( boost::asio::buffer( data ) );
    auto readed = sock.async_read_some( boost::asio::buffer( data ), boost::asio::use_future );
    io.run();
    window.setCurrentWidget( window.mainWidget );
    window.mainWidget->previews->createPreviewDown( "NoneType4Name.", "std::string lastMessage", "16.05" );
    window.mainWidget->previews->createPreviewDown( "cuvi", "я твою семью Смартфон vivo", "15:30" );
    window.mainWidget->messages->createMessageDown( "Привет!.", "15:30", 1 );
    window.mainWidget->messages->createMessageDown( "Я всю твою семью вырежу, а потом и к тебе вернусь!!!\nСмартфон vivo", "15:30", 0 );
    window.show();
    readed.get();
    qDebug() << data.data() << '\n';

    return app.exec();
}
