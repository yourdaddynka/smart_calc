#include "s21_smartcalc.h"

int infix_to_postfix(char *input_string, char *postfix) {
  Operations *op_stack = NULL;
  int postfix_index = 0;
  int open_brackets = 0;
  int error_flag = corect;
  for (int i = 0; i < (int)strlen(input_string); i++) {
    if (is_num(input_string[i])) {
      num_entry(input_string, &i, postfix, &postfix_index);
    } else if (input_string[i] == '(') {
      open_brackets++;
      push_operations(&op_stack, input_string[i],
                      s21_priority(input_string[i]));
    } else if (input_string[i] == ')') {
      if (open_brackets > 0) {
        open_brackets--;
        while (op_stack != NULL && op_stack->data != '(') {
          postfix_create(postfix, &postfix_index, &op_stack);
        }
        pop_operations(&op_stack);
      } else {
        error_flag = incorect;
        break;
      }
    } else {
      while (op_stack != NULL &&
             s21_priority(op_stack->data) >= s21_priority(input_string[i])) {
        postfix_create(postfix, &postfix_index, &op_stack);
      }
      push_operations(&op_stack, input_string[i],
                      s21_priority(input_string[i]));
    }
  }
  error_flag = open_brackets == 0 ? error_flag : incorect;
  if (error_flag == corect) {
    while (op_stack != NULL) {
      postfix_create(postfix, &postfix_index, &op_stack);
    }
    if (is_op(input_string[strlen(input_string) - 1])) {
      error_flag = incorect;
    }
  }
  postfix[postfix_index] = '\0';
  if (error_flag == corect) {
    error_flag = check_postfix(postfix);
  }
  return error_flag;
}

double s21_func_calc(char symbol, Numbers **num_stack) {
  double calc_res = 0.0;
  double num_calc1 = pop_number(num_stack);
  if (symbol == 'a')
    calc_res = sin(num_calc1);  // sin
  else if (symbol == 'b')
    calc_res = cos(num_calc1);  // cos
  else if (symbol == 'c')
    calc_res = tan(num_calc1);  // tg
  else if (symbol == 'd')
    calc_res = asin(num_calc1);  // asin
  else if (symbol == 'e')
    calc_res = acos(num_calc1);  // acos
  else if (symbol == 'f')
    calc_res = atan(num_calc1);  // atg
  else if (symbol == 'g')
    calc_res = sqrt(num_calc1);  // sqtr
  else if (symbol == 'h')
    calc_res = log(num_calc1);  // ln
  else if (symbol == 'i')
    calc_res = log10(num_calc1);  // log
  if (symbol == '^' || symbol == '%' || symbol == '+' || symbol == '-' ||
      symbol == '*' || symbol == '/') {
    double num_calc2 = pop_number(num_stack);
    if (symbol == '^')
      calc_res = powl(num_calc2, num_calc1);  // pow
    else if (symbol == '%')
      calc_res = fmod(num_calc2, num_calc1);  // fmod
    else if (symbol == '+')
      calc_res = num_calc2 + num_calc1;
    else if (symbol == '-')
      calc_res = num_calc2 - num_calc1;
    else if (symbol == '*')
      calc_res = num_calc2 * num_calc1;
    else if (symbol == '/')
      calc_res = num_calc2 / num_calc1;
  }
  return calc_res;
}

double calculation(char *postfix, double x) {
  Numbers *num_stack = NULL;
  double calc_res = 0;
  double num = 0;
  for (int i = 0; i < (int)strlen(postfix); i++) {
    num = 0;
    if (postfix[i] == 'x')
      push_number(&num_stack, x);
    else if (is_num(postfix[i])) {
      num = atof(&postfix[i]);
      for (; is_num(postfix[i]); i++)
        ;
      i--;
      push_number(&num_stack, num);
    } else if (is_op(postfix[i])) {
      calc_res = s21_func_calc(postfix[i], &num_stack);
      push_number(&num_stack, calc_res);
    }
  }
  return calc_res;
}

int s21_smartcalc(char *input_string, double x, double *result) {
  int error = incorect;
  char input_valid[2000] = {0};
  funk_create(input_string, input_valid);
  char unar_string[2000] = {0};
  s21_unarniy_minus(input_valid, unar_string);
  char res_string[2000] = {0};
  if (infix_to_postfix(unar_string, res_string) == corect) {
    int space_count = 0;
    for (int i = 0; i < (int)strlen(res_string); ++i) {
      if (res_string[i] == ' ') {
        space_count++;
      }
    }
    if (space_count == 1) {
      *result = atof(res_string);
    } else {
      *result = calculation(res_string, x);
    }
    error = corect;
    if (isnan(*result) || isinf(*result)) error = incorect;
  }
  return error;
}