#include "dialogMessages.hxx"
#include <sstream>
#include <QDebug>

dialogMessages::dialogMessages( mainWidget *parent ) :
    QWidget( parent )
{
    setObjectName( "dialogMessages" );
    QSizePolicy sizePolicy( QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding );
    sizePolicy.setHorizontalStretch( 0 );
    sizePolicy.setVerticalStretch( 0 );
    setSizePolicy( sizePolicy );
    dialogLayout = new QVBoxLayout( this );
    dialogLayout->setSpacing( 0 );
    dialogLayout->setObjectName( "dialogLayout" );
    dialogLayout->setContentsMargins( 0, 0, 0, 0 );
    dialogProfile = new QWidget( this );
    dialogProfile->setObjectName( "dialogeProfile" );
    dialogProfile->setFixedHeight( 62 );

    dialogLayout->addWidget( dialogProfile );

    dialog = new QTableWidget( this );
    if ( dialog->columnCount() < 2 )
        dialog->setColumnCount( 2 );
    QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
    __qtablewidgetitem->setTextAlignment( Qt::AlignTrailing | Qt::AlignVCenter );
    dialog->setHorizontalHeaderItem( 0, __qtablewidgetitem );
    QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
    __qtablewidgetitem1->setTextAlignment( Qt::AlignLeading | Qt::AlignVCenter );
    dialog->setHorizontalHeaderItem( 1, __qtablewidgetitem1 );
    dialog->setObjectName( "dialog" );
    sizePolicy.setHeightForWidth( dialog->sizePolicy().hasHeightForWidth() );
    dialog->setSizePolicy( sizePolicy );
    QFont font;
    font.setFamilies( { QString::fromUtf8( "Cascadia Mono" ) } );
    font.setPointSize( 9 );
    font.setBold( false );
    font.setItalic( false );
    dialog->setFont( font );
    dialog->setStyleSheet( QString::fromUtf8( "QTableWidget\
                                                  {\
                                                  	background-color: rgb(45, 27, 75);\
                                                  	border: none;\
                                                  	outline:none;\
                                                  }\
                                                  \
                                                  QTableWidget::item\
                                                  {\
                                                  	border: none;}" ) );
    dialog->setSizeAdjustPolicy( QAbstractScrollArea::AdjustToContents );
    dialog->setEditTriggers( QAbstractItemView::NoEditTriggers );
    dialog->setTabKeyNavigation( false );
    dialog->setSelectionMode( QAbstractItemView::NoSelection );
    dialog->setShowGrid( false );
    dialog->setColumnCount( 2 );
    dialog->horizontalHeader()->setVisible( false );
    dialog->verticalHeader()->setVisible( false );
    dialog->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
    dialog->verticalHeader()->setSectionResizeMode( QHeaderView::ResizeToContents );
    dialog->setSortingEnabled( false );

    dialogLayout->addWidget( dialog );

    messageBar = new QHBoxLayout();
    messageBar->setSpacing( 0 );
    messageBar->setObjectName( "messageBar" );
    appendMedia = new QPushButton( this );
    appendMedia->setObjectName( "appendMedia" );
    appendMedia->setFixedSize( 46, 46 );
    appendMedia->setCursor( QCursor( Qt::PointingHandCursor ) );
    appendMedia->setStyleSheet( QString::fromUtf8( "background-color: rgba(255, 255, 255, 0);" ) );

    messageBar->addWidget( appendMedia );

    writeMessage = new QLineEdit( this );
    writeMessage->setObjectName( "writeMessage" );
    writeMessage->setFixedHeight( 46 );
    writeMessage->setStyleSheet( QString::fromUtf8( "QLineEdit{border:none;}" ) );

    messageBar->addWidget( writeMessage );

    voiceRecord = new QPushButton( this );
    voiceRecord->setObjectName( "voiceRecord" );
    voiceRecord->setFixedSize( 46, 46 );
    voiceRecord->setCursor( QCursor( Qt::PointingHandCursor ) );
    voiceRecord->setStyleSheet( QString::fromUtf8( "background-color: rgba(255, 255, 255, 0);" ) );

    messageBar->addWidget( voiceRecord );

    dialogLayout->addLayout( messageBar );
    appendMedia->setText( QCoreApplication::translate( "window", "файл", nullptr ) );
    // writeMessage->setText( QString() );
    writeMessage->setPlaceholderText( QCoreApplication::translate( "window", "Написать сообщение...", nullptr ) );
    voiceRecord->setText( QCoreApplication::translate( "window", "Петь тут", nullptr ) );
}

dialogMessages::~dialogMessages()
{
}

dialogMessageWidget *dialogMessages::createMessageUp( std::string message, std::string time, bool client )
{
    dialog->insertRow( 0 );
    auto wdg = new dialogMessageWidget( dialog, message, time, client );
    dialog->setCellWidget( 0, client, wdg );
    return wdg;
}

dialogMessageWidget *dialogMessages::createMessageDown( std::string message, std::string time, bool client )
{
    dialog->insertRow( dialog->rowCount() );
    auto wdg = new dialogMessageWidget( dialog, message, time, client );
    dialog->setCellWidget( dialog->rowCount() - 1, client, wdg );
    return wdg;
}

dialogMessageWidget::dialogMessageWidget( QTableWidget *parent, std::string text, std::string time, bool client ) :
    QWidget( parent )
{
    setObjectName( "dialogMessageWidget" );
    horizontalLayout = new QHBoxLayout( this );
    horizontalLayout->setObjectName( "horizontalLayout" );
    autor = new QVBoxLayout();
    autor->setSpacing( 0 );
    autor->setObjectName( "autor" );
    verticalSpacer = new QSpacerItem( 0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::MinimumExpanding );

    autor->addItem( verticalSpacer );

    icon = new QLabel( this );
    icon->setObjectName( "icon" );
    QSizePolicy sizePolicy( QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding );
    QSizePolicy sizePolicy1( QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred );
    sizePolicy.setHorizontalStretch( 0 );
    sizePolicy.setVerticalStretch( 0 );
    sizePolicy1.setHorizontalStretch( 0 );
    sizePolicy1.setVerticalStretch( 0 );
    icon->setFixedSize( 33, 33 );
    icon->setStyleSheet( QString::fromUtf8( "background-color: rgba(255, 255, 255, 0);" ) );

    autor->addWidget( icon );

    message = new QVBoxLayout();
    message->setSpacing( 0 );
    message->setObjectName( "message" );
    std::stringstream ss( text );
    std::string token;
    size_t i { 0 };
    while ( std::getline( ss, token, '\n' ) )
    {
        texts.emplace_back( new dialogMessageWidgetTextLabel( this ) );
        texts.back()->setObjectName( std::string( "text" ) + std::to_string( i++ ) );
        texts.back()->setSizePolicy( sizePolicy1 );
        texts.back()->setCursor( QCursor( Qt::IBeamCursor ) );
        texts.back()->setTextInteractionFlags( Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard );
        texts.back()->setWordWrap( false );
        texts.back()->setStyleSheet( QString::fromUtf8( "QLabel{\
                                                            padding:10px;\
                                                            border-top-right-radius:10px;\
                                                            border-top-left-radius:10px;\
                                                            border-bottom-right-radius:0px;\
                                                            border-bottom-left-radius:0px;}" ) );
        message->addWidget( texts.back() );
        texts.back()->setText( token.c_str() );
    }
    if ( i > 1 )
        texts.front()->setSizePolicy( sizePolicy );

    data = new QLabel( this );
    data->setObjectName( "data" );
    data->setSizePolicy( sizePolicy1 );
    data->setAlignment( Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter );

    message->addWidget( data );

    data->setStyleSheet( QString::fromUtf8( std::string( "padding-right:2px;padding-bottom:2px;" ) + ( client ? "border-bottom-left-radius:10px;" : "border-bottom-right-radius:10px;" ) ) );
    data->setText( time.c_str() );
    icon->setText( "ico" );

    if ( client )
    {
        horizontalLayout->addItem( new QSpacerItem( 10, 10, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum ) );
        horizontalLayout->addLayout( message );
        horizontalLayout->addLayout( autor );
        for ( const auto t : texts )
            t->setAlignment( Qt::AlignBottom | Qt::AlignRight );
    }
    else
    {
        horizontalLayout->addLayout( autor );
        horizontalLayout->addLayout( message );
        horizontalLayout->addItem( new QSpacerItem( 10, 10, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum ) );
        for ( const auto t : texts )
            t->setAlignment( Qt::AlignBottom | Qt::AlignLeft );
    }
}

dialogMessageWidget::~dialogMessageWidget()
{
}

dialogMessageWidgetTextLabel::dialogMessageWidgetTextLabel( QWidget *parent ) :
    QLabel( parent )
{
}
dialogMessageWidgetTextLabel::~dialogMessageWidgetTextLabel()
{
}

void dialogMessageWidgetTextLabel::resizeEvent( QResizeEvent *event )
{
    if ( fontMetrics().boundingRect( text() ).width() > event->size().width() )
    {
        resize( event->size().width(), height() );
        setWordWrap( true );
    }
    QLabel::resizeEvent( event );
}
