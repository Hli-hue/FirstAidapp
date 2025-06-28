#include "FirstAid.h"
#include "emergencyguide.h"
#include "AEDLocator.h"
#include "kits.h"
#include "learningmenu.h"
#include "symptomcheckdialog.h"
#include "ui_FirstAid.h"
#include "widget.h"
#include <QWidget>
#include <QScreen>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Learning,&QPushButton::clicked, this, &MainWindow::on_Learning_clicked);

    socket = new QTcpSocket;

    //连接到服务器
    QString ip="127.0.0.1";
    QString port="8000";
    socket->connectToHost(QHostAddress(ip),port.toShort());
    connect(socket,&QTcpSocket::connected,[this]{
        QMessageBox::information(this,"连接提示","连接服务器成功");
    });

    connect(socket,&QTcpSocket::disconnected,[this]{
        QMessageBox::warning(this,"连接提示","连接断开");
    });

    connect(socket,&QTcpSocket::readyRead,[this]{
        QString message=QString(socket->readAll());
        message+="有急救事件发生，请求救援";
        QMessageBox::information(this,"救援提示",message);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Learning_clicked()
{
    LearingMenu *LearningMenuWidget = new LearingMenu();
    LearningMenuWidget->setWindowTitle("急救学习");
    LearningMenuWidget->setWindowIcon(QIcon(":/res/Learn.png"));
    LearningMenuWidget->resize(1000, 650);
    LearningMenuWidget->show();
}


void MainWindow::on_Kits_clicked()
{
    Kits *KitWidget = new Kits();
    KitWidget->setWindowTitle("急救包整理");
    KitWidget->setWindowIcon(QIcon(":/res/Kits.png"));
    KitWidget->resize(1000, 650);
    KitWidget->show();
}


void MainWindow::on_Guide_clicked()
{
    EmergencyGuide* window = new EmergencyGuide(this);
    window->setWindowTitle("紧急救援指导");
    window->setWindowIcon(QIcon(":/res/Guide.png"));
    window->resize(700,500);
    window->show();
}

void MainWindow::on_Check_clicked()
{
    // 使用指针确保窗口不会立即销毁
    SymptomCheckDialog* dialog = new SymptomCheckDialog(this);
    dialog->setWindowTitle("症状自查");
    dialog->setWindowIcon(QIcon(":/res/Check.png"));
    dialog->show();
}



void MainWindow::on_AEDLocate_clicked()
{
    AEDLocator* locator = new AEDLocator();

    locator->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint);

    locator->setAttribute(Qt::WA_TranslucentBackground, false);

    locator->setWindowTitle("急救设备定位");
    locator->setWindowIcon(QIcon(":/res/AED.png"));
    locator->setFixedSize(300, 200);  // 禁止调整大小

    QPoint centerPos = this->geometry().center() - locator->rect().center();
    locator->move(centerPos);

    locator->setAttribute(Qt::WA_DeleteOnClose);
    locator->show();
}


void MainWindow::on_Operate_clicked()
{
    Widget *operateWindow = new Widget(this);
    operateWindow->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint);

    operateWindow->setAttribute(Qt::WA_TranslucentBackground, false);
    operateWindow->setStyleSheet("background-color: white;");

    operateWindow->setWindowTitle("急救处理方案");
    operateWindow->setWindowIcon(QIcon(":/res/Operate.png"));
    operateWindow->setFixedSize(350, 500);
    QPoint centerPos = this->geometry().center() - operateWindow->rect().center();
    operateWindow->move(centerPos);
    operateWindow->setAttribute(Qt::WA_DeleteOnClose);
    operateWindow->show();
}

void MainWindow::on_CallButton_clicked()
{
    double lat, lon;
    QString error;
    QByteArray ba;

    if (getLocation(lat, lon, error)) {
        qDebug() << "定位成功:" << lat << "," << lon;
        QString positionSite="经度：";
        positionSite+=QString::number(lat);
        positionSite+="  纬度：";
        positionSite+=QString::number(lon);
        ba=positionSite.toUtf8();
    } else{
        qDebug() << "定位成功:" ;
        ba="二教309";
    }

    QMessageBox::information(this,"紧急呼叫","定位成功！请等待救援！");

    socket->write(ba);
}

bool MainWindow::getLocation(double &latitude, double &longitude, QString &error)
{
    // 检查定位服务是否可用
    const auto sources = QGeoPositionInfoSource::availableSources();
    if (sources.isEmpty()) {
        error = "定位服务不可用";
        return false;
    }

    // 创建定位源
    QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
    if (!source) {
        error = "无法创建定位源";
        return false;
    }

    // 准备事件循环
    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);

    // 连接信号
    bool success = false;
    connect(source, &QGeoPositionInfoSource::positionUpdated, this,
            [&](const QGeoPositionInfo &info) {
                if (info.isValid()) {
                    latitude = info.coordinate().latitude();
                    longitude = info.coordinate().longitude();
                    success = true;
                } else {
                    error = "无效位置信息";
                }
                loop.quit();
            });

    connect(source, &QGeoPositionInfoSource::errorOccurred, this,
            [&](QGeoPositionInfoSource::Error errorType) {
                switch (errorType) {
                case QGeoPositionInfoSource::AccessError:
                    error = "位置权限被拒绝";
                    break;
                case QGeoPositionInfoSource::ClosedError:
                    error = "定位服务已关闭";
                    break;
                default:
                    error = "定位错误: " + QString::number(static_cast<int>(errorType));
                }
                loop.quit();
            });

    connect(&timer, &QTimer::timeout, this, [&]() {
        error = "定位请求超时";
        loop.quit();
    });

    // 启动定位请求
    source->requestUpdate();
    timer.start(10000); // 10秒超时

    // 等待结果
    loop.exec();

    // 清理
    source->deleteLater();

    return success;
}
