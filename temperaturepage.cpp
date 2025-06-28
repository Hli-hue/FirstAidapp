#include "temperaturepage.h"

TemperaturePage::TemperaturePage(QWidget *parent)
    : QWizardPage(parent), tempSpinBox(new QDoubleSpinBox(this))
{
    setTitle("输入体温");
    tempSpinBox->setRange(30.0, 50.0);
    tempSpinBox->setValue(36.0);
    tempSpinBox->setSingleStep(0.1);

    QFormLayout *layout = new QFormLayout;
    layout->addRow("体温 (℃):", tempSpinBox);
    setLayout(layout);

    registerField("temperature*", tempSpinBox); // *表示必填字段
}

double TemperaturePage::getTemperature() const {
    return tempSpinBox->value();
}
