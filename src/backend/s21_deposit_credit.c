#include "s21_smartcalc.h"

int s21_credit_ann(double summ, int time, double procent, double *all,
                   double *monthly_payment) {  // 4
  int result_work = corect;
  if (summ <= 0 || time <= 0 || procent <= 0) result_work = incorect;
  if (result_work != incorect) {
    double proc = procent / 100 / 12;
    *monthly_payment = summ * (proc / (1 - pow(1 + proc, -time)));
    for (int i = 0; i < time; i++, *all += (*monthly_payment))
      ;
  }
  return result_work;
}

int s21_credit_dif(double summ, int time, double procent, double *all,
                   double *monthly_one, double *monthly_closed) {
  int result_work = corect;
  if (summ <= 0 || time <= 0 || procent <= 0) result_work = incorect;
  if (result_work != incorect) {
    double proc = procent / 100 / 12;
    double diff_pay = 0;
    for (int i = 0; i < time; i++) {
      *all += diff_pay = (summ / time) + ((summ - i * (summ / time)) * proc);
      if (i == 0) *monthly_one = diff_pay;
      if (i == time - 1) *monthly_closed = diff_pay;
    }
  }
  return result_work;
}

int s21_deposit(double summa, int time, double procent, double nalog_procent,
                int periodichnost, double popolnenya, double izyatia,
                int kapitaliz, double *procent_out, double *nalog_summ,
                double *all_summ) {
  int result_work = corect;
  if (summa < 0 || time < 0 || procent < 0 || nalog_procent < 0 ||
      periodichnost < 0 || popolnenya < 0 || izyatia < 0)
    result_work = incorect;
  if (result_work != incorect) {
    double summ_buff = summa;
    for (int i = 0; i < time; i++) {
      double month_summ = 0;
      //если periodichnost раз в год = 12,раз в месяц 1
      if (periodichnost == 1) {
        month_summ = summ_buff * procent * 0.01 / 12;
      } else if (periodichnost == 12 && i % 11 == 0 && i > 0) {
        month_summ = summ_buff * procent * 0.01;
      }
      summ_buff =
          summ_buff + popolnenya - izyatia;  //пополнения и изъяетие раз в мес
      if (kapitaliz == 1) {
        summ_buff += month_summ;
      }
      *procent_out += month_summ;
    }
    *nalog_summ = *procent_out * nalog_procent * 0.01;
    *all_summ = summa + (*procent_out) - (*nalog_summ) +
                ((popolnenya - izyatia) * time);
  }
  return result_work;
}
