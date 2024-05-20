#pragma once
#ifndef MAINWINDOW_H
#    define MAINWINDOW_H
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

class mainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    mainWindow( QStackedWidget &sw, QWidget *parent = nullptr );
    ~mainWindow();
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
    QStackedWidget &sw;

  private slots:
    void on_pushButton_clicked();
    void on_goToRegister_clicked();
};

#endif // MAINWINDOW_H
