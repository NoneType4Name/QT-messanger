#include "dialogsPreviews.hxx"

dialogsPreviews::dialogsPreviews( mainWidget *parent ) :
    QWidget( parent )
{
    setObjectName( "dialogsPreviews" );
    setMinimumWidth( 130 );
    QSizePolicy sizePolicy( QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding );
    setSizePolicy( sizePolicy );
    sizePolicy.setHorizontalStretch( 0 );
    sizePolicy.setVerticalStretch( 0 );
    usersLayout = new QVBoxLayout( this );
    usersLayout->setSpacing( 0 );
    usersLayout->setObjectName( "usersLayout" );
    usersLayout->setContentsMargins( 0, 0, 0, 0 );
    searchBar = new QWidget( this );
    searchBar->setObjectName( "searchBar" );
    searchBar->setFixedHeight( 62 );
    searchBarLayout = new QHBoxLayout( searchBar );
    searchBarLayout->setSpacing( 0 );
    searchBarLayout->setObjectName( "searchBarLayout" );
    settingsOpenButton = new QPushButton( searchBar );
    settingsOpenButton->setObjectName( "settingsOpenButton" );
    settingsOpenButton->setFixedSize( 35, 35 );
    settingsOpenButton->setStyleSheet( QString::fromUtf8( "background-color: rgba(0, 0, 0, 0);\
                                                             color: rgb(255, 255, 255);\
                                                             font-size: 24pt;" ) );

    searchBarLayout->addWidget( settingsOpenButton );

    searchField = new QLineEdit( searchBar );
    searchField->setObjectName( "searchField" );
    sizePolicy.setHeightForWidth( searchField->sizePolicy().hasHeightForWidth() );
    searchField->setSizePolicy( sizePolicy );
    searchField->setFixedHeight( 35 );
    searchField->setStyleSheet( QString::fromUtf8( "QLineEdit{\
                                                      	background-color: rgb(90, 54, 116);\
                                                      	padding-right:10px;\
                                                      	padding-left:10px;\
                                                      	border-radius:17px;}" ) );

    searchBarLayout->addWidget( searchField );

    usersLayout->addWidget( searchBar );

    users = new QListWidget( this );
    users->setObjectName( "users" );
    sizePolicy.setHeightForWidth( users->sizePolicy().hasHeightForWidth() );
    users->setSizePolicy( sizePolicy );
    users->setStyleSheet( QString::fromUtf8( "QListWidget\
                                                {\
                                                	border:none;\
                                                }\
                                                \
                                                QListWidget::item\
                                                {\
                                                	outline: none;\
                                                }\
                                                \
                                                QListWidget::item:hover\
                                                {\
                                                	background-color: rgb(60, 0, 100);\
                                                }\
                                                \
                                                QListWidget::item:selected\
                                                {\
                                                	background-color: rgb(90, 54, 116);\
                                                }" ) );
    users->setDefaultDropAction( Qt::IgnoreAction );
    settingsOpenButton->setText( QCoreApplication::translate( "window", "≡", nullptr ) );
    searchField->setPlaceholderText( QCoreApplication::translate( "window", "Поиск", nullptr ) );
    usersLayout->addWidget( users );
}

dialogPreviewWidget *dialogsPreviews::createPreviewUp( std::string name, std::string lastMessage, std::string lastMessageTime )
{
    auto wdg = new dialogPreviewWidget( users, name, lastMessage, lastMessageTime );
    users->insertItem( 0, "" );
    users->item( 0 )->setSizeHint( QSize( 0, 62 ) );
    users->setItemWidget( users->item( 0 ), wdg );
    wdg->ReadStatys->setText( "ok" );
    return wdg;
}

dialogPreviewWidget *dialogsPreviews::createPreviewDown( std::string name, std::string lastMessage, std::string lastMessageTime )
{
    auto wdg = new dialogPreviewWidget( users, name, lastMessage, lastMessageTime );
    users->insertItem( users->count(), "" );
    users->item( users->count() - 1 )->setSizeHint( QSize( 0, 62 ) );
    users->setItemWidget( users->item( users->count() - 1 ), wdg );
    wdg->ReadStatys->setText( "ok" );
    return wdg;
}

dialogsPreviews::~dialogsPreviews()
{
}

