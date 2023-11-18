#include "s21_smartcalc.h"

void push_operations(Operations **base, char data, int priority) {
  Operations *list_operations = malloc(sizeof(Operations));
  if (list_operations != NULL) {
    list_operations->data = data;
    list_operations->priority = priority;
    list_operations->next = *base;
    *base = list_operations;
  }
}

char pop_operations(Operations **head) {
  Operations *temp = *head;
  char buf_oper = temp->data;
  *head = (*head)->next;
  free(temp);
  return buf_oper;
}

double pop_number(Numbers **base) {
  Numbers *temp_base = *base;
  double buf_num = temp_base->data;
  *base = temp_base->next;
  free(temp_base);
  return buf_num;
}

void push_number(Numbers **base, double data) {
  Numbers *list_numbers = malloc(sizeof(Numbers));
  if (list_numbers != NULL) {
    list_numbers->data = data;
    list_numbers->next = *base;
    *base = list_numbers;
  }
}
