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

void MainWindow::on_pushButton_clicked()
{
  uav_button_actions->startMission();
  ui->pushButton->setEnabled(false);
}

void MainWindow::on_radioButton_clicked()
{
    uav_button_actions->switchOperator(2);
    ui->pushButton_17->setEnabled(false);
    ui->pushButton_18->setEnabled(false);
    ui->pushButton_15->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
    ui->pushButton_16->setEnabled(false);
    ui->pushButton_13->setEnabled(false);
}

void MainWindow::on_radioButton_2_clicked()
{
    uav_button_actions->switchOperator(1);
    ui->pushButton_17->setEnabled(true);
    ui->pushButton_18->setEnabled(true);
    ui->pushButton_15->setEnabled(true);
    ui->pushButton_14->setEnabled(true);
    ui->pushButton_16->setEnabled(true);
    ui->pushButton_13->setEnabled(true);
}

void MainWindow::on_radioButton_3_clicked()
{
    uav_button_actions->switchPrimaryUav(1);
}

void MainWindow::on_radioButton_4_clicked()
{
    uav_button_actions->switchPrimaryUav(2);
}

void MainWindow::on_radioButton_5_clicked()
{
    uav_button_actions->switchPrimaryUav(3);
}

void MainWindow::on_radioButton_6_clicked()
{
    uav_button_actions->switchPrimaryUav(4);
}
