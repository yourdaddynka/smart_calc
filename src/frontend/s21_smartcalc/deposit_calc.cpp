#include "deposit_calc.h"

#include "mainwindow.h"
#include "ui_deposit_calc.h"

deposit_calc::deposit_calc(QWidget *parent)
    : QDialog(parent), ui(new Ui::deposit_calc) {
  ui->setupUi(this);
  connect(ui->result, SIGNAL(clicked()), this, SLOT(DeposCalc()));
}

deposit_calc::~deposit_calc() { delete ui; }
void deposit_calc::DeposCalc() {
  QString summ_input_st = ui->sum_input->toPlainText();
  QString procent_input_st = ui->procent_input->toPlainText();
  QString time_input_st = ui->time_month->toPlainText();
  QString nalog_input_st = ui->nalog_input->toPlainText();
  QString izyatiya_st = ui->izyatiya->toPlainText();
  QString popolnenya_st = ui->popolnenya->toPlainText();

  QString oper = ui->kapital->currentText();
  QString period_input_st = ui->period_viplat->currentText();

  bool ok1, ok2, ok3, ok4, ok5, ok6;
  int period_type = 0, kapital_type = 0;

  double summ_input = summ_input_st.toDouble(&ok1);
  double procent_input = procent_input_st.toDouble(&ok2);
  double time_input = time_input_st.toDouble(&ok3);
  double nalog_input = nalog_input_st.toDouble(&ok4);
  double izyatiya = izyatiya_st.toDouble(&ok5);
  double popolnenya = popolnenya_st.toDouble(&ok6);

  double depos_output = 0, nalog_out = 0, procent_out = 0;
  int result = incorect;

  if (oper == "Да")
    kapital_type = 1;
  else
    kapital_type = 0;

  if (period_input_st == "Раз в год")
    period_type = 12;
  else
    period_type = 1;

  if (ok1 && ok2 && ok3 && ok4 && ok5 && ok6) {
    result = s21_deposit(summ_input, time_input, procent_input, nalog_input,
                         period_type, popolnenya, izyatiya, kapital_type,
                         &procent_out, &nalog_out, &depos_output);
    if (result == corect) {
      ui->deposit_sum_output->setText(QString::number(depos_output, 'f', 2));
      ui->nalog_sum_output->setText(QString::number(nalog_out, 'f', 2));
      ui->pocent_output->setText(QString::number(procent_out, 'f', 2));
    } else {
      ui->deposit_sum_output->setText("ERROR");
      ui->nalog_sum_output->setText("ERROR");
      ui->pocent_output->setText("ERROR");
    }
  } else {
    ui->deposit_sum_output->setText("ERROR");
    ui->nalog_sum_output->setText("ERROR");
    ui->pocent_output->setText("ERROR");
  }
}
