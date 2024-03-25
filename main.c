#include "includes/Reader.h"
#include <stdio.h>

int main() {
    unsigned short expressions;
    scanf("%hd", &expressions);

    while (expressions > 0) {
        Stack* stack = read_input(END, 0);
        print_stack(stack);
        delete_stack(stack);
        expressions--;
    }

    return 0;
}
