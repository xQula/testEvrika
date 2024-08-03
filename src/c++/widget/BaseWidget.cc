//
// Created by xqula on 01.08.24.
//

#include "BaseWidget.h"
#include <QVBoxLayout>

auto widget::BaseWidget::setSize(const SizeWidget& size) -> void
{
    this->setFixedSize(size.x, size.y);
}

auto widget::BaseWidget::createLayot(QWidget* element) -> void
{
    const auto mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(element);
}
