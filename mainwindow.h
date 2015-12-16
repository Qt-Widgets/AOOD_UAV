#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "src/uavGui/uavButtonActions.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initialize( uavButtonActions*  uav_button_actions );

private:
    Ui::MainWindow *ui;

    uavButtonActions*  uav_button_actions;
};

#endif // MAINWINDOW_H
