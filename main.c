#include "includes/Reader.h"
#include "includes/Calculator.h"
#include <stdio.h>

int main() {
    unsigned short expressions;
    scanf("%hu", &expressions);

    while (expressions > 0) {
        Stack* stack = init_stack(NULL);
        read_input(stack, END, 0);
        print_stack(stack);
        calculate(stack);
        putchar('\n');
        expressions--;
    }

    return 0;
}
