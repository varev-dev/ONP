#include "includes/Reader.h"
#include <string.h>

int main() {
    Stack* stack = read_input(END);
    print_stack(stack);
    delete_stack(stack);
    return 0;
}
