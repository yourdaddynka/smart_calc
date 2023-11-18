#ifndef GRAPS_H
#define GRAPS_H

#include <qcustomplot.h>

#include <QDialog>
#include <QVector>
extern "C" {
#include "../../backend/s21_smartcalc.h"
}
namespace Ui {
class graps;
}

class graps : public QDialog {
  Q_OBJECT

public:
  explicit graps(QWidget *parent = nullptr);
  ~graps();

private:
  Ui::graps *ui;
  QVector<double> x, y;
  QString m_a;

public slots:
  void slot(QString a);
  void on_plotButton_clicked();
};

#endif // GRAPS_H
