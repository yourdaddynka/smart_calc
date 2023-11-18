#include "graps.h"

#include "mainwindow.h"
#include "ui_graps.h"

graps::graps(QWidget *parent) : QDialog(parent), ui(new Ui::graps) {
  ui->setupUi(this);
}

graps::~graps() { delete ui; }
void graps::slot(QString a) {
  m_a = a;
  connect(ui->Plot, &QPushButton::clicked, this, &graps::on_plotButton_clicked);
}

void graps::on_plotButton_clicked() {
  QString Xmin_st = ui->Xmin->toPlainText();
  QString Xmax_st = ui->Xmax->toPlainText();
  QString Ymin_st = ui->Ymin->toPlainText();
  QString Ymax_st = ui->Ymax->toPlainText();
  bool ok1, ok2, ok3, ok4;
  double Xmin = Xmin_st.toDouble(&ok1);
  double Xmax = Xmax_st.toDouble(&ok2);
  double Ymin = Ymin_st.toDouble(&ok3);
  double Ymax = Ymax_st.toDouble(&ok4);
  int flag = 0;
  if (ok1 && ok2 && ok3 && ok4) {
    if (Xmin >= Xmax) {
      Xmin = -10;
      Xmax = 10;
      ui->Xmin->setPlainText(QString::number(Xmin));
      ui->Xmax->setPlainText(QString::number(Xmin));
    }

    if (Ymin >= Ymax) {
      Ymin = -10;
      Ymax = 10;
      ui->Ymin->setPlainText(QString::number(Ymin));
      ui->Ymax->setPlainText(QString::number(Ymax));
    }

    ui->widget->xAxis->setRange(Xmin, Xmax);
    ui->widget->yAxis->setRange(Ymin, Ymax);

    int error = 0;
    double result = 0;
    QByteArray byteArray = m_a.toLocal8Bit();
    char *input_string = byteArray.data();

    x.clear();
    y.clear();
    for (int i = -100000; i < 100000; i++) {
      x.push_back(i * 0.1);
      double current_x = i * 0.1;
      error = s21_smartcalc(input_string, current_x, &result);
      y.push_back(result);
    }

    if (error == corect) {
      ui->widget->addGraph();
      ui->widget->graph(0)->setData(x, y);
      ui->widget->replot();
      ui->widget->setInteraction(QCP::iRangeZoom, true);
      ui->widget->setInteraction(QCP::iRangeDrag, true);
    } else {
      flag = 1;
    }
  } else {
    flag = 1;
  }
  if (flag == 1) {
    ui->Xmin->setPlainText("ERROR");
    ui->Xmax->setPlainText("ERROR");
    ui->Ymin->setPlainText("ERROR");
    ui->Ymax->setPlainText("ERROR");
  }
}

/*рабочий*
void graps::slot(QString a)
{
ui->widget->xAxis->setRange(-100,100);
ui->widget->yAxis->setRange(-100,100);
int error = 0;
double result = 0;
QByteArray byteArray = a.toLocal8Bit();
char *input_string = byteArray.data();

for(int i = -20; i < 20; i++) {
    x.push_back(i * 0.1);
    double current_x = i * 0.1;
    error = s21_smartcalc(input_string, current_x, &result);
    y.push_back(result);
}
if(error == corect){
ui->widget->addGraph();
ui->widget->graph(0)->setData(x, y);
ui->widget->replot();
ui->widget->setInteraction(QCP::iRangeZoom, true);
ui->widget->setInteraction(QCP::iRangeDrag, true);
}

}
*/
/*
void graps::slot(QString a)
{
    QString Xmin_st = ui->Xmin->toPlainText();
    QString Xmax_st = ui->Xmax->toPlainText();
    QString Ymin_st = ui->Ymin->toPlainText();
    QString Ymax_st = ui->Ymax->toPlainText();
    bool ok1,ok2,ok3,ok4;
    double Xmin = Xmin_st.toDouble(&ok1);
    double Xmax = Xmax_st.toDouble(&ok2);
    double Ymin = Ymin_st.toDouble(&ok3);
    double Ymax = Ymax_st.toDouble(&ok4);
    if(ok1 && ok2 && ok3 && ok4){
        if(Xmin >= Xmax){
            Xmin = -10;
            Xmax = 10;
        }
        else if(Ymin >= Ymax){
            Ymin = -10;
            Ymax = 10;
        }
        ui->widget->xAxis->setRange(Xmin,Xmax);
        ui->widget->yAxis->setRange(Ymin,Ymax);
        int error = 0;
        double result = 0;
        QByteArray byteArray = a.toLocal8Bit();
        char *input_string = byteArray.data();
        for(int i = -Ymin; i < Ymax; i++) {
            x.push_back(i * 0.1);
            double current_x = i * 0.1;
            error = s21_smartcalc(input_string, current_x, &result);
            y.push_back(result);
        }
        if(error == corect){
        ui->widget->addGraph();
        ui->widget->graph(0)->setData(x, y);
        ui->widget->replot();
        ui->widget->setInteraction(QCP::iRangeZoom, true);
        ui->widget->setInteraction(QCP::iRangeDrag, true);
        }
        else{
             ui->Xmin->setText("error");
        }
    }
}
*/
