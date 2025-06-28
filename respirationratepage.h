#ifndef RESPIRATIONRATEPAGE_H
#define RESPIRATIONRATEPAGE_H

#include <QWizardPage>
#include <QDoubleSpinBox>
#include <QFormLayout>

class RespirationRatePage : public QWizardPage {
    Q_OBJECT
public:
    RespirationRatePage(QWidget *parent = nullptr);
    double getRespirationRate() const;

private:
    QDoubleSpinBox *tempSpinBox;
};

#endif // RESPIRATIONRATEPAGE_H
