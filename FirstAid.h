#ifndef FIRSTAID_H
#define FIRSTAID_H

#include <Qtcpsocket>
#include <QMainWindow>
#include <QGeoPositionInfoSource>
#include <QGeoCoordinate>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Learning_clicked();

    void on_Kits_clicked();

    void on_Guide_clicked();

    void on_Check_clicked();

    void on_AEDLocate_clicked();

    void on_Operate_clicked();

    void on_CallButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket * socket;

    bool getLocation(double &latitude, double &longitude, QString &error);
};
#endif // FIRSTAID_H
