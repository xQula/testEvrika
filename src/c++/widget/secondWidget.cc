//
// Created by xqula on 01.08.24.
//

#include "secondWidget.h"
#include <QVBoxLayout>

widget::SecondWidget::SecondWidget(QWidget* parent)
    : BaseWidget(parent)
    , m_label(new QLabel(this))
{
    this->setWindowTitle("Second window");
    this->setSize({600, 400});
    this->m_label->setText("Peace to the world");
    this->createLayot(m_label);
}
