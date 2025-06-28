#ifndef HEARTRATEPAGE_H
#define HEARTRATEPAGE_H

#include <QWizardPage>
#include <QDoubleSpinBox>
#include <QFormLayout>

class HeartRatePage : public QWizardPage {
    Q_OBJECT
public:
    HeartRatePage(QWidget *parent = nullptr);
    double getHeartRate() const;

private:
    QDoubleSpinBox *tempSpinBox;
};

#endif // HEARTRATEPAGE_H
