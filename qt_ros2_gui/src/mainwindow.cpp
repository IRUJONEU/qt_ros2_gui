#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::handleButton);

    node = std::make_shared<rclcpp::Node>("qt_ros2_gui");

    subscription = node->create_subscription<std_msgs::msg::String>(
        "input_topic", 10,
        std::bind(&MainWindow::subscriptionCallback, this, std::placeholders::_1));

    publisher = node->create_publisher<std_msgs::msg::String>("output_topic", 10);

    std::thread([this]()
                { rclcpp::spin(this->node); })
        .detach();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton()
{
    qDebug() << "Button clicked!";

    auto message = std_msgs::msg::String();
    message.data = "Button clicked!";
    publisher->publish(message);
}

void MainWindow::subscriptionCallback(const std_msgs::msg::String::SharedPtr msg)
{
    QMetaObject::invokeMethod(this, "updateLabel", Qt::QueuedConnection,
                              Q_ARG(QString, QString::fromStdString(msg->data)));
}

void MainWindow::updateLabel(const QString &message)
{
    ui->label->setText(message);
}