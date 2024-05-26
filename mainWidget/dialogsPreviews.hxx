#pragma once
#ifndef DIALOGPREVIEWS_HXX
#    define DIALOGPREVIEWS_HXX
#    include <QtWidgets/QLabel>
#    include <QtWidgets/QWidget>
#    include <QtWidgets/QVBoxLayout>
#    include <QtWidgets/QHBoxLayout>
#    include <QtWidgets/QPushButton>
#    include <QtWidgets/QLineEdit>
#    include <QtWidgets/QListWidget>
#    include <QtWidgets/QLabel>
#    include <QtWidgets/QSpacerItem>
#    include "mainWidget.hxx"

class mainWidget;
class dialogPreviewWidget;

class dialogsPreviews : public QWidget
{
    Q_OBJECT

  private:
    friend mainWidget;
    dialogsPreviews( mainWidget *parent );

  public:
    ~dialogsPreviews();
    QVBoxLayout *usersLayout;
    QWidget *searchBar;
    QHBoxLayout *searchBarLayout;
    QPushButton *settingsOpenButton;
    QLineEdit *searchField;
    QListWidget *users;
    dialogPreviewWidget *createPreviewUp( std::string name, std::string lastMessage, std::string lastMessageTime );
    dialogPreviewWidget *createPreviewDown( std::string name, std::string lastMessage, std::string lastMessageTime );
};

class dialogPreviewWidget : public QWidget
{
    Q_OBJECT
  private:
    friend mainWidget;
    friend dialogsPreviews;
    dialogPreviewWidget( QListWidget *parent, std::string name, std::string lastMessage, std::string lastMessageTime );

  public:
    ~dialogPreviewWidget();
    QLabel *Avatar;
    QLabel *UserName;
    QLabel *ReadStatys;
    QLabel *DialogTime;
    QLabel *LastMessage;
    QLabel *DialogStatus;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
};
#endif