#ifndef SPEEDOMETERWIDGET_H
#define SPEEDOMETERWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>

class SpeedometerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SpeedometerWidget(QWidget *parent = nullptr);
    int get_Speed(){return m_speed;}
    void set_Speed(int speed){m_speed = speed;}
protected:
    void paintEvent(QPaintEvent *);
private:
    int m_speed;
};

#endif // SPEEDOMETERWIDGET_H
