#include "authWidget.hxx"
#include "messenger.hxx"
#include "screenWidget.hxx"
#include <boost/json/object.hpp>
#include <boost/json/serialize.hpp>
#include <QMetaObject>
#include <qcontainerfwd.h>
#include <qdir.h>

authWidget::authWidget( screenWidget *screen, QWidget *parent ) :
    screen( screen ),
    QMainWindow( parent )
{
    if ( objectName().isEmpty() )
        setObjectName( "authWidget" );
    QSizePolicy sizePolicy( QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed );
    sizePolicy.setHorizontalStretch( 0 );
    sizePolicy.setVerticalStretch( 0 );
    sizePolicy.setHeightForWidth( this->sizePolicy().hasHeightForWidth() );
    setSizePolicy( sizePolicy );
    setStyleSheet( QString::fromUtf8( "background-color: rgb(0, 0, 0);" ) );
    centralwidget = new QWidget( this );
    centralwidget->setObjectName( "centralwidget" );
    verticalLayout_2 = new QVBoxLayout( centralwidget );
    verticalLayout_2->setObjectName( "verticalLayout_2" );
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName( "horizontalLayout" );
    horizontalSpacer = new QSpacerItem( 40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum );

    horizontalLayout->addItem( horizontalSpacer );

    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName( "verticalLayout" );
    verticalSpacer = new QSpacerItem( 20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding );

    verticalLayout->addItem( verticalSpacer );

    label = new QLabel( centralwidget );
    label->setObjectName( "label" );
    QSizePolicy sizePolicy1( QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred );
    sizePolicy1.setHorizontalStretch( 0 );
    sizePolicy1.setVerticalStretch( 0 );
    sizePolicy1.setHeightForWidth( label->sizePolicy().hasHeightForWidth() );
    label->setSizePolicy( sizePolicy1 );
    QFont font;
    font.setFamilies( { QString::fromUtf8( "Cascadia Mono" ) } );
    font.setPointSize( 18 );
    label->setFont( font );
    label->setStyleSheet( QString::fromUtf8(
        "color: rgb(255, 255, 255);\n"
        "background-color: rgba(255, 255, 255, 0);\n"
        "padding: 5px;" ) );
    label->setAlignment( Qt::AlignCenter );

    verticalLayout->addWidget( label );

    login = new QLineEdit( centralwidget );
    login->setObjectName( "login" );
    login->setStyleSheet( QString::fromUtf8( "QLineEdit\n"
                                             "{\n"
                                             "	font: 18pt \"Cascadia Mono\";\n"
                                             "	color: rgb(255, 255, 255);\n"
                                             "	border-radius:10px;\n"
                                             "	border: 2px solid rgb(125, 0, 255);\n"
                                             "  padding: 5px;\n"
                                             "}\n"
                                             "\n"
                                             "QLineEdit:focus\n"
                                             "{\n"
                                             "	border-color: rgb(255, 255, 255);\n"
                                             "}" ) );
    login->setMaxLength( 255 );
    login->setAlignment( Qt::AlignCenter );

    verticalLayout->addWidget( login );

    password = new QLineEdit( centralwidget );
    password->setObjectName( "password" );
    password->setSizePolicy( sizePolicy1 );
    password->setTabletTracking( false );
    password->setAcceptDrops( false );
    password->setAutoFillBackground( false );
    password->setStyleSheet( QString::fromUtf8( "QLineEdit\n"
                                                "{\n"
                                                "	font: 18pt \"Cascadia Mono\";\n"
                                                "	color: rgb(255, 255, 255);\n"
                                                "	border-radius:10px;\n"
                                                "	border: 2px solid rgb(125, 0, 255);\n"
                                                "   padding: 5px;\n"
                                                "}\n"
                                                "\n"
                                                "QLineEdit:focus\n"
                                                "{\n"
                                                "	border-color: rgb(255, 255, 255);\n"
                                                "}" ) );
    password->setText( QString::fromUtf8( "" ) );
    password->setMaxLength( 255 );
    password->setFrame( false );
    password->setEchoMode( QLineEdit::Password );
    password->setAlignment( Qt::AlignCenter );
    password->setClearButtonEnabled( false );

    verticalLayout->addWidget( password );

    enterButton = new QPushButton( centralwidget );
    enterButton->setObjectName( "enterButton" );
    enterButton->setSizePolicy( sizePolicy1 );
    enterButton->setCursor( QCursor( Qt::PointingHandCursor ) );
    enterButton->setStyleSheet( QString::fromUtf8( "QPushButton{\n"
                                                   "	background-color: rgb(125, 0, 255);\n"
                                                   "	font: 18pt \"Cascadia Mono\";\n"
                                                   "	color: rgb(255, 255, 255);\n"
                                                   "	border-radius: 10px;\n"
                                                   "    padding: 5px;\n"
                                                   "}\n"
                                                   "\n"
                                                   "QPushButton:hover, QPushButton:focus\n"
                                                   "{	\n"
                                                   "	background-color: rgb(86, 0, 177);\n"
                                                   "}\n"
                                                   "\n"
                                                   "QPushButton:focus\n"
                                                   "{\n"
                                                   "	outline: none;\n"
                                                   "	border: 1px solid rgb(255, 255, 255);\n"
                                                   "}" ) );

    verticalLayout->addWidget( enterButton );

    verticalSpacer_2 = new QSpacerItem( 20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding );

    verticalLayout->addItem( verticalSpacer_2 );

    horizontalLayout->addLayout( verticalLayout );

    horizontalSpacer_2 = new QSpacerItem( 40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum );

    horizontalLayout->addItem( horizontalSpacer_2 );

    verticalLayout_2->addLayout( horizontalLayout );

    referenceButton = new QPushButton( centralwidget );
    referenceButton->setObjectName( "referenceButton" );
    QSizePolicy gtrSizePolicy( QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred );
    gtrSizePolicy.setHorizontalStretch( 0 );
    gtrSizePolicy.setVerticalStretch( 0 );
    gtrSizePolicy.setHeightForWidth( referenceButton->sizePolicy().hasHeightForWidth() );
    referenceButton->setSizePolicy( gtrSizePolicy );
    QFont gtrFont;
    gtrFont.setFamilies( { QString::fromUtf8( "Cascadia Mono" ) } );
    gtrFont.setPointSize( 18 );
    referenceButton->setFont( gtrFont );
    referenceButton->setStyleSheet( QString::fromUtf8(
        "QPushButton{"
        "color: rgb(255, 255, 255);\n"
        "background-color: rgba(255, 255, 255, 0);\n"
        "}\n"
        "QPushButton:hover{\n"
        "color: rgb(125, 0, 255);\n"
        "}\n" ) );
    referenceButton->setCursor( QCursor( Qt::PointingHandCursor ) );

    verticalLayout->addWidget( referenceButton );
    login->setPlaceholderText( "♥ Введите логин" );
    password->setPlaceholderText( "Пароль ◕‿◕" );
    restore();
    setCentralWidget( centralwidget );

    QMetaObject::connectSlotsByName( this );
}

