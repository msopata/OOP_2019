#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    displacement = new Displacement(this);
    speed = new Speed(this);
    acceleration = new Acceleration(this);

    QObject::connect(displacement, SIGNAL(changed(double)),
                     speed, SLOT(onDisplacementChange(double))
                     );

    QObject::connect(speed, SIGNAL(changed(double)),
                     acceleration, SLOT(onSpeedChange(double))
                     );

     ui->setupUi(this);

     QObject::connect(speed, SIGNAL(changed(double)),
                      ui->lcdSpeed, SLOT(display(double))
                      );

     QObject::connect(acceleration, SIGNAL(changed(double)),
                      ui->lcdAcceleration, SLOT(display(double))
                      );



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QString s = ui->lineEdit->text();

    displacement->set(s.toDouble());
}
