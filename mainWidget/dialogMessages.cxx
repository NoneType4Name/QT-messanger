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
    QSizePolicy sizePolicy( QSizePolicy::Policy::Ignored,
                            QSizePolicy::Policy::Preferred );
    sizePolicy.setHorizontalStretch( 0 );
    sizePolicy.setVerticalStretch( 0 );
    centralWidgetHorizontalLayout = new QHBoxLayout( this );
    centralWidgetHorizontalLayout->setSpacing( 0 );
    centralWidgetHorizontalLayout->setObjectName( "centralWidgetHorizontalLayout" );
    centralWidgetHorizontalLayout->setContentsMargins( 0, 0, 0, 0 );
    authorWidget = new QWidget( this );
    authorWidget->setObjectName( "authorWidget" );
    authorWidget->setMinimumSize( QSize( 33, 0 ) );
    authorWidget->setMaximumSize( QSize( 33, 16777215 ) );
    author = new QVBoxLayout( authorWidget );
    author->setSpacing( 0 );
    author->setObjectName( "author" );
    author->setContentsMargins( 0, 0, 0, 0 );
    verticalSpacer = new QSpacerItem( 20, 40, QSizePolicy::Policy::Minimum,
                                      QSizePolicy::Policy::Expanding );

    author->addItem( verticalSpacer );

    icon = new QLabel( authorWidget );
    icon->setObjectName( "icon" );
    QSizePolicy sizePolicy1( QSizePolicy::Policy::Maximum,
                             QSizePolicy::Policy::Maximum );
    sizePolicy1.setHorizontalStretch( 0 );
    sizePolicy1.setVerticalStretch( 0 );
    sizePolicy1.setHeightForWidth( icon->sizePolicy().hasHeightForWidth() );
    icon->setSizePolicy( sizePolicy1 );
    icon->setMinimumSize( QSize( 33, 33 ) );
    icon->setMaximumSize( QSize( 33, 33 ) );
    icon->setStyleSheet(
        QString::fromUtf8( "background-color: rgba(255, 255, 255, 0);" ) );
    icon->setAlignment( Qt::AlignCenter );

    author->addWidget( icon );

    messageBoxWidget = new QWidget( this );
    messageBoxWidget->setObjectName( "messageBoxWidget" );
    messageBox = new QHBoxLayout( messageBoxWidget );
    messageBox->setSpacing( 0 );
    messageBox->setObjectName( "messageBox" );
    messageBox->setContentsMargins( 0, 0, 0, 0 );
    messageWidget = new QWidget( messageBoxWidget );
    messageWidget->setObjectName( "messageWidget" );
    message = new QVBoxLayout( messageWidget );
    message->setSpacing( 0 );
    message->setObjectName( "message" );
    message->setContentsMargins( 0, 0, 0, 0 );
    QSizePolicy sizePolicy2( QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding );
    sizePolicy2.setHorizontalStretch( 0 );
    sizePolicy2.setVerticalStretch( 0 );
    QSizePolicy sizePolicy3( QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Maximum );
    sizePolicy3.setHorizontalStretch( 0 );
    sizePolicy3.setVerticalStretch( 0 );

    std::stringstream ss( text );
    std::string token;
    size_t i { 0 };
    while ( std::getline( ss, token, '\n' ) )
    {
        texts.emplace_back( new dialogMessageWidgetTextLabel( messageWidget ) );
        texts.back()->setObjectName( std::string( "text" ) + std::to_string( i++ ) );
        texts.back()->setSizePolicy( sizePolicy3 );
        texts.back()->setCursor( QCursor( Qt::IBeamCursor ) );
        texts.back()->setTextInteractionFlags( Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard );
        texts.back()->setStyleSheet( QString::fromUtf8( "QLabel{\
padding:10px;\
padding-bottom: 0px;\
padding-top: 0px;}" ) );
        texts.back()->setWordWrap( false );
        texts.back()->setAlignment( ( i > 0 ? Qt::AlignCenter : Qt::AlignBottom ) | Qt::AlignLeading | ( client ? Qt::AlignLeft : Qt::AlignRight ) );
        texts.back()->setText( token.c_str() );
        message->addWidget( texts.back() );
    }
    if ( i > 1 )
    {
        texts.front()->setSizePolicy( sizePolicy2 );
        texts.front()->setStyleSheet( QString::fromUtf8( "QLabel{\
padding:10px;\
padding-bottom: 0px;\
border-top-right-radius:10px;\
border-top-left-radius:10px;\
border-bottom-right-radius:0px;\
border-bottom-left-radius:0px;" ) );
    }

    data = new QLabel( messageWidget );
    data->setObjectName( "data" );
    sizePolicy3.setHeightForWidth( data->sizePolicy().hasHeightForWidth() );
    data->setSizePolicy( sizePolicy3 );
    data->setMinimumSize( QSize( 0, 24 ) );
    data->setMaximumSize( QSize( 16777215, 24 ) );
    data->setStyleSheet(
        QString::fromUtf8( "padding:5px; border-bottom-right-radius:10px;" ) );
    data->setAlignment( Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter );

    message->addWidget( data );

    data->setStyleSheet( QString::fromUtf8( std::string( "padding-right:2px;padding-bottom:2px;" ) + ( client ? "border-bottom-left-radius:10px;" : "border-bottom-right-radius:10px;" ) ) );
    data->setText( time.c_str() );
    icon->setText( "ico" );

    if ( client )
    {
        centralWidgetHorizontalLayout->addWidget( messageBoxWidget );
        centralWidgetHorizontalLayout->addWidget( authorWidget );
        horizontalSpacer = new QSpacerItem( 40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum );
        messageBox->addItem( horizontalSpacer );
    }
    else
    {
        centralWidgetHorizontalLayout->addWidget( authorWidget );
        centralWidgetHorizontalLayout->addWidget( messageBoxWidget );
        horizontalSpacer = new QSpacerItem( 40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum );
        messageBox->addWidget( messageWidget );
        messageBox->addItem( horizontalSpacer );
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
    // if ( fontMetrics().boundingRect( text() ).width() > event->size().width() )
    // {
    //     resize( event->size().width(), height() );
    //     // parentWidget()->layout().size
    //     setWordWrap( true );
    // }
    QLabel::resizeEvent( event );
}
