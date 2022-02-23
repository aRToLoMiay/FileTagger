#include "TagViewerWidget.h"
#include "ui_TagViewerWidget.h"

TagViewerWidget::TagViewerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TagViewerWidget)
{
    ui->setupUi(this);
}

TagViewerWidget::~TagViewerWidget()
{
    delete ui;
}
