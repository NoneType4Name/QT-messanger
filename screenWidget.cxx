#include "messenger.hxx"
#include <qlogging.h>
#include "screenWidget.hxx"

screenWidget::screenWidget( QWidget *parent ) :
    QStackedWidget( parent )
{
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
    show();
    init();
}

screenWidget::~screenWidget()
{
}

void screenWidget::init()
{
    if ( !messenger::configsPath.exists( "user.json" ) )
    {
        setCurrentWidget( auth );
        auth->auth();
    }
    else
    {
        auto d { messenger::signIn() };
        if ( d == messenger::signInErrorCodes::Ok )
        {
            setCurrentWidget( mainWidget );
        }
        else
        {
            if ( d == messenger::signInErrorCodes::WrongData || d == messenger::signInErrorCodes::EmptyData )
                messenger::configsPath.remove( "user.json" );
            setCurrentWidget( auth );
            // failed to login
        }
    }
}