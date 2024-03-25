//
// Created by varev on 25.03.2024.
//

#ifndef ONPINC_CALCULATOR_H
#define ONPINC_CALCULATOR_H
#include "Stack.h"

typedef enum Status {
    ERROR,
    OK
} Status;

void calculate(Stack* stack);
Status divide(int* numerator, int* denominator);
Status multiply(int* a, int* b);
Status subtract(int* a, int* b);
Status sum(int* a, int* b);
Status condition(int* compare, int* greater, int* smaller);
Status max(Stack* stack, int* amount);
Status min(Stack* stack, int* amount);

#endif //ONPINC_CALCULATOR_H
