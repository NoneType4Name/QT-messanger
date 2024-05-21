#pragma once
#ifndef SIGNUPWIDGET_H
#    define SIGNUPWIDGET_H
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

class signUPwidget : public QMainWindow
{
    Q_OBJECT

  public:
    signUPwidget( QStackedWidget &screen, QWidget *parent = nullptr );
    ~signUPwidget();
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
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;

  private:
    QStackedWidget &screen;

  private slots:
    void on_enterButton_clicked();
};

#endif // SIGNUPWIDGET_H
