#ifndef TEMPERATUREPAGE_H
#define TEMPERATUREPAGE_H

#include <QWizardPage>
#include <QDoubleSpinBox>
#include <QFormLayout>

class TemperaturePage : public QWizardPage {
    Q_OBJECT
public:
    TemperaturePage(QWidget *parent = nullptr);
    double getTemperature() const;

private:
    QDoubleSpinBox *tempSpinBox;
};

#endif // TEMPERATUREPAGE_H
