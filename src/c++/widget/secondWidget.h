//
// Created by xqula on 01.08.24.
//

#pragma once

#include <QLabel>
#include <widget/BaseWidget.h>

namespace widget
{
    class SecondWidget : public BaseWidget{
        Q_OBJECT
    public:
        explicit SecondWidget(QWidget *parent = nullptr);
    private:
        QLabel* m_label;
    };
}
