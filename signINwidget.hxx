#pragma once
#ifndef SIGNINWIDGET_H
#    define SIGNINWIDGET_H
#    include <QMainWindow>
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

class signINWidget : public QMainWindow
{
    Q_OBJECT

  public:
    signINWidget( QStackedWidget &screen, QWidget *parent = nullptr );
    ~signINWidget();
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *welcomeLabel;
    QLineEdit *login;
    QLineEdit *password;
    QPushButton *enterButton;
    QPushButton *registrationReferenceButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

  private:
    QStackedWidget &screen;

  private slots:
    void on_enterButton_clicked();
    void on_registrationReferenceButton_clicked();
};

#endif // SIGNINWIDGET_H
