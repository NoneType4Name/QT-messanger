#include "messenger.hxx"
namespace messenger
{
    QDir configsPath;
    boost::asio::io_context io;
    websocket_T::websocket_T() :
        boost::beast::websocket::stream<boost::asio::ip::tcp::socket>( io )
    {
        boost::beast::websocket::stream_base::timeout opt {
            std::chrono::seconds( 10 ),
            std::chrono::seconds( 10 ),
            true };
        set_option( opt );
    }

    websocket_T::~websocket_T()
    {
        if ( is_open() )
            close( boost::beast::websocket::close_code::normal );
    }

    decltype( auto ) websocket_T::connect()
    {
        auto r { boost::asio::connect( next_layer(), resolver.resolve( "localhost", "8080" ) ) };
        handshake( "localhost:8080", "/" );
        return r;
    }
    websocket_T websocket;

    signInErrorCodes signIn()
    {
        QFile userFile { configsPath.absoluteFilePath( "user.json" ) };
        if ( !userFile.open( QIODevice::ReadOnly ) || !userFile.size() )
            return EmptyData;
        boost::json::object request;
        boost::json::parse( userFile.readAll().data() );
        boost::json::object file { boost::json::parse( userFile.readAll().data() ).as_object() };
        userFile.close();
        request[ "request" ] = "connect";
        request[ "user" ]    = { { "id", file[ "id" ].as_int64() }, { "password", file[ "password" ].as_string() } };
        websocket.write( boost::asio::buffer( boost::json::serialize( request ) ) );
        boost::beast::flat_buffer buffer;
        boost::beast::error_code err;
        websocket.read( buffer, err );
        if ( err == boost::beast::error::timeout )
            return TimeOut;
        request = boost::json::parse( std::string( buffer_cast<const char *>( buffer.data() ), buffer.size() ) ).as_object();
        if ( request.contains( "answer" ) && request[ "answer" ].is_int64() )
            return static_cast<signInErrorCodes>( request[ "answer" ].as_int64() );
        else
            return ServerError;
    };
} // namespace messenger
