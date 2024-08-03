#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}