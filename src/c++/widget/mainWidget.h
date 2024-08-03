//
// Created by xqula on 01.08.24.
//

#pragma once
#include <widget/secondWidget.h>
#include <widget/BaseWidget.h>
#include <QtWidgets/QWidget>
#include <QPushButton>

namespace widget
{
    class MainWidget : public BaseWidget{
        Q_OBJECT
    public:
        explicit MainWidget(QWidget *parent = nullptr);
        ~MainWidget() override;
    private:
        auto createButton() -> void;

        SecondWidget* m_widget_second;
        QPushButton* m_button;
    };
}
