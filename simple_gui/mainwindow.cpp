#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include "acceleration.h"
#include "displacement.h"
#include "speed.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Displacement *displacement = new Displacement(this);
    Speed *speed = new Speed(this);
    Acceleration *acceleration = new Acceleration(this);

    QObject::connect(displacement, SIGNAL(changed(double)),
                     speed, SLOT(onDisplacementChange(double))
                     );

    QObject::connect(speed, SIGNAL(changed(double)),
                     acceleration, SLOT(onSpeedChange(double))
                     );

     ui->setupUi(this);

     QObject::connect(displacement, SIGNAL(changed(double)),
                      ui->lcdSpeed, SLOT(display(double))
                      );

     QObject::connect(speed, SIGNAL(changed(double)),
                      ui->lcdAcceleration, SLOT(display(double))
                      );



}

MainWindow::~MainWindow()
{
    delete ui;
}
