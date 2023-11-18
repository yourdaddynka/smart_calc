#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QtCore>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  //
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(dot_clicked()));
  connect(ui->pushButton_AC, SIGNAL(clicked()), this,
          SLOT(on_pushButton_AC_clicked()));
  //
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui->pushButton_sum, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_open_bracket, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  connect(ui->pushButton_closed_bracket, SIGNAL(clicked()), this,
          SLOT(math_operations()));
  //
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(trigon_operations()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(trigon_operations()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(trigon_operations()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(trigon_operations()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(trigon_operations()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(trigon_operations()));
  //
}
MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui->result_show->text();
  int len = ui->result_show->text().length();
  if (len > 0) {
    QChar last_char = ui->result_show->text().at(len - 1);
    if (last_char != ')' && last_char != 'x')
      new_label += button->text();
  } else
    new_label += button->text();
  ui->result_show->setText(new_label);
}

void MainWindow::dot_clicked() {
  int len = ui->result_show->text().length();
  char *str = new char(ui->result_show->text().length());
  int flag = 0;
  QChar last_char = '\0';
  if (len > 0) {
    last_char = ui->result_show->text().at(len - 1);

    QByteArray tmp = ui->result_show->text().toLatin1();
    strlcpy(str, tmp, ui->result_show->text().length() + 1);

    for (int i = 0; i < len; i++) {
      flag = (str[i] == '.') ? 1
             : (!(std::isdigit(str[i])) && str[i] != '.' && str[i] != 'x')
                 ? 0
                 : flag;
      if (!last_char.isDigit())
        flag = 1;
    }

    if (flag == 0)
      ui->result_show->setText(ui->result_show->text() + ".");
    if (str)
      delete (str);
  }
}

void MainWindow::math_operations() {
  QPushButton *button = (QPushButton *)sender();
  QString math_op_st = ui->result_show->text();
  int openBr = math_op_st.count('(');
  int closedBr = math_op_st.count(')');
  int len = ui->result_show->text().length();
  if (len > 0) {
    QChar last_char = ui->result_show->text().at(len - 1);
    if (button->text() == "%" &&
        (last_char.isDigit() || last_char == ')' || last_char == 'x'))
      math_op_st += "%";

    else if (button->text() == "aˆb" &&
             (last_char.isDigit() || last_char == ')' || last_char == 'x'))
      math_op_st += "^";

    else if ((button->text() == "sqrt" || button->text() == "ln" ||
              button->text() == "log") &&
             !last_char.isDigit() && last_char != ')' && last_char != '.' &&
             last_char != 'x')
      math_op_st += button->text() + "(";

    else if (button->text() == '(' && !last_char.isDigit() &&
             last_char != ')' && last_char != '.' && last_char != 'x')
      math_op_st += button->text();

    else if ((button->text() == "+" || button->text() == "*") &&
             (last_char.isDigit() || last_char == ')' || last_char == 'x'))
      math_op_st += button->text();

    else if (button->text() == "÷" &&
             (last_char.isDigit() || last_char == ')' || last_char == 'x'))
      math_op_st += "/";

    else if (button->text() == "-" || last_char.isDigit() || last_char == ')' ||
             last_char == 'x')
      math_op_st += button->text();

    else if (button->text() == ')' && (openBr - closedBr > 0) &&
             (last_char.isDigit() || last_char == ')' || last_char == 'x'))
      math_op_st += button->text();
  } else if (len == 0) {
    if (button->text() == "(")
      math_op_st += button->text();
    else if (button->text() == '-')
      math_op_st += "0" + button->text();
    else if (button->text() == "log" || button->text() == "ln" ||
             button->text() == "sqrt")
      math_op_st += button->text() + "(";
  }
  ui->result_show->setText(math_op_st);
}

void MainWindow::trigon_operations() {
  QPushButton *button = (QPushButton *)sender();
  QString trig_op_st = ui->result_show->text();
  int len = ui->result_show->text().length();
  if (len > 0) {
    QChar last_char = ui->result_show->text().at(len - 1);
    if (!last_char.isDigit() && last_char != ')' && last_char != 'x' &&
        last_char != '.')
      trig_op_st += button->text() + "(";
  } else
    trig_op_st += button->text() + "(";

  ui->result_show->setText(trig_op_st);
}

void MainWindow::on_pushButton_AC_clicked() { ui->result_show->clear(); }

void MainWindow::on_pushButton_X_clicked() {
  int len = ui->result_show->text().length();
  QString x_string = ui->result_show->text();
  if (len > 0) {
    QChar last_char = ui->result_show->text().at(len - 1);
    if (!last_char.isDigit() && last_char != '.' && last_char != ')' &&
        last_char != 'x')
      x_string += "x";
  } else
    x_string += "x";
  ui->result_show->setText(x_string);
}

void MainWindow::on_pushButton_phony_clicked() {
  QString x_label_st = ui->label_x->toPlainText();
  if (x_label_st == "")
    x_label_st = "0";
  QString input_str = ui->result_show->text();
  bool ok;
  int result_work = corect;
  double x_label = x_label_st.toDouble(&ok);
  int BrSum = input_str.count('(') - input_str.count(')');
  double result = 0;
  for (int i = 0; i < BrSum && BrSum >= 0; i++) {
    input_str += ")";
  }
  QByteArray string = input_str.toLocal8Bit();
  char *input_string = string.data();
  if (ok) {
    result_work = s21_smartcalc(input_string, x_label, &result);
    if (result_work == incorect)
      ui->result_show->setText("INCORRECT");
    else {
      char res[20] = {'\0'};
      double_string(res, result);
      ui->result_show->setText(res);
    }
  } else
    ui->result_show->setText("INCORRECT");
}

void MainWindow::on_pushButton_graph_clicked() {
  graphs = new graps(this);
  if (graphs->isVisible()) {
    graphs->close();
  } else
    graphs->show();
  connect(this, &MainWindow::signal, graphs, &graps::slot);
  QString currentString = ui->result_show->text();
  emit signal(currentString);
}

void MainWindow::on_pushButton_deposit_clicked() {
  DeCalc = new deposit_calc(this);
  DeCalc->show();
}

void MainWindow::on_pushButton_credit_clicked() {
  CrCalc = new credit_calc(this);
  CrCalc->show();
}
