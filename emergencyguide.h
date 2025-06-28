#ifndef EMERGENCYGUIDE_H
#define EMERGENCYGUIDE_H

#include <QMainWindow>
#include <QListWidget>
#include <QSqlQuery>
#include <QDialog>

class EmergencyGuide : public QMainWindow {
    Q_OBJECT
public:
    EmergencyGuide(QWidget *parent = nullptr);
    void displayDetails(const QString &injuryType);

private:
    void setupDatabase();
};

class DetailsDialog : public QDialog {
    Q_OBJECT
public:
    DetailsDialog(const QString &symptoms, const QString &imagePath, QWidget *parent = nullptr);
};

#endif // EMERGENCYGUIDE_H

