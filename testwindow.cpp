#include "testwindow.h"
#include "ui_testwindow.h"

testWindow::testWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testWindow)
{
    ui->setupUi(this);
    m_speedometerwidget = new SpeedometerWidget(this);
    m_speedometerwidget2 = new SpeedometerWidget(this);
    m_speedometerwidget->resize(400,400);
    m_speedometerwidget2->resize(400,400);
    m_speedometerwidget2->move(450,0);

    process = new QProcess(this);
    connect (process, SIGNAL(readyReadStandardOutput()), this, SLOT(on_pushButton_clicked()));
    connect (process, SIGNAL(readyReadStandardError()), this, SLOT(on_pushButton_clicked()));
}

testWindow::~testWindow()
{
    delete ui;
}

void testWindow::on_horizontalSlider_valueChanged(int value)
{
    m_speedometerwidget->set_Speed(value);
}

void testWindow::on_pushButton_clicked()
{
    QString out,out2;
    bool ok=false;
    process->start("python3 ../Test_Speedometer/compteur.py");
    out = process->readAllStandardOutput();
    out2 = process->readAllStandardError();
    m_speedometerwidget2->set_Speed(out.toInt(&ok,10));
}
