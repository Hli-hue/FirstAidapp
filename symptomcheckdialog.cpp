#include "symptomcheckdialog.h"

SymptomCheckDialog::SymptomCheckDialog(QWidget *parent) : QDialog(parent) {
    setupDatabase();

    QVBoxLayout *layout = new QVBoxLayout(this);

    temperatureInput = new QLineEdit(this);
    heartRateInput = new QLineEdit(this);
    respirationRateInput = new QLineEdit(this);

    layout->addWidget(new QLabel("体温 (℃)："));
    layout->addWidget(temperatureInput);
    layout->addWidget(new QLabel("心率 (次/分钟)："));
    layout->addWidget(heartRateInput);
    layout->addWidget(new QLabel("呼吸频率 (次/分钟)："));
    layout->addWidget(respirationRateInput);

    QPushButton *submitButton = new QPushButton("提交", this);
    layout->addWidget(submitButton);

    connect(submitButton, &QPushButton::clicked, this, &SymptomCheckDialog::onSubmit);
}

void SymptomCheckDialog::setupDatabase() {
    // 创建数据库连接
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("health_conditions.db");

    // 打开数据库连接
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Unable to open the database.");
        return; // 如果数据库打开失败，则返回
    }

    // 创建表
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS health_conditions ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "temperature REAL, "
               "heart_rate INTEGER, "
               "respiration_rate INTEGER, "
               "condition TEXT)");

    // 插入一些初始数据
    query.exec("INSERT INTO health_conditions (temperature, heart_rate, respiration_rate, condition) VALUES (38.5, NULL, NULL, '高烧')");
    query.exec("INSERT INTO health_conditions (temperature, heart_rate, respiration_rate, condition) VALUES (37.3, NULL, NULL, '低烧')");
    query.exec("INSERT INTO health_conditions (temperature, heart_rate, respiration_rate, condition) VALUES (NULL, 60, NULL, '心率过低，可能失血过多')");
    query.exec("INSERT INTO health_conditions (temperature, heart_rate, respiration_rate, condition) VALUES (NULL, 100, NULL, '心率过高，可能焦虑或其他')");
    query.exec("INSERT INTO health_conditions (temperature, heart_rate, respiration_rate, condition) VALUES (NULL, NULL, 12, '呼吸频率正常')");
}

void SymptomCheckDialog::onSubmit() {
    bool ok;
    double temperature = temperatureInput->text().toDouble(&ok);
    if (!ok) return; // 输入不合法处理
    int heartRate = heartRateInput->text().toInt(&ok);
    if (!ok) return; // 输入不合法处理
    int respirationRate = respirationRateInput->text().toInt(&ok);
    if (!ok) return; // 输入不合法处理

    evaluateHealth(temperature, heartRate, respirationRate);
}

void SymptomCheckDialog::evaluateHealth(double temperature, int heartRate, int respirationRate) {
    QString condition;

    // 综合评估体温
    if (temperature >= 38.5) {
        condition += "高烧；";
    } else if (temperature >= 37.3) {
        condition += "低烧；";
    } else if (temperature < 35.0) {
        condition += "低体温；";
    } else {
        condition += "体温正常；";
    }

    // 综合评估心率
    if (heartRate < 60) {
        condition += "心率过低，可能失血过多；";
    } else if (heartRate > 100) {
        condition += "心率过高，可能焦虑或其他；";
    } else {
        condition += "心率正常；";
    }

    // 综合评估呼吸频率
    if (respirationRate < 12) {
        condition += "呼吸频率过低，可能存在呼吸系统问题；";
    } else if (respirationRate > 20) {
        condition += "呼吸频率过高，可能焦虑或其他；";
    } else {
        condition += "呼吸频率正常；";
    }

    // 输出综合评估结果
    QMessageBox::information(this, tr("健康状态"), condition);
}
