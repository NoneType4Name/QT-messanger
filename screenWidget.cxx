#include "messenger.hxx"
#include <qlogging.h>
#include "screenWidget.hxx"
#include <future>

screenWidget::screenWidget( QWidget *parent ) :
    QStackedWidget( parent )
{
    if ( objectName().isEmpty() )
        setObjectName( "screenWidget" );
    QSizePolicy sizePolicy( QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed );
    sizePolicy.setHorizontalStretch( 0 );
    sizePolicy.setVerticalStretch( 0 );
    sizePolicy.setHeightForWidth( this->sizePolicy().hasHeightForWidth() );
    setSizePolicy( sizePolicy );
    setStyleSheet( QString::fromUtf8( "background-color: rgb(0, 0, 0);" ) );
    setWindowTitle( "QT-messanger" );
    resize( 800, 600 );
    this->addWidget( auth = new authWidget( this ) );
    this->addWidget( this->mainWidget = new class mainWidget( this ) );
    init();
}

screenWidget::~screenWidget()
{
}

void screenWidget::init()
{
    auth->registration = !messenger::configsPath.exists( "user.json" );
    while ( 1 )
    {
        if ( auth->registration )
        {
            setCurrentWidget( auth );
        }
        auto f { std::async( &messenger::signIn ) };
        uint32_t c { 0 };
        while ( f.wait_for( std::chrono::seconds( 0 ) ) != std::future_status::ready )
        {
            ++c;
            if ( !( c ) )
            {
                auth->enterButton->setText( "." );
            }
            else if ( !( c % 900 ) )
                c = 0;
            else if ( c % 100 == 3 || c % 100 == 6 )
                auth->enterButton->setText( auth->enterButton->text() + "." );
        }
        auto data { f.get() };
        if ( !data )
        {
            setCurrentWidget( mainWidget );
            return;
        }
        else
        {
            qDebug() << "Error SignIn: " << data << '\n';
            auth->registration = 1;
        }
    }
}