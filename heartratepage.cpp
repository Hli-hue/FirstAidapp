#include "heartratepage.h"

HeartRatePage::HeartRatePage(QWidget *parent)
    : QWizardPage(parent), tempSpinBox(new QDoubleSpinBox(this))
{
    setTitle("输入心率");
    tempSpinBox->setRange(30, 200);
    tempSpinBox->setValue(60);
    tempSpinBox->setSingleStep(1);

    QFormLayout *layout = new QFormLayout;
    layout->addRow("心率 (次/分钟):", tempSpinBox);
    setLayout(layout);

    registerField("heartrate*", tempSpinBox); // *表示必填字段
}

double HeartRatePage::getHeartRate() const {
    return tempSpinBox->value();
}
