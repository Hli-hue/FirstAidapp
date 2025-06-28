#ifndef LEARNINGTEST_H
#define LEARNINGTEST_H

#include <QWidget>

namespace Ui {
class LearingTest;
}

class LearingTest : public QWidget
{
    Q_OBJECT

public:
    explicit LearingTest(QWidget *parent = nullptr);
    ~LearingTest();

private:
    Ui::LearingTest *ui;

};

#endif // LEARNINGTEST_H
