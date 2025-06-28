#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "EmergencyModel.h"

class SearchEngine
{
public:
    SearchEngine(const QJsonArray & emergencyType);
    QJsonArray search(const QString & query);
private:
    QJsonArray searchStart;
    QString searchText;
    int calculateScore(const QJsonValue & item, const QStringList &queryTerms);
    int levenshteinDistance(const QString &s1, const QString &s2);
    int jaccardSimilarity(const QString &s1, const QString &s2);
};

#endif // SEARCHENGINE_H
