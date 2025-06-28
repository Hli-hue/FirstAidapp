#include "mypage.h"
#include "ui_mypage.h"

MyPage::MyPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyPage)
{
    ui->setupUi(this);
}

MyPage::~MyPage()
{
    delete ui;
}
