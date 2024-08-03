//
// Created by xqula on 01.08.24.
//

#include "mainWidget.h"
#include <QVBoxLayout>



widget::MainWidget::MainWidget(QWidget* parent)
    : BaseWidget(parent)
    , m_widget_second( new SecondWidget(nullptr))
    , m_button(new QPushButton(this))
{
    this->setWindowTitle("Main window");
    this->setSize({800, 600});
    this->createButton();
    this->createLayot(m_button);
    this->show();
}

widget::MainWidget::~MainWidget()
{
    delete m_widget_second;
}

auto widget::MainWidget::createButton() -> void
{
    m_button->setText("Click me");
    connect(m_button, &QPushButton::clicked, this, [this](){
        m_widget_second->show();
    });
}