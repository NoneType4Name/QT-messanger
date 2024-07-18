#include <QApplication>
#include <QStackedWidget>
#include <QDebug>
#include "screenWidget.hxx"
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/asio/use_awaitable.hpp>

namespace
{
    boost::asio::io_context io;
    boost::asio::ip::tcp::resolver resolver( io );
    boost::beast::websocket::stream<boost::asio::ip::tcp::socket> websock( io );
    struct _
    {
        _()
        {
        }
        ~_()
        {
            websock.close( boost::beast::websocket::close_code::normal );
        }
    } _;
} // namespace

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );
    screenWidget window;
    boost::asio::connect( websock.next_layer(), resolver.resolve( "localhost", "8080" ) );
    websock.handshake( "localhost:8080", "/" );
    websock.write( boost::asio::buffer( std::string( R"({"request": "connect", "user": {"id": 1}})" ) ) );
    boost::beast::flat_buffer buffer;
    auto readed { websock.async_read( buffer, boost::asio::use_future ) };
    io.run();
    window.setCurrentWidget( window.mainWidget );
    window.mainWidget->previews->createPreviewDown( "NoneType4Name.", "std::string lastMessage", "16.05" );
    window.mainWidget->previews->createPreviewDown( "cuvi", "я твою семью Смартфон vivo", "15:30" );
    window.mainWidget->messages->createMessageDown( "Привет!.", "15:30", 1 );
    window.mainWidget->messages->createMessageDown( "Я всю твою семью вырежу, а потом и к тебе вернусь!!!\nСмартфон vivo", "15:30", 0 );
    window.show();
    // readed.get();

    return app.exec();
}
