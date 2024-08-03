#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButton();
    void updateLabel(const QString &message);

private:
    Ui::MainWindow *ui;
    std::shared_ptr<rclcpp::Node> node;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
    void subscriptionCallback(const std_msgs::msg::String::SharedPtr msg);
};

#endif // MAINWINDOW_H