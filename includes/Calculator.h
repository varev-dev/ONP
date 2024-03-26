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
Status divide(int* numerator, const int* denominator);
Status condition(Stack* stack);
Node* max(Stack* stack, int* amount);
Node* min(Stack* stack, int* amount);

#endif //ONPINC_CALCULATOR_H
