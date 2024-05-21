#include "authWidget.hxx"
#include "screenWidget.hxx"

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
    auth = new authWidget( this );

    this->addWidget( auth );
}

screenWidget::~screenWidget()
{
}
