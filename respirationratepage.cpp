#include "respirationratepage.h"

RespirationRatePage::RespirationRatePage(QWidget *parent)
    : QWizardPage(parent), tempSpinBox(new QDoubleSpinBox(this))
{
    setTitle("输入呼吸频率");
    tempSpinBox->setRange(6, 30);
    tempSpinBox->setValue(12);
    tempSpinBox->setSingleStep(1);

    QFormLayout *layout = new QFormLayout;
    layout->addRow("呼吸频率 (次/分钟):", tempSpinBox);
    setLayout(layout);

    registerField("temperature*", tempSpinBox); // *表示必填字段
}

double RespirationRatePage::getRespirationRate() const {
    return tempSpinBox->value();
}
