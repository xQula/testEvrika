//
// Created by xqula on 01.08.24.
//

#pragma once

#include <QtWidgets/QWidget>

namespace widget
{
    struct SizeWidget
    {
        int x = 0;
        int y = 0;
    };

    class BaseWidget : public QWidget {
        Q_OBJECT
    public:
        explicit BaseWidget(QWidget *parent = nullptr) : QWidget(parent) {}
        ~BaseWidget() override = default;
    protected:
        auto setSize(const SizeWidget &size) -> void;
        auto createLayot(QWidget *element) -> void;
    };
}