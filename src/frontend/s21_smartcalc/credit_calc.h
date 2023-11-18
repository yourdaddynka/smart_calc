#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <QDialog>

extern "C" {
#include "../../backend/s21_smartcalc.h"
}
namespace Ui {
class credit_calc;
}

class credit_calc : public QDialog {
  Q_OBJECT

public:
  explicit credit_calc(QWidget *parent = nullptr);
  ~credit_calc();

private slots:
  void CreditCalc();

private:
  Ui::credit_calc *ui;
};

#endif // CREDIT_CALC_H
