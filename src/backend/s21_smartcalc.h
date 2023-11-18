#ifndef S21_SMARTCALC_H
#define S21_SMARTCALC_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define corect 0
#define incorect 1
typedef struct op_stack {
  char data;
  int priority;
  struct op_stack *next;
} Operations;

typedef struct num_stack {
  double data;
  struct num_stack *next;
} Numbers;

/* операции со стеком */

void push_operations(Operations **base, char data, int priority);
char pop_operations(Operations **head);
double pop_number(Numbers **base);
void push_number(Numbers **base, double data);

/* вспомогательные функции */

int s21_priority(char p);
int is_num(char symbol);
int is_op(char symbol);
void num_entry(char *input_string, int *i, char *postfix, int *postfix_index);
void postfix_create(char *postfix, int *postfix_index, Operations **op_stack);
int check_postfix(char *postfix);
void funk_create(const char *input_string, char *res_string);
void double_string(char *string, double result);
void s21_unarniy_minus(char *validation_string, char *calculation_string);

/* основные функции */

int infix_to_postfix(char *input_string, char *postfix);
double s21_func_calc(char symbol, Numbers **num_stack);
double calculation(char *postfix, double x);
int s21_smartcalc(char *input_string, double x, double *result);

/* кредитный и депозитный */

int s21_credit_ann(double summ, int time, double procent, double *all,
                   double *monthly_payment);
int s21_credit_dif(double summ, int time, double procent, double *all,
                   double *monthly_one, double *monthly_closed);
int s21_deposit(double summa, int time, double procent, double nalog_procent,
                int periodichnost, double popolnenya, double izyatia,
                int kapitaliz, double *procent_out, double *nalog_summ,
                double *all_summ);

#endif
