#include "selfcheck.h"
#include "ui_selfcheck.h"

SelfCheck::SelfCheck(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SelfCheck)
{
    ui->setupUi(this);
}

SelfCheck::~SelfCheck()
{
    delete ui;
}
