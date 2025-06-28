#ifndef EMERGENCYMODEL_H
#define EMERGENCYMODEL_H

#include <QWidget>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QJsonArray>
#include <QString>
#include <QSet>

class EmergencyModel
{
public:
    QJsonArray getJson();
    void createJson();
    EmergencyModel();
private:
    QJsonArray emergencyType;
};

#endif // EMERGENCYMODEL_H
