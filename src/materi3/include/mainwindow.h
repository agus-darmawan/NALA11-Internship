#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ros/ros.h>
#include <QMainWindow>
#include <QDebug>
#include <ui_mainwindow.h>
#include "materi_3/value.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void pub_data(int, int,int,int,int,int);

public slots:
    void send_data();

private:
    Ui::MainWindow *ui;
    materi_3::value dataPublish;
    ros::NodeHandle nh;
    ros::Publisher pub_msg;
};

#endif // MAINWINDOW_H