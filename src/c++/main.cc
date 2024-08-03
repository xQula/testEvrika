#include <QApplication>
#include <widget/mainWidget.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    widget::MainWidget widget;
    return QApplication::exec();
}
