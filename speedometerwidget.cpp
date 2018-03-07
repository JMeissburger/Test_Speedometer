#include "speedometerwidget.h"

SpeedometerWidget::SpeedometerWidget(QWidget *parent) : QWidget(parent)
{
    m_speed=0;
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(100);
    setWindowTitle(tr("Speedometer"));
    resize(600,600);
}

void SpeedometerWidget::paintEvent(QPaintEvent *)
{
    QColor backgroudColor(46, 52, 54);
    QColor black(0, 0, 0);
    QPoint center_point(0,0);
    QPen pen;
    static const QPoint speedHand[3] = {
        QPoint(3, 8),
        QPoint(-3, 8),
        QPoint(0, -250)
    };
    int side =qMin(width(),height());

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(black);
    painter.drawRect(0,0,width(),height());
    painter.translate(width() / 2, height() / 2);
    painter.scale(side/600.0,side/600.0);

    painter.setBrush(backgroudColor);
    pen.setColor(Qt::white);
    pen.setWidth(1);
    painter.setPen(pen);
    painter.drawEllipse(center_point,290,290);

    painter.setBrush(Qt::red);
    pen.setColor(Qt::red);
    pen.setWidth(1);
    painter.setPen(pen);

    painter.save();
    painter.rotate(1.125*get_Speed() - 135);
    painter.drawConvexPolygon(speedHand,3);
    painter.restore();



    pen.setColor (Qt::white);
    pen.setWidth (8);
    painter.setPen(pen);
    for (int i = 0; i < 16; ++i)
    {
        if(i < 3 || i>5)
        {
         painter.drawLine(250,0,280,0);

        }
        painter.rotate(22.5);
    }
    pen.setWidth (2);
    painter.setPen(pen);
    painter.rotate(11.25);
    for (int j = 0; j < 16; ++j)
    {
        if(j < 2 || j>5)
        {
           painter.drawLine(260, 0, 270, 0);
        }
        painter.rotate(22.5);
    }
    painter.rotate(-11.25);

    painter.drawText(-170,170,"0");
    painter.drawText(-220,95,"20");
    painter.drawText(-240,4,"40");
    painter.drawText(-220,-85,"60");
    painter.drawText(-170,-160,"80");
    painter.drawText(-90,-210,"100");
    painter.drawText(-15,-225,"120");
    painter.drawText(75,-210,"140");
    painter.drawText(150,-155,"160");
    painter.drawText(195,-85,"180");
    painter.drawText(215,4,"200");
    painter.drawText(195,95,"220");
    painter.drawText(150,170,"240");

}
