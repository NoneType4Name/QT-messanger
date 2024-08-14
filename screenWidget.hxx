#pragma once
#ifndef SCREENWIDGET_H
#    define SCREENWIDGET_H
#    include <QtCore/QVariant>
#    include <QtWidgets/QApplication>
#    include <QtWidgets/QHBoxLayout>
#    include <QtWidgets/QLabel>
#    include <QtWidgets/QLineEdit>
#    include <QtWidgets/QMainWindow>
#    include <QtWidgets/QMenuBar>
#    include <QtWidgets/QPushButton>
#    include <QtWidgets/QSpacerItem>
#    include <QtWidgets/QVBoxLayout>
#    include <QtWidgets/QWidget>
#    include <QStackedWidget>
#    include "authWidget.hxx"
#    include "mainWidget/mainWidget.hxx"

class screenWidget : public QStackedWidget
{
    Q_OBJECT

  public:
    screenWidget( QWidget *parent = nullptr );
    ~screenWidget();
    void init();
    authWidget *auth;
    mainWidget *mainWidget;
    // std::thread *auth_thread { nullptr };
};

#endif