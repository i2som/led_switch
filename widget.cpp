#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->exit_btn, &QPushButton::pressed, this, &Widget::exit_app);
    connect(ui->led_on_btn, &QRadioButton::clicked, this, &Widget::led_on);
    connect(ui->led_off_btn, &QRadioButton::clicked, this, &Widget::led_off);

    QFile inputFile("/sys/class/leds/user1/brightness");
    int led_pre_status;
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       led_pre_status = in.readLine().toInt();
       inputFile.close();
    }
    qDebug() << led_pre_status;
    if(led_pre_status){
        ui->led_on_btn->setChecked(true);
        ui->led_status->setText("LED ON");
    }else {
        ui->led_off_btn->setChecked(true);
        ui->led_status->setText("LED OFF");
    }


}

Widget::~Widget()
{
    delete ui;
}

void Widget::exit_app(void)
{
    qApp->exit();
}

void Widget::led_on(bool b)
{
    system("echo 1 > /sys/class/leds/user1/brightness");
    ui->led_status->setText("LED ON");

}

void Widget::led_off(bool b)
{
    system("echo 0 > /sys/class/leds/user1/brightness");
    ui->led_status->setText("LED OFF");

}
