#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qcustomplot.h>

#include <QMainWindow>

#include "credit_calc.h"
#include "deposit_calc.h"
#include "graps.h"
extern "C" {
#include "../../backend/s21_smartcalc.h"
}
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  graps *graphs;
  credit_calc *CrCalc;
  deposit_calc *DeCalc;

signals:
  void signal(QString a);

private slots:
  void digits_numbers();
  void dot_clicked();
  void on_pushButton_phony_clicked();
  void on_pushButton_AC_clicked();
  void on_pushButton_X_clicked();
  void math_operations();
  void trigon_operations();
  void on_pushButton_graph_clicked();
  void on_pushButton_deposit_clicked();
  void on_pushButton_credit_clicked();
};
#endif // MAINWINDOW_H
