#include "mainWidget.hxx"
#include "../screenWidget.hxx"

mainWidget::mainWidget( screenWidget *screen, QMainWindow *parent ) :
    screen( screen ),
    QMainWindow( parent )
{
    centralwidget = new QWidget( this );
    centralwidget->setObjectName( "centralwidget" );
    centralwidget->setStyleSheet( QString::fromUtf8( "*\
                                                         {\
                                                         	background-color: rgb(44, 0, 75);\
                                                         	color: rgb(255, 255, 255);\
                                                         	font: 9pt \"Cascadia Mono\";\
                                                         	outline: none;\
                                                         	border: none;\
                                                         	selection-background-color: rgb(81, 0, 135);\
                                                         }\
                                                         \
                                                         QScrollBar:vertical\
                                                         {\
                                                             border: 0px solid #999999;\
                                                             background: rgb(70, 70, 70);\
                                                             width:10px;    \
                                                         	margin: 0px 0px 0px 0px;\
                                                         }\
                                                         \
                                                         QScrollBar::handle:vertical\
                                                         {   \
                                                         	min-height: 0px;\
                                                             border: 0px solid red;\
                                                         	border-radius: 2px;\
                                                         	background-color:grey;\
                                                         	margin: 0px 3px 0px 3px;\
                                                         }\
                                                         \
                                                         QScrollBar::add-line:vertical\
                                                         {\
                                                             height: 0px;\
                                                             subcontrol-position: bottom;\
                                                         	subcontrol-origin: margin;\
                                                         }\
                                                         \
                                                         QScrollBar::sub-line:vertical\
                                                         {\
                                                         	height: 0 px;\
                                                             subcontrol-position: top;\
                                                             subcontrol-origin: margin;\
                                                         }\
                                                         \
                                                         QScrollBar::sub-page:vertical\
                                                         {\
                                                         	background: none;\
                                                         }\
                                                         \
                                                         QScrollBar::add-page:vertical\
                                                         {\
                                                         	background: none;\
                                                         }" ) );
    mainLayout = new QHBoxLayout( centralwidget );
    mainLayout->setSpacing( 0 );
    mainLayout->setObjectName( "mainLayout" );
    mainLayout->setContentsMargins( 0, 0, 0, 0 );

    splitter = new QSplitter();
    splitter->addWidget( previews = new dialogsPreviews( this ) );
    splitter->addWidget( messages = new dialogMessages( this ) );
    mainLayout->addWidget( splitter );
    setCentralWidget( centralwidget );
}

mainWidget::~mainWidget()
{
}