#include "learningmenu.h"
#include "ui_learningmenu.h"

LearingMenu::LearingMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LearingMenu)
{
    ui->setupUi(this);
}

LearingMenu::~LearingMenu()
{
    delete ui;
}

void LearingMenu::on_action0_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/0/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/0/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/0/QnA.md"));
}


void LearingMenu::on_action1_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/1/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/1/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/1/QnA.md"));
}


void LearingMenu::on_action2_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/2/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/2/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/2/QnA.md"));
}


void LearingMenu::on_action3_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/3/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/3/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/3/QnA.md"));
}


void LearingMenu::on_action4_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/4/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/4/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/4/QnA.md"));
}


void LearingMenu::on_action5_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/5/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/5/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/5/QnA.md"));
}


void LearingMenu::on_action6_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/6/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/6/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/6/QnA.md"));
}


void LearingMenu::on_action7_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/7/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/7/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/7/QnA.md"));
}


void LearingMenu::on_action8_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/8/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/8/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/8/QnA.md"));
}


void LearingMenu::on_action9_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/9/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/9/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/9/QnA.md"));
}


void LearingMenu::on_action10_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/10/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/10/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/10/QnA.md"));
}


void LearingMenu::on_action11_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/11/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/11/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/12/QnA.md"));
}


void LearingMenu::on_action12_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/12/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/12/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/12/QnA.md"));
}


void LearingMenu::on_action13_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/13/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/13/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/13/QnA.md"));
}


void LearingMenu::on_action14_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/14/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/14/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/14/QnA.md"));
}


void LearingMenu::on_action15_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/15/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/15/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/15/QnA.md"));
}


void LearingMenu::on_action16_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/16/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/16/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/16/QnA.md"));
}


void LearingMenu::on_action17_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/17/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/17/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/17/QnA.md"));
}


void LearingMenu::on_action18_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/18/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/18/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/18/QnA.md"));
}


void LearingMenu::on_action19_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/19/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/19/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/19/QnA.md"));
}


void LearingMenu::on_action20_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/20/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/20/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/20/QnA.md"));
}


void LearingMenu::on_action21_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/21/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/21/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/21/QnA.md"));
}


void LearingMenu::on_action22_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/22/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/22/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/22/QnA.md"));
}


void LearingMenu::on_action23_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/23/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/23/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/23/QnA.md"));
}


void LearingMenu::on_action24_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/24/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/24/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/24/QnA.md"));
}


void LearingMenu::on_action25_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/25/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/25/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/25/QnA.md"));
}


void LearingMenu::on_action26_triggered()
{
    ui->HeadName->clear();
    ui->Steps->clear();
    ui->QnA->clear();

    ui->HeadName->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/26/HN.md"));
    ui->Steps->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/26/ST.md"));
    ui->QnA->setMarkdown(readFileContent("C:/FirstAidapp/knowledge/26/QnA.md"));
}


QString LearingMenu::readFileContent(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return QString("无法打开文件: %1\n错误: %2").arg(filePath, file.errorString());
    }

    QTextStream in(&file);
    return in.readAll();
}

void LearingMenu::on_action_B_triggered()
{

}

