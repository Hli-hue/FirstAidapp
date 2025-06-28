#include "knowledgepage.h"
#include "ui_knowledgepage.h"

KnowledgePage::KnowledgePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::KnowledgePage)
{
    ui->setupUi(this);
}

KnowledgePage::~KnowledgePage()
{
    delete ui;
}