dialogPreviewWidget::dialogPreviewWidget( QListWidget *parent, std::string name, std::string lastMessage, std::string lastMessageTime ) :
    QWidget( parent )
{
    setObjectName( "dialogPreviewWidget" );
    setFixedHeight( 62 );
    QFont font;
    font.setFamilies( { QString::fromUtf8( "Cascadia Mono" ) } );
    font.setPointSize( 20 );
    font.setBold( false );
    font.setItalic( false );
    setFont( font );
    setCursor( QCursor( Qt::PointingHandCursor ) );
    verticalLayout_2 = new QVBoxLayout( this );
    verticalLayout_2->setObjectName( "verticalLayout_2" );
    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setObjectName( "horizontalLayout_3" );
    Avatar = new QLabel( this );
    Avatar->setObjectName( "Avatar" );
    Avatar->setFixedSize( 46, 46 );
    Avatar->setStyleSheet( QString::fromUtf8( "QLabel\
                                              {\
                                                background-color: rgba(255, 255, 255, 0);\
                                              }" ) );
    Avatar->setAlignment( Qt::AlignmentFlag::AlignCenter );

    horizontalLayout_3->addWidget( Avatar );

    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName( "verticalLayout" );
    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName( "horizontalLayout_2" );
    UserName = new QLabel( this );
    UserName->setObjectName( "UserName" );
    QSizePolicy sizePolicy( QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred );
    sizePolicy.setHorizontalStretch( 0 );
    sizePolicy.setVerticalStretch( 0 );
    UserName->setSizePolicy( sizePolicy );
    UserName->setFixedHeight( 16 );
    UserName->setStyleSheet( QString::fromUtf8( "QLabel\
                                                {\
                                                    background-color: rgba(255, 255, 255, 0);\
                                                }" ) );
    UserName->setAlignment( Qt::AlignmentFlag::AlignLeading | Qt::AlignmentFlag::AlignLeft | Qt::AlignmentFlag::AlignVCenter );

    horizontalLayout_2->addWidget( UserName );

    horizontalSpacer_2 = new QSpacerItem( 40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum );

    horizontalLayout_2->addItem( horizontalSpacer_2 );

    ReadStatys = new QLabel( this );
    ReadStatys->setObjectName( "ReadStatys" );
    ReadStatys->setFixedSize( 18, 10 );
    ReadStatys->setStyleSheet( QString::fromUtf8( "QLabel\
                                                  {\
                                                  	background-color: rgba(255, 255, 255, 0);\
                                                  }" ) );
    ReadStatys->setAlignment( Qt::AlignmentFlag::AlignCenter );

    horizontalLayout_2->addWidget( ReadStatys );

    DialogTime = new QLabel( this );
    DialogTime->setObjectName( "DialogTime" );
    DialogTime->setFixedSize( 32, 10 );
    DialogTime->setStyleSheet( QString::fromUtf8( "QLabel\
                                                  {\
                                                  	background-color: rgba(255, 255, 255, 0);\
                                                  }" ) );
    DialogTime->setAlignment( Qt::AlignmentFlag::AlignCenter );

    horizontalLayout_2->addWidget( DialogTime );

    verticalLayout->addLayout( horizontalLayout_2 );

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName( "horizontalLayout" );
    LastMessage = new QLabel( this );
    LastMessage->setObjectName( "LastMessage" );
    LastMessage->setSizePolicy( sizePolicy );
    LastMessage->setFixedHeight( 16 );
    LastMessage->setStyleSheet( QString::fromUtf8( "QLabel\
                                                   {\
                                                   	background-color: rgba(255, 255, 255, 0);\
                                                   }" ) );
    LastMessage->setAlignment( Qt::AlignmentFlag::AlignLeading | Qt::AlignmentFlag::AlignLeft | Qt::AlignmentFlag::AlignVCenter );

    horizontalLayout->addWidget( LastMessage );

    horizontalSpacer = new QSpacerItem( 40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum );

    horizontalLayout->addItem( horizontalSpacer );

    DialogStatus = new QLabel( this );
    DialogStatus->setObjectName( "DialogStatus" );
    DialogStatus->setFixedSize( 16, 16 );
    DialogStatus->setStyleSheet( QString::fromUtf8( "QLabel\
                                                    {\
                                                    	background-color: rgba(255, 255, 255, 0);\
                                                    }" ) );
    DialogStatus->setAlignment( Qt::AlignmentFlag::AlignCenter );

    horizontalLayout->addWidget( DialogStatus );

    verticalLayout->addLayout( horizontalLayout );

    horizontalLayout_3->addLayout( verticalLayout );

    verticalLayout_2->addLayout( horizontalLayout_3 );

    Avatar->setText( QCoreApplication::translate( "window", "IMAGE", nullptr ) );
    UserName->setText( QCoreApplication::translate( "window", name.c_str(), nullptr ) );
    ReadStatys->setText( QCoreApplication::translate( "window", "ok", nullptr ) );
    LastMessage->setText( QCoreApplication::translate( "window", lastMessage.c_str(), nullptr ) );
    DialogTime->setText( QCoreApplication::translate( "window", lastMessageTime.c_str(), nullptr ) );
    DialogStatus->setText( QCoreApplication::translate( "window", "N", nullptr ) );
}

dialogPreviewWidget::~dialogPreviewWidget()
{
}