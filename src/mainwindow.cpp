#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "FileTaggerWidget.h"

#include <qlayout.h>
#include <qlineedit.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUI() {
    //QLineEdit* form = new QLineEdit();
    FileTaggerWidget* form = new FileTaggerWidget();
    QLayout* layout = new QVBoxLayout();
    layout->addWidget(form);
    ui->centralwidget->setLayout(layout);
}
