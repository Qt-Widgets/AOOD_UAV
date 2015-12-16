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

void MainWindow::on_pushButton_13_clicked()
{
    uav_button_actions->dropSupplies();
}

void MainWindow::on_pushButton_16_clicked()
{
    uav_button_actions->takePicture();
}

void MainWindow::on_pushButton_14_clicked()
{
    uav_button_actions->transmitPictures();
}

void MainWindow::on_pushButton_15_clicked()
{
    uav_button_actions->fireMissile();
}

void MainWindow::on_pushButton_18_clicked()
{
    uav_button_actions->fireGun();
}

void MainWindow::on_pushButton_17_clicked()
{
    uav_button_actions->breakEngage();
}
