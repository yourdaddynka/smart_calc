#ifndef DEPOSIT_CALC_H
#define DEPOSIT_CALC_H

#include <QDialog>
extern "C" {
#include "../../backend/s21_smartcalc.h"
}
namespace Ui {
class deposit_calc;
}

class deposit_calc : public QDialog {
  Q_OBJECT

public:
  explicit deposit_calc(QWidget *parent = nullptr);
  ~deposit_calc();

private slots:
  void DeposCalc();

private:
  Ui::deposit_calc *ui;
};

#endif // DEPOSIT_CALC_H
