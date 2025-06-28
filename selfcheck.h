#ifndef SELFCHECK_H
#define SELFCHECK_H

#include <QWidget>

namespace Ui {
class SelfCheck;
}

class SelfCheck : public QWidget
{
    Q_OBJECT

public:
    explicit SelfCheck(QWidget *parent = nullptr);
    ~SelfCheck();

private:
    Ui::SelfCheck *ui;
};

#endif // SELFCHECK_H
