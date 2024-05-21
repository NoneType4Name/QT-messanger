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
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;

  private:
    QStackedWidget &screen;

  private slots:
    void on_pushButton_clicked();
    void on_goToRegister_clicked();
};

#endif // SIGNINWIDGET_H
