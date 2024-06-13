#pragma once
#ifndef CLIENTSOCKET
#    define CLIENTSOCKET
#    include <string>
#    include <boost/bind/bind.hpp>
#    include <boost/shared_ptr.hpp>
#    include <boost/enable_shared_from_this.hpp>
#    include <boost/asio.hpp>
#    include <QDebug>

class clientSocket
{
  public:
    boost::asio::io_context &io_context;
    boost::asio::ip::tcp::resolver resolver;
    boost::asio::ip::tcp::socket handle;
    clientSocket( boost::asio::io_context &io_context ) :
        io_context( io_context ),
        resolver( io_context ),
        handle( io_context )
    {
    }

    void connect( std::string host, std::string port )
    {
        resolver.async_resolve( host, port, std::bind( &clientSocket::on_connect, this, boost::asio::placeholders::error, boost::asio::placeholders::results ) );
    }

    void write( std::string data )
    {
        boost::asio::async_write( handle, boost::asio::buffer( data, data.size() ), []( boost::system::error_code error, std::size_t size )
                                  {
        if ( error == boost::asio::error::eof )
            return;
        else if ( error )
            throw boost::system::system_error( error ); } );
    }

    auto read( boost::asio::streambuf &buff )
    {
        return boost::asio::async_read( handle, buff, boost::asio::use_future ).share();
    }

    void readCall( boost::asio::streambuf &buff, void( callback )( boost::system::error_code, std::size_t, boost::asio::streambuf * ) )
    {
        boost::asio::async_read( handle, buff, std::bind( callback, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred, &buff ) );
    }

    void close()
    {
        handle.close();
    }

  private:
    void on_connect( const boost::system::error_code &ec, boost::asio::ip::tcp::resolver::results_type results )
    {
        if ( ec == boost::asio::error::eof )
            return;
        else if ( ec )
        {
            qDebug() << ec.what();
            // throw boost::system::system_error( ec );
        }
        boost::asio::async_connect( handle, results.begin(), []( boost::system::error_code, boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> endpoint ) {} );
    }
};
#endif
