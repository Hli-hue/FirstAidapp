#include "emergencyguide.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QSqlDatabase>
#include <QSqlError>

EmergencyGuide::EmergencyGuide(QWidget *parent) : QMainWindow(parent) {
    setupDatabase(); // 初始化数据库

    QListWidget *listWidget = new QListWidget();

    // 读取数据库并填充列表
    QSqlQuery query("SELECT injury_type FROM emergency_guide");
    while (query.next()) {
        listWidget->addItem(query.value(0).toString());
    }

    connect(listWidget, &QListWidget::itemClicked, this, [this](QListWidgetItem *item) {
        QString injuryType = item->text();
        this->displayDetails(injuryType);
    });

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(listWidget);

    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void EmergencyGuide::setupDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("emergency_guide.db");

    if (!db.open()) {
        qDebug() << "Database error: " << db.lastError().text();
        return;
    }

    QSqlQuery query;

    // 清空表
    query.exec("DROP TABLE IF EXISTS emergency_guide");

    // 创建表
    query.exec("CREATE TABLE emergency_guide ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "injury_type TEXT UNIQUE, "  // 将injury_type设置为唯一
               "symptoms TEXT)");

    // 读取txt文件并插入数据
    QFile file("emergency_guide.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split("|");
            if (fields.size() == 2) {
                query.prepare("INSERT INTO emergency_guide (injury_type, symptoms) "
                              "VALUES (?, ?)");  // 不再使用IGNORE，以便每次都插入
                query.addBindValue(fields[0]);
                query.addBindValue(fields[1]);
                query.exec();
            }
        }
        file.close();
    }
}

void EmergencyGuide::displayDetails(const QString &injuryType) {
    // 从数据库获取详细信息
    QSqlQuery query;
    query.prepare("SELECT symptoms FROM emergency_guide WHERE injury_type = ?");
    query.addBindValue(injuryType);
    query.exec();

    if (query.next()) {
        QString symptoms = query.value(0).toString();
        QString imagePath = injuryType + ".jpg"; // 假设图片命名规则

        // 输出调试信息
        qDebug() << "Symptoms: " << symptoms;  // 确认症状信息
        qDebug() << "Image path: " << imagePath; // 确认图片路径

        // 创建并显示详细信息对话框
        DetailsDialog *dialog = new DetailsDialog(symptoms, imagePath, this);
        dialog->exec(); // 模态对话框
    } else {
        qDebug() << "No symptoms found for injury type: " << injuryType; // 没有找到症状
    }
}

DetailsDialog::DetailsDialog(const QString &symptoms, const QString &imagePath, QWidget *parent)
    : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout();

    // 添加症状信息的标签
    layout->addWidget(new QLabel("症状: " + symptoms));

    // 添加图片
    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
        qDebug() << "Failed to load image from path: " << imagePath; // 图片加载失败
    } else {
        // 固定弹窗大小
        setFixedSize(400, 300); // 设置固定大小

        // 按比例缩放图像
        QLabel *imageLabel = new QLabel();
        imageLabel->setPixmap(pixmap.scaled(400, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        layout->addWidget(imageLabel);
    }

    // 添加关闭按钮
    QPushButton *closeButton = new QPushButton("关闭");
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
    layout->addWidget(closeButton);

    setLayout(layout);
}
