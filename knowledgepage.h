#ifndef KNOWLEDGEPAGE_H
#define KNOWLEDGEPAGE_H

#include <QWidget>

namespace Ui {
class KnowledgePage;
}

class KnowledgePage : public QWidget
{
    Q_OBJECT

public:
    explicit KnowledgePage(QWidget *parent = nullptr);
    ~KnowledgePage();

private:
    Ui::KnowledgePage *ui;
};

#endif // KNOWLEDGEPAGE_H