authWidget::~authWidget()
{
    // if ( screen->auth_thread )
    //     screen->auth_thread->join();
}

void authWidget::auth()
{
    // auto f { std::async( &messenger::signIn ) };
    // uint32_t c { 0 };
    // QMetaObject::invokeMethod( this, "updateLoadText", Qt::QueuedConnection, Q_ARG( QString, "." ) );
    // while ( f.wait_for( std::chrono::seconds( 0 ) ) != std::future_status::ready )
    // {
    //     ++c;
    //     if ( !( c % 900 ) )
    //     {
    //         QMetaObject::invokeMethod( this, "updateLoadText", Qt::QueuedConnection, Q_ARG( QString, "." ) );
    //         c = 0;
    //     }
    //     else if ( c == 300 )
    //         QMetaObject::invokeMethod( this, "updateLoadText", Qt::QueuedConnection, Q_ARG( QString, ".." ) );
    //     else if ( c == 600 )
    //         QMetaObject::invokeMethod( this, "updateLoadText", Qt::QueuedConnection, Q_ARG( QString, "..." ) );
    // }
    messenger::signInErrorCodes answ;
    if ( registration )
        answ = messenger::signUp( login->text().toStdString(), password->text().toStdString() );
    else
        answ = messenger::signIn();
    if ( answ == messenger::signInErrorCodes::Ok )
    {
        screen->setCurrentWidget( screen->mainWidget );
        // mainWidget->reload();
    }
    else
    {
        qDebug() << "Error SignIn: " << static_cast<int>( answ ) << '\n';
        registration = 1;
    }
    // screen->auth_thread = nullptr;
}

void authWidget::restore()
{
    if ( registration )
    {
        label->setText( "Регистрация\n\nДобро пожаловать!~" );
        enterButton->setText( "Зарегестрироваться ♥" );
        referenceButton->setText( "Уже есть аккаунт?" );
    }
    else
    {
        label->setText( "Вход\n\nС возвращением!~" );
        enterButton->setText( "Авторизоваться ♥" );
        referenceButton->setText( "Ещё нет аккаунта?" );
    }
}

void authWidget::saveLoginData()
{
    QFile file { messenger::configsPath.absoluteFilePath( "user.json" ) };
    file.open( QIODevice::WriteOnly | QIODevice::Text );
    boost::json::object f = { { "login", login->text().toStdString() }, { "password", password->text().toStdString() } };
    file.write( boost::json::serialize( f ).data() );
    file.close();
}

void authWidget::on_enterButton_clicked()
{
    if ( registration )
        saveLoginData();
    // if ( screen->auth_thread )
    // {
    //     screen->auth_thread->join();
    //     delete screen->auth_thread;
    // }
    // screen->auth_thread = new std::thread { [ & ]()
    screen->auth->auth();
}

void authWidget::on_referenceButton_clicked()
{
    registration = !registration;
    restore();
}

// void authWidget::updateLoadText( QString s )
// {
//     enterButton->setText( s );
// }
