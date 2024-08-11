#pragma once
#ifndef MESSENGER_HXX
#    define MESSENGER_HXX
#    include <QDir>
#    include <boost/beast.hpp>
#    include <boost/json.hpp>
namespace messenger
{
    enum signInErrorCodes
    {
        Ok = 0,
        ServerError,
        WrongData,
        TooManyTries,
        TimeOut,
        EmptyData,

    };
    extern QDir configsPath;
    extern boost::asio::io_context io;
    extern struct websocket_T : public boost::beast::websocket::stream<boost::asio::ip::tcp::socket>
    {
        websocket_T();
        ~websocket_T();
        decltype( auto ) connect();
        boost::asio::ip::tcp::resolver resolver { io };
    } websocket;
    signInErrorCodes signIn();
} // namespace messenger
#endif