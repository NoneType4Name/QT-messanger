#pragma once
#ifndef DIALOGMESSAGE_HXX
#    define DIALOGMESSAGE_HXX
#    include <QtWidgets/QVBoxLayout>
#    include <QtWidgets/QWidget>
#    include <QtWidgets/QTableWidget>
#    include <QtWidgets/QHBoxLayout>
#    include <QtWidgets/QPushButton>
#    include <QtWidgets/QLabel>
#    include <QResizeEvent>
#    include "mainWidget.hxx"

class mainWidget;
class dialogMessageWidget;

class dialogMessages : public QWidget
{
    Q_OBJECT

  private:
    friend mainWidget;
    dialogMessages( mainWidget *parent );
    std::unordered_map<uint64_t, dialogMessageWidget *> _messagesTable;

  public:
    ~dialogMessages();
    QVBoxLayout *dialogLayout;
    QWidget *dialogProfile;
    QTableWidget *dialog;
    QHBoxLayout *messageBar;
    QPushButton *appendMedia;
    QLineEdit *writeMessage;
    QPushButton *voiceRecord;
    dialogMessageWidget *createMessageUp( std::string message, std::string time, bool client );
    dialogMessageWidget *createMessageDown( std::string message, std::string time, bool client );
};

class dialogMessageWidget : public QWidget
{
    Q_OBJECT
  private:
    friend mainWidget;
    friend dialogMessages;
    QHBoxLayout *centralWidgetHorizontalLayout;
    QWidget *authorWidget;
    QVBoxLayout *author;
    QSpacerItem *verticalSpacer;
    QLabel *icon;
    QWidget *messageBoxWidget;
    QHBoxLayout *messageBox;
    QWidget *messageWidget;
    QVBoxLayout *message;
    QLabel *text;
    QLabel *data;
    QSpacerItem *horizontalSpacer;
    dialogMessageWidget( QWidget *parent, std::string message, std::string time, bool client );

  public:
    ~dialogMessageWidget();
};

class dialogMessageBoxWidget : public QWidget
{
    Q_OBJECT
  public:
    dialogMessageBoxWidget( QWidget *parent );
    ~dialogMessageBoxWidget();

  private:
    void resizeEvent( QResizeEvent *event ) override;
};
#endif