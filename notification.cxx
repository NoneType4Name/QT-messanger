#include "notification.hxx"
#include <qnamespace.h>
#include <QWidget>

notificationWidget::notificationWidget( QWidget *parent ) :
    QWidget( parent )
{
    this->setObjectName( "notificationWidget" );
    this->setGeometry( QRect( 40, 20, 200, 100 ) );
    this->move( parentWidget()->width() / 2 - this->width() / 2, parentWidget()->height() / 2 - this->height() / 2 );
    this->setStyleSheet( QString::fromUtf8(
        "*{"
        "color: rgb(255, 255, 255);"
        "background-color: rgb(44, 0, 75);"
        "font: 9pt Cascadia Mono;"
        "outline: none;"
        "border: none;"
        "border-radius:5px;}" ) );
    setAttribute( Qt::WA_StyledBackground );
    verticalLayout = new QVBoxLayout( this );
    verticalLayout->setSpacing( 5 );
    verticalLayout->setObjectName( "verticalLayout" );
    verticalLayout->setContentsMargins( 10, 5, 10, 5 );
    text = new QLabel( this );
    text->setObjectName( "text" );
    QSizePolicy sizePolicy( QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding );
    sizePolicy.setHorizontalStretch( 0 );
    sizePolicy.setVerticalStretch( 0 );
    sizePolicy.setHeightForWidth( text->sizePolicy().hasHeightForWidth() );
    text->setSizePolicy( sizePolicy );
    text->setWordWrap( true );
    verticalLayout->addWidget( text );
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing( 0 );
    horizontalLayout->setObjectName( "horizontalLayout" );
    horizontalSpacer = new QSpacerItem( 40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum );
    horizontalLayout->addItem( horizontalSpacer );
    OkButton = new QPushButton( this );
    OkButton->setObjectName( "OkButton" );
    QSizePolicy sizePolicy1( QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum );
    sizePolicy1.setHorizontalStretch( 0 );
    sizePolicy1.setVerticalStretch( 0 );
    sizePolicy1.setHeightForWidth( OkButton->sizePolicy().hasHeightForWidth() );
    OkButton->setSizePolicy( sizePolicy1 );
    OkButton->setCursor( QCursor( Qt::PointingHandCursor ) );
    OkButton->setStyleSheet( QString::fromUtf8( "QPushButton{background-color: rgb(90, 54, 116);}" ) );
    horizontalLayout->addWidget( OkButton );
    horizontalSpacer1 = new QSpacerItem( 40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum );
    horizontalLayout->addItem( horizontalSpacer1 );
    verticalLayout->addLayout( horizontalLayout );
    text->setText( "Description" );
    OkButton->setText( "OK" );
    QMetaObject::connectSlotsByName( this );
    for ( auto wdg : parent->findChildren<QWidget *>() )
    {
        auto p { this->parent() };
        if ( wdg != this && wdg->parent() != this )
            wdg->setEnabled( 0 );
    }
    show();
}

notificationWidget::~notificationWidget()
{
}

void notificationWidget::on_OkButton_clicked()
{
    for ( auto wdg : this->parent()->findChildren<QWidget *>() )
        wdg->setEnabled( 1 );
    delete this;
}
