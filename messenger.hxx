#pragma once
#include <boost/asio/ip/tcp.hpp>
#ifndef MESSENGER_HXX
#    define MESSENGER_HXX
#    include <QDir>
#    include <boost/beast.hpp>
#    include <boost/json.hpp>
namespace messenger
{
    enum struct signInErrorCodes
    {
        Ok = 0,
        ServerError,
        WrongData,
        TooManyTries,
        AuthTimeOut,
        WrongAuthData,
        WrongAuthLogin,
        EmptyData,
        TimeOut,
    };
    enum struct serverAnswers
    {
        Ok = 0,
        ServerError,
        WrongData,
        TooManyTries,
        AuthTimeOut,
        WrongAuthData,
        WrongAuthLogin,
    };

    extern QDir configsPath;
    extern boost::asio::io_context io;
    extern struct websocket_T : public boost::beast::websocket::stream<boost::asio::ip::tcp::socket>
    {
        websocket_T();
        ~websocket_T();
        boost::asio::ip::tcp::endpoint connect();
        boost::asio::ip::tcp::resolver resolver { io };
    } websocket;
    signInErrorCodes signIn();
    signInErrorCodes signUp( std::string_view login, std::string_view password );
} // namespace messenger
#endif