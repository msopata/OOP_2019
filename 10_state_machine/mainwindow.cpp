#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStateMachine>
#include <QHistoryState>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    auto stateMachine = new QStateMachine(this);

    auto unlockedState = new QState(stateMachine);
    unlockedState->assignProperty(ui->pbToggle, "text", "LOCK");
    unlockedState->assignProperty(ui->pbToggle, "enabled", true);
    unlockedState->assignProperty(ui->pbSave, "enabled", true);
    unlockedState->assignProperty(ui->teText, "enabled", true);


    auto lockedState = new QState(stateMachine);
    lockedState->assignProperty(ui->pbToggle, "text", "UNLOCK");
    lockedState->assignProperty(ui->pbToggle, "enabled", true);
    lockedState->assignProperty(ui->pbSave, "enabled", false);
    lockedState->assignProperty(ui->teText, "placeholderText", "Error...");
    lockedState->assignProperty(ui->teText, "enabled", false);




    auto startUpState = new QState(unlockedState);
    startUpState->assignProperty(ui->pbSave, "enabled", false);
    startUpState->assignProperty(ui->teText, "placeholderText", "Openfile to start editing...");
    startUpState->assignProperty(ui->teText, "enabled", false);

    auto openState = new QState(unlockedState);

    auto errorState = new QState(unlockedState);

    auto viewState = new QState(unlockedState);
    viewState->assignProperty(ui->teText, "enabled", true);


    auto editState = new QState(unlockedState);
    editState->assignProperty(ui->pbOpen, "enabled", false);
    editState->assignProperty(ui->pbSave, "enabled", true);



    auto saveState = new QState(unlockedState);


    stateMachine->setInitialState(unlockedState);
    unlockedState->addTransition(ui->pbToggle, SIGNAL(clicked()), lockedState);
    lockedState->addTransition(ui->pbToggle, SIGNAL(clicked()), unlockedState);

    unlockedState->setInitialState(startUpState);


    //att!
    startUpState->addTransition(ui->pbOpen, SIGNAL(clicked()), openState);
    connect(ui->pbOpen, SIGNAL(clicked()), this, SLOT(open()));

    openState->addTransition(this, SIGNAL(opened()), viewState);

    viewState->addTransition(ui->pbOpen, SIGNAL(clicked()), openState);
    viewState->addTransition(ui->teText, SIGNAL(textChanged()), editState);

    editState->addTransition(ui->pbSave, SIGNAL(clicked()), saveState);

    saveState->addTransition(this, SIGNAL(saved()), viewState);
    connect(saveState, SIGNAL(entered()), this, SLOT(save()));






    stateMachine->start();

    /*
    auto greenState = new QState(stateMachine);
    auto yellowState = new QState(stateMachine);
    auto redState = new QState(stateMachine);
    auto logState = new QState(stateMachine);


    greenState->assignProperty(ui->pbToggle, "text", "GREEN");
    yellowState->assignProperty(ui->pbToggle, "text", "YELLOW");
    redState->assignProperty(ui->pbToggle, "text", "RED");


    greenState->addTransition(ui->pbToggle, SIGNAL(clicked()), redState);
    yellowState->addTransition(ui->pbToggle, SIGNAL(clicked()), logState);
    redState->addTransition(ui->pbToggle, SIGNAL(clicked()), yellowState);
    logState->addTransition(this, SIGNAL(done()), greenState);

    connect(logState, SIGNAL(entered()), this, SLOT(log()));

    stateMachine->setInitialState(greenState);

    stateMachine->start();
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{

    qDebug() << "Open state works...";
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Text File"), "", tr("Text Files (*.txt)"));
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        emit error();

    ui->teText->setText(file.readAll());
    emit opened();
}

void MainWindow::save()
{
    qDebug() << "Save state works..";
    emit saved();
    // TODO: Open 'fileName' for writing
    // TODO: Emit 'error' if opening failed
    // TODO: Save file and emit 'saved' if succeeded
}

void MainWindow::log()
{
    qDebug() << "Inside log() function...";
    emit done();
}

