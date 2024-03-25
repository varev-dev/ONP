#include "includes/Reader.h"
#include "includes/Calculator.h"
#include <stdio.h>

int main() {
    unsigned short expressions;
    scanf("%hd", &expressions);

    while (expressions > 0) {
        Stack* stack = read_input(END, 0);
        print_stack(stack);
        calculate(stack);
        printf("\n");
        expressions--;
    }

    return 0;
}
