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

class authWidget : public QMainWindow
{
    Q_OBJECT

  public:
    authWidget( QStackedWidget *screen, QWidget *parent = nullptr );
    ~authWidget();
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *login;
    QLineEdit *password;
    QPushButton *enterButton;
    QPushButton *referenceButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QStackedWidget *screen;
    bool registration;

  private slots:
    void on_enterButton_clicked();
    void on_referenceButton_clicked();

  private:
    void reference();
};

#endif // AUTHWIDGET_H
