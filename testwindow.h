#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QDebug>
#include "speedometerwidget.h"


namespace Ui {
class testWindow;
}

class testWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit testWindow(QWidget *parent = 0);
    ~testWindow();

private slots:
    //void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::testWindow *ui;
    SpeedometerWidget *m_speedometerwidget,*m_speedometerwidget2;
    QProcess *process;
};

#endif // TESTWINDOW_H
