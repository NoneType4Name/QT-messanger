#include "signINwidget.h"
#include "pages.h"

signINWidget::signINWidget( QStackedWidget &screen, QWidget *parent ) :
    screen( screen ), QMainWindow( parent )
{
    if ( objectName().isEmpty() )
        setObjectName( "MainWindow" );
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

    lineEdit_2 = new QLineEdit( centralwidget );
    lineEdit_2->setObjectName( "lineEdit_2" );
    lineEdit_2->setStyleSheet( QString::fromUtf8( "QLineEdit\n"
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
    lineEdit_2->setMaxLength( 255 );
    lineEdit_2->setAlignment( Qt::AlignCenter );

    verticalLayout->addWidget( lineEdit_2 );

    lineEdit = new QLineEdit( centralwidget );
    lineEdit->setObjectName( "lineEdit" );
    QSizePolicy sizePolicy2( QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred );
    sizePolicy2.setHorizontalStretch( 0 );
    sizePolicy2.setVerticalStretch( 0 );
    sizePolicy2.setHeightForWidth( lineEdit->sizePolicy().hasHeightForWidth() );
    lineEdit->setSizePolicy( sizePolicy2 );
    lineEdit->setTabletTracking( false );
    lineEdit->setAcceptDrops( false );
    lineEdit->setAutoFillBackground( false );
    lineEdit->setStyleSheet( QString::fromUtf8( "QLineEdit\n"
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
    lineEdit->setText( QString::fromUtf8( "" ) );
    lineEdit->setMaxLength( 255 );
    lineEdit->setFrame( false );
    lineEdit->setEchoMode( QLineEdit::Password );
    lineEdit->setAlignment( Qt::AlignCenter );
    lineEdit->setClearButtonEnabled( false );

    verticalLayout->addWidget( lineEdit );

    pushButton = new QPushButton( centralwidget );
    pushButton->setObjectName( "pushButton" );
    sizePolicy2.setHeightForWidth( pushButton->sizePolicy().hasHeightForWidth() );
    pushButton->setSizePolicy( sizePolicy2 );
    pushButton->setCursor( QCursor( Qt::PointingHandCursor ) );
    pushButton->setStyleSheet( QString::fromUtf8( "QPushButton{\n"
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

    verticalLayout->addWidget( pushButton );

    verticalSpacer_2 = new QSpacerItem( 20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding );

    verticalLayout->addItem( verticalSpacer_2 );

    horizontalLayout->addLayout( verticalLayout );

    horizontalSpacer_2 = new QSpacerItem( 40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum );

    horizontalLayout->addItem( horizontalSpacer_2 );

    verticalLayout_2->addLayout( horizontalLayout );

    auto goToRegister = new QPushButton( centralwidget );
    goToRegister->setObjectName( "goToRegister" );
    QSizePolicy gtrSizePolicy( QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred );
    gtrSizePolicy.setHorizontalStretch( 0 );
    gtrSizePolicy.setVerticalStretch( 0 );
    gtrSizePolicy.setHeightForWidth( goToRegister->sizePolicy().hasHeightForWidth() );
    goToRegister->setSizePolicy( gtrSizePolicy );
    QFont gtrFont;
    gtrFont.setFamilies( { QString::fromUtf8( "Cascadia Mono" ) } );
    gtrFont.setPointSize( 18 );
    goToRegister->setFont( gtrFont );
    goToRegister->setStyleSheet( QString::fromUtf8(
        "QPushButton{"
        "color: rgb(255, 255, 255);\n"
        "background-color: rgba(255, 255, 255, 0);\n"
        "}\n"
        "QPushButton:hover{\n"
        "color: rgb(125, 0, 255);\n"
        "}\n" ) );
    goToRegister->setCursor( QCursor( Qt::PointingHandCursor ) );
    // goToRegister->setAlignment( Qt::AlignCenter );

    verticalLayout->addWidget( goToRegister );

    goToRegister->setText( "Еще не зарегистрированы?" );

    setWindowTitle( "QT-messanger" );
    label->setText( "С возвращением!~" );
    lineEdit_2->setPlaceholderText( "♥ Введите логин" );
    lineEdit->setPlaceholderText( "Пароль ◕‿◕" );
    pushButton->setText( "Авторизоваться ♥" );

    setCentralWidget( centralwidget );

    QMetaObject::connectSlotsByName( this );
}

signINWidget::~signINWidget()
{
}

void signINWidget::on_pushButton_clicked()
{
    qDebug() << lineEdit_2->text() << "\t" << lineEdit->text() << "\n";
}

void signINWidget::on_goToRegister_clicked()
{
    screen.setCurrentIndex( RegisterPage );
}
