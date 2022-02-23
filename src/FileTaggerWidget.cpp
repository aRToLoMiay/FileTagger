#include "FileTaggerWidget.h"
#include "ui_FileTaggerWidget.h"

#include "FilesManagerWidget.h"
#include "TagViewerWidget.h"

FileTaggerWidget::FileTaggerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileTaggerWidget)
{
    ui->setupUi(this);

    setupUI();
}

FileTaggerWidget::~FileTaggerWidget()
{
    delete ui;
}

void FileTaggerWidget::setupUI() {
    QLayout* layout = new QVBoxLayout();
    layout->addWidget(new FilesManagerWidget());
    ui->filesManagerWidget->setLayout(layout);

    layout = new QVBoxLayout();
    layout->addWidget(new TagViewerWidget());
    ui->tagsWidget->setLayout(layout);
    
    QPalette tagsPal;
    tagsPal.setColor(QPalette::Background, Qt::black);
    ui->viewWidget->setPalette(tagsPal);
    ui->viewWidget->update();
}
