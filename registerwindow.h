#pragma once
#ifndef REGISTERWINDOW_H
#    define REGISTERWINDOW_H
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

class registerWindow : public QWidget
{
    Q_OBJECT

  public:
    registerWindow( QStackedWidget &sw, QWidget *parent = nullptr );
    ~registerWindow();
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
};

#endif // REGISTERWINDOW_H
