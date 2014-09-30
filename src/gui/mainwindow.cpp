#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openGameWindow() {
    gameWindow = new GameWindow;
    gameWindwo.show();
}

void MainWindow::on_playButton_clicked() {
    openGameWindow();
}

void MainWindow::on_quitButton_clikced() {
    qApp->quit();
}
