#include "searchengine.h"

SearchEngine::SearchEngine(const QJsonArray & emergencyType)
{
    searchStart=emergencyType;
}


QJsonArray SearchEngine::search(const QString & query)
{
    QStringList searchTerms=query.split(' ',Qt::SkipEmptyParts);
    QVector<QPair<QJsonValue,int>>results;

    for(int i=0;i<searchStart.size();i++){
        int score=calculateScore(searchStart.at(i),searchTerms);
        if(score>0){
            results.append(qMakePair(searchStart.at(i),score));
        }
    }

    std::sort(results.begin(),results.end(),[](const QPair<QJsonValue,int> &a,const QPair<QJsonValue,int> &b){
        return (a.second > b.second);
    });

    //检测
    qDebug()<<results;
    //至此

    QJsonArray searchFinal;
    for(int i=0;i<results.size();i++){
        searchFinal.append(results.at(i).first);
    }

    return searchFinal;
}



int SearchEngine::calculateScore(const QJsonValue & item, const QStringList &queryTerms)
{
    int score=0;
    QJsonObject obj=item.toObject();



    QJsonValue nameValue=obj.value("name");
    QString nameString=nameValue.toString();

    for(const QString &item: queryTerms){
        if(item==nameString){
            score+=10000;
            return score;
        }
        score+=levenshteinDistance(item,nameString);
        score+=10*jaccardSimilarity(item,nameString);
    }



    /*QJsonValue symptomValue=obj.value("symptom");
    QJsonArray symptomArray = symptomValue.toArray();
    for(const QString &item: queryTerms){
        for(const QJsonValue &itemSym: symptomArray){
            score+=levenshteinDistance(item,itemSym.toString());
            score+=10*jaccardSimilarity(item,itemSym.toString());
        }
    }*/


    QJsonValue keywordsValue=obj.value("keywords");
    QJsonArray keywordsArray = keywordsValue.toArray();
    for(const QString &item: queryTerms){
        for(const QJsonValue &itemKey: keywordsArray){
            score+=levenshteinDistance(item,itemKey.toString());
            score+=10*jaccardSimilarity(item,itemKey.toString());
        }
    }

    //检测
    /*qDebug()<<nameString;
    qDebug()<<symptomString;
    qDebug()<<keywordsString;*/
    //发现bug：nameString没有数据
    //已修正

    /*for(const QString &item: queryTerms){
        if(item==nameString){
            score+=10000;
            return score;
        }
        score+=levenshteinDistance(item,nameString);
        for(int i=0;i<symptomTerms.size();i++){
            score+=levenshteinDistance(item,symptomTerms[i]);
        }
        for(int i=0;i<keywordsTerms.size();i++){
            score+=levenshteinDistance(item,keywordsTerms[i]);
        }

    }*/

    QJsonValue urgency=obj.value("urgency");
    int urgencyScore=urgency.toInt();
    score+=urgencyScore;

    qDebug()<<score;
    return score;
}



int SearchEngine::levenshteinDistance(const QString &s1, const QString &s2) {
    const int len1 = s1.size(), len2 = s2.size();
    QVector<QVector<int>> dp(len1+1, QVector<int>(len2+1, 0));

    for (int i = 0; i <= len1; ++i) dp[i][0] = i;
    for (int j = 0; j <= len2; ++j) dp[0][j] = j;

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            int cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
            dp[i][j] = std::min({
                dp[i-1][j] + 1,
                dp[i][j-1] + 1,
                dp[i-1][j-1] + cost
            });
        }
    }
    return dp[len1][len2];
}


int SearchEngine::jaccardSimilarity(const QString &s1, const QString &s2){
    // 将字符串拆分为单字的集合（自动去重）
    QSet<QString> set1, set2;
    for (const QChar &ch : s1) {
        set1.insert(QString(ch));
    }
    for (const QChar &ch : s2) {
        set2.insert(QString(ch));
    }

    //检测分词结果
    //qDebug()<<"拆词："<<set1;
    //qDebug()<<"拆词："<<set2;

    // 计算交集和并集的大小
    const int intersection = (set1 & set2).size();
    const int union_size = (set1 | set2).size();

    // 处理并集为空的情况
    return 10*(union_size == 0 ? 0.0 : static_cast<double>(intersection) / union_size);
}
