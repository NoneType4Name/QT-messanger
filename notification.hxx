#pragma once
#ifndef NOTIFICATION_HXX
#    define NOTIFICATION_HXX
#    include <QtWidgets/QApplication>
#    include <QtWidgets/QHBoxLayout>
#    include <QtWidgets/QLabel>
#    include <QtWidgets/QMainWindow>
#    include <QtWidgets/QPushButton>
#    include <QtWidgets/QSpacerItem>
#    include <QtWidgets/QVBoxLayout>
#    include <QtWidgets/QWidget>

class notificationWidget : public QWidget
{
    Q_OBJECT

  public:
    notificationWidget( QWidget *parent = nullptr );
    ~notificationWidget();
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *text;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *OkButton;
    QSpacerItem *horizontalSpacer1;
  private slots:
    void on_OkButton_clicked();
};
#endif