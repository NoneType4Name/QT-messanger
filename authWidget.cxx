#include "authWidget.hxx"

authWidget::authWidget( screenWidget *screen, QWidget *parent ) :
    screen( screen ), QMainWindow( parent )
{
    if ( objectName().isEmpty() )
        setObjectName( "authWidget" );
    resize( 800, 600 );
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
    label->setStyleSheet( QString::fromUtf8( "color: rgb(255, 255, 255);\n"
                                             "background-color: rgba(255, 255, 255, 0);" ) );
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
    QSizePolicy sizePolicy2( QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred );
    sizePolicy2.setHorizontalStretch( 0 );
    sizePolicy2.setVerticalStretch( 0 );
    sizePolicy2.setHeightForWidth( password->sizePolicy().hasHeightForWidth() );
    password->setSizePolicy( sizePolicy2 );
    password->setTabletTracking( false );
    password->setAcceptDrops( false );
    password->setAutoFillBackground( false );
    password->setStyleSheet( QString::fromUtf8( "QLineEdit\n"
                                                "{\n"
                                                "	font: 18pt \"Cascadia Mono\";\n"
                                                "	color: rgb(255, 255, 255);\n"
                                                "	border-radius:10px;\n"
                                                "	border: 2px solid rgb(125, 0, 255);\n"
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
    sizePolicy2.setHeightForWidth( enterButton->sizePolicy().hasHeightForWidth() );
    enterButton->setSizePolicy( sizePolicy2 );
    enterButton->setCursor( QCursor( Qt::PointingHandCursor ) );
    enterButton->setStyleSheet( QString::fromUtf8( "QPushButton{\n"
                                                   "	background-color: rgb(125, 0, 255);\n"
                                                   "	font: 18pt \"Cascadia Mono\";\n"
                                                   "	color: rgb(255, 255, 255);\n"
                                                   "	border-radius: 10px;\n"
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
    // goToRegister->setAlignment( Qt::AlignCenter );

    verticalLayout->addWidget( referenceButton );
    login->setPlaceholderText( "♥ Введите логин" );
    password->setPlaceholderText( "Пароль ◕‿◕" );
    reference();
    setCentralWidget( centralwidget );

    QMetaObject::connectSlotsByName( this );
}

authWidget::~authWidget()
{
}

void authWidget::reference()
{
    if ( registration )
    {
        label->setText( "Добро пожаловать!~" );
        enterButton->setText( "Зарегестрироваться ♥" );
        referenceButton->setText( "Уже есть аккаунт?" );
    }
    else
    {
        label->setText( "С возвращением!~" );
        enterButton->setText( "Авторизоваться ♥" );
        referenceButton->setText( "Ещё нет аккаунта?" );
    }
}

void authWidget::on_enterButton_clicked()
{
    if ( registration )
        qDebug() << login->text() << "\t" << password->text() << "\n";
    else
        qDebug() << login->text() << "\t" << password->text() << "\n";
}

void authWidget::on_referenceButton_clicked()
{
    registration = !registration;
    reference();
}
