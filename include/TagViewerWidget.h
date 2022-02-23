#ifndef TAGVIEWERWIDGET_H
#define TAGVIEWERWIDGET_H

#include <QWidget>

namespace Ui {
class TagViewerWidget;
}

class TagViewerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TagViewerWidget(QWidget *parent = nullptr);
    ~TagViewerWidget();

private:
    Ui::TagViewerWidget *ui;
};

#endif // TAGVIEWERWIDGET_H
