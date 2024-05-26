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
    dialogMessageWidget( QTableWidget *parent, std::string message, std::string time, bool client );

  public:
    ~dialogMessageWidget();
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *autor;
    QSpacerItem *verticalSpacer;
    QLabel *icon;
    QVBoxLayout *message;
    std::vector<QLabel *> texts;
    QLabel *data;
};

class dialogMessageWidgetTextLabel : public QLabel
{
    Q_OBJECT
  public:
    dialogMessageWidgetTextLabel( QWidget *parent );
    ~dialogMessageWidgetTextLabel();

  private:
    void resizeEvent( QResizeEvent *event ) override;
};
#endif