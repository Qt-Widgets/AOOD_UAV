#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/uavLogger/uavLogger.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    uavLogger::getInstance()->initialize( ui->textEdit );
    uavLogger::getInstance()->log("Hello Group Awesome!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize( uavButtonActions*  uav_button_actions )
{
 this->uav_button_actions   = uav_button_actions;
}
