#ifndef SYMPTOMCHECKDIALOG_H
#define SYMPTOMCHECKDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

class SymptomCheckDialog : public QDialog {
    Q_OBJECT

public:
    SymptomCheckDialog(QWidget *parent = nullptr);

private slots:
    void onSubmit();

private:
    void setupDatabase();
    void evaluateHealth(double temperature, int heartRate, int respirationRate);

    QLineEdit *temperatureInput;
    QLineEdit *heartRateInput;
    QLineEdit *respirationRateInput;
};

#endif // SYMPTOMCHECKDIALOG_H
