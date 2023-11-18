#include "credit_calc.h"

#include "mainwindow.h"
#include "ui_credit_calc.h"

credit_calc::credit_calc(QWidget *parent)
    : QDialog(parent), ui(new Ui::credit_calc) {
  ui->setupUi(this);
  connect(ui->pushButton_result, SIGNAL(clicked()), this, SLOT(CreditCalc()));
}

credit_calc::~credit_calc() { delete ui; }

void credit_calc::CreditCalc() {
  QString summ_input = ui->summ_input->toPlainText();
  QString pricent_input = ui->pricent_input->toPlainText();
  QString time_input = ui->time_input->toPlainText();
  QString oper = ui->comboBox->currentText();
  bool ok1, ok2, ok3, credit_type;
  double summ = summ_input.toDouble(&ok1);
  double pricent = pricent_input.toDouble(&ok2);
  double time = time_input.toDouble(&ok3);
  double all_summ = 0, monthy_payment = 0, monthy_one = 0, monthy_closed = 0;
  int result = incorect, flag = 0;
  if (oper == "аннуитентный")
    credit_type = true;
  else
    credit_type = false;

  if (ok1 && ok2 && ok3) {
    if (credit_type) {
      result = s21_credit_ann(summ, time, pricent, &all_summ, &monthy_payment);
    } else {
      result = s21_credit_dif(summ, time, pricent, &all_summ, &monthy_one,
                              &monthy_closed);
    }
    if (result == corect) {
      ui->All_sum->setText(QString::number(all_summ, 'f', 2));
      ui->pereplata->setText(QString::number((all_summ - summ), 'f', 2));
      ui->one_month_diff->setText(
          QString::number((credit_type ? 0 : monthy_one), 'f', 2));
      ui->closed_month_diff->setText(
          QString::number((credit_type ? 0 : monthy_closed), 'f', 2));
      ui->month_money->setText(QString::number(monthy_payment, 'f', 2));
    } else {
      flag = 1;
    }
  } else {
    flag = 1;
  }
  if (flag == 1) {
    ui->All_sum->setText("ERROR");
    ui->month_money->setText("ERROR");
    ui->pereplata->setText("ERROR");
    ui->one_month_diff->setText("ERROR");
    ui->closed_month_diff->setText("ERROR");
  }
}
