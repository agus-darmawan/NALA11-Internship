#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pub_msg = nh.advertise<materi_3::value>("materi_3", 1000);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::send_data);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::send_data()
{
    int data_1 = ui->lineEdit_1->text().toInt();
    int data_2 = ui->lineEdit_2->text().toInt();
    int data_3 = ui->lineEdit_3->text().toInt();
    int data_4 = ui->lineEdit_4->text().toInt();
    int data_5 = ui->lineEdit_5->text().toInt();
    int data_6 = ui->lineEdit_6->text().toInt();
    pub_data(data_1, data_2,data_3, data_4,data_5, data_6);
}

void MainWindow::pub_data(int data_1, int data_2, int data_3, int data_4, int data_5, int data_6){

    dataPublish.maxh = data_1;
    dataPublish.maxs = data_2;
    dataPublish.maxv = data_3;
    dataPublish.minh = data_4;
    dataPublish.mins = data_5;
    dataPublish.minv = data_6;
    pub_msg.publish(dataPublish);
}