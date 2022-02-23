#ifndef FILETAGGERWIDGET_H
#define FILETAGGERWIDGET_H

#include <QWidget>

namespace Ui {
class FileTaggerWidget;
}

class FileTaggerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileTaggerWidget(QWidget *parent = nullptr);
    ~FileTaggerWidget();

protected:
    void setupUI();

private:
    Ui::FileTaggerWidget *ui;
};

#endif // FILETAGGERWIDGET_H
