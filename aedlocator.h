#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QProcess>
#include <QFile>
#include <Qlabel>
#include <QLineEdit>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

struct AED {
    QString id;      // AED设备ID
    double latitude;  // 纬度
    double longitude; // 经度
};

class AEDLocator : public QWidget {
    Q_OBJECT

    // 在 AEDLocator 类中添加成员变量
private:
    QNetworkAccessManager *networkManager;

public:
    AEDLocator(QWidget *parent = nullptr);

private slots:
    void onGeocodeButtonClicked();
    void onFindButtonClicked();

private:
    void initUI();
    void loadAEDData();
    AED findNearestAED(double userLat, double userLon);

    // 声明所有 UI 控件
    QLineEdit *addressInput;
    QLineEdit *lonInput;      // 新增
    QLineEdit *latInput;      // 新增
    QPushButton *geocodeButton;
    QPushButton *findButton;  // 新增
    QLabel *resultLabel;      // 新增

    QList<AED> aedList;
};
