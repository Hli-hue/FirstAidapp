#ifndef KITS_H
#define KITS_H

#include <QWidget>
#include <QToolButton>
#include <qpushbutton.h>

namespace Ui {
class Kits;
}

class Kits : public QWidget
{
    Q_OBJECT

public:
    explicit Kits(QWidget *parent = nullptr);
    ~Kits();

private:
    Ui::Kits *ui;

    QToolButton *toolButton[5];
    QPushButton *btn[5];
    QWidget *widgets[5];

    QString btnstyleOpened;
    QString btnstyleClosed;

private slots:
    void on_btns_clicked();
};

#endif // KITS_H
