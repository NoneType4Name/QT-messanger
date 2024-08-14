#pragma once
#ifndef MAINWIDGET_HXX
#    define MAINWIDGET_HXX
#    include <QtCore/QVariant>
#    include <QtWidgets/QStackedWidget>
#    include <QtWidgets/QApplication>
#    include <QtWidgets/QHBoxLayout>
#    include <QtWidgets/QHeaderView>
#    include <QtWidgets/QLineEdit>
#    include <QtWidgets/QListWidget>
#    include <QtWidgets/QMainWindow>
#    include <QtWidgets/QPushButton>
#    include <QtWidgets/QTableWidget>
#    include <QtWidgets/QVBoxLayout>
#    include <QtWidgets/QWidget>
#    include <QtWidgets/QSplitter>
#    include "dialogsPreviews.hxx"
#    include "dialogMessages.hxx"

class mainWidget : public QMainWindow
{
    Q_OBJECT

  public:
    mainWidget( class screenWidget *screen, QMainWindow *parent = nullptr );
    ~mainWidget();
    QWidget *centralwidget;
    QHBoxLayout *mainLayout;
    QSplitter *splitter;
    screenWidget *screen;
    class dialogsPreviews *previews;
    class dialogMessages *messages;
};
#endif