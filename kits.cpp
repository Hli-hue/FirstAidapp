#include "kits.h"
#include "ui_kits.h"

Kits::Kits(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Kits)
{
    ui->setupUi(this);
    toolButton[0] = ui->tbbook;
    toolButton[1] = ui->tbbandage;
    toolButton[2] = ui->tbdisinfect;
    toolButton[3] = ui->tbmadicine;
    toolButton[4] = ui->tbtool;

    btn[0] = ui->btbook;
    btn[1] = ui->btbandage;
    btn[2] = ui->btdisinfect;
    btn[3] = ui->btmedicine;
    btn[4] = ui->bttool;

    widgets[0] = ui->bookbox;
    widgets[1] = ui->bandagebox;
    widgets[2] = ui->disinfectbox;
    widgets[3] = ui->medicinebox;
    widgets[4] = ui->toolbox;

    btnstyleClosed = R"(
        QPushButton {
            border: none;
            background-image: url(":/res/res/add.png");
            background-repeat:no-repeat;
            background-position:center;
            background-color:transparent;
        }
        QPushButton:hover {
            background-image: url(":/res/res/add_hover.png");
        }
    )";

    btnstyleOpened = R"(
        QPushButton {
            border: none;
            background-image: url(":/res/res/minus.png");
            background-repeat:no-repeat;
            background-position:center;
            background-color:transparent;
        }
        QPushButton:hover {
            background-image: url(":/res/res/minus_hover.png");
        }
    )";
    QString toolButtonTexts[5] = {"文书类","包扎类","消毒类","医药类","工具类"};
    QString toolButtonIcons[5] = {":/res/res/book.png",":/res/res/bandage.png",":/res/res/disinfect.png",":/res/res/medicine.png",":/res/res/tool.png"};

    for (int i = 0; i < 5; i++){
        toolButton[i]->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        toolButton[i]->setText(toolButtonTexts[i]);
        toolButton[i]->setIcon(QIcon(QPixmap(toolButtonIcons[i])));
        toolButton[i]->setIconSize(QSize(32,32));
        toolButton[i]->setStyleSheet(R"(
            QToolButton {
                border:0px solid #C0DCF2;
                font:16px "Microsoft YaHei";
                padding:5px;
                padding-left:10px;
            }
)");
        widgets[i]->setVisible(false);
        btn[i]->setStyleSheet(btnstyleClosed);
        btn[i]->setProperty("index",i);

        connect(btn[i],&QPushButton::clicked,this,&::Kits::on_btns_clicked);
    }
}

Kits::~Kits()
{
    delete ui;
}

void ::Kits::on_btns_clicked(){
    QPushButton *button =qobject_cast<QPushButton *>(sender());
    if (button){
        int index = button->property("index").toInt();
        widgets[index]->setVisible(!widgets[index]->isVisible());
        btn[index]->setStyleSheet(
            widgets[index]->isVisible() ? btnstyleOpened : btnstyleClosed);
    }
}

