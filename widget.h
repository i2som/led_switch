#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void exit_app(void);
    void led_on(bool);
    void led_off(bool);



private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
