#include "s21_smartcalc.h"

int s21_priority(char p) {
  int result = 10;
  if (p == '(' || p == ')')
    result = 1;
  else if ((p >= '0' && p <= '9') || p == 'x' || p == ' ' || p == '.')
    result = 0;
  else if (p == '-' || p == '+')
    result = 2;
  else if (p == '*' || p == '/' || p == '%' || p == '^')
    result = 3;
  else if ((p >= 'a' && p <= 'i'))
    result = 4;
  return result;
}

int is_num(char symbol) {
  return ((symbol >= '0' && symbol <= '9') || symbol == '.' || symbol == 'x')
             ? 1
             : 0;
}

int is_op(char symbol) {
  return ((symbol >= 'a' && symbol <= 'i') || symbol == '+' || symbol == '-' ||
          symbol == '/' || symbol == '*' || symbol == '%' || symbol == '^')
             ? 1
             : 0;
}

void num_entry(char *input_string, int *i, char *postfix, int *postfix_index) {
  while (is_num(input_string[*i])) {
    postfix[*postfix_index] = input_string[*i];
    *postfix_index += 1;
    *i += 1;
  }
  postfix[*postfix_index] = ' ';
  *postfix_index += 1;
  *i -= 1;
}

void postfix_create(char *postfix, int *postfix_index, Operations **op_stack) {
  postfix[(*postfix_index)++] = pop_operations(op_stack);
  postfix[(*postfix_index)++] = ' ';
}

int check_postfix(char *postfix) {
  int error = corect;
  for (int i = 0; i < (int)strlen(postfix); i++) {
    if (s21_priority(postfix[i]) == 1 || s21_priority(postfix[i]) == 10)
      error = incorect;
  }
  return error;
}

void funk_create(const char *input_string, char *res_string) {
  int res_idx = 0;
  for (int i = 0; i < (int)strlen(input_string); i++) {
    if (strncmp(&input_string[i], "asin", 4) == 0) {
      res_string[res_idx++] = 'd';
      i += 3;
    } else if (strncmp(&input_string[i], "acos", 4) == 0) {
      res_string[res_idx++] = 'e';
      i += 3;
    } else if (strncmp(&input_string[i], "atan", 4) == 0) {
      res_string[res_idx++] = 'f';
      i += 3;
    } else if (strncmp(&input_string[i], "sqrt", 4) == 0) {
      res_string[res_idx++] = 'g';
      i += 3;
    } else if (strncmp(&input_string[i], "ln", 2) == 0) {
      res_string[res_idx++] = 'h';
      i += 1;
    } else if (strncmp(&input_string[i], "log", 3) == 0) {
      res_string[res_idx++] = 'i';
      i += 2;
    } else if (strncmp(&input_string[i], "mod", 3) == 0) {
      res_string[res_idx++] = '%';
      i += 2;
    } else if (strncmp(&input_string[i], "sin", 3) == 0) {  //
      res_string[res_idx++] = 'a';
      i += 2;
    } else if (strncmp(&input_string[i], "cos", 3) == 0) {  //
      res_string[res_idx++] = 'b';
      i += 2;
    } else if (strncmp(&input_string[i], "tan", 3) == 0) {  //
      res_string[res_idx++] = 'c';
      i += 2;
    } else {
      res_string[res_idx++] = input_string[i];
    }
  }
  res_string[res_idx] = '\0';
}

void s21_unarniy_minus(char *validation_string, char *calculation_string) {
  int j = 0;
  for (int i = 0; i < (int)strlen(validation_string); i++) {
    if (validation_string[i] == '-' &&
        (i == 0 || strchr("(+-*/^%", validation_string[i - 1]) != NULL)) {
      if (validation_string[i + 1] == '-') {
        calculation_string[j++] = '+';
        i++;
      } else {
        calculation_string[j++] = '0';
        calculation_string[j++] = '-';
      }
    } else {
      calculation_string[j++] = validation_string[i];
    }
  }
  calculation_string[j] = '\0';
}

void double_string(char *string, double result) {
  snprintf(string, 20, "%.7lf", result);
}