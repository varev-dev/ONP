#include "includes/Stack.h"
#include <string.h>

int main() {
    Stack* stack = init_stack(NULL);
    char* text = malloc(16 * sizeof(char));
    strcpy(text, "8321");
    push(stack, init_node(init_token_with_value(NUMBER, text), NULL));

    text = malloc(16 * sizeof(char));
    strcpy(text, "+");
    push(stack, init_node(init_token_with_value(OPERAND, text), NULL));

    text = malloc(16 * sizeof(char));
    strcpy(text, "MIN1");
    push(stack, init_node(init_token_with_value(FUNCTION, text), NULL));

    print_stack(stack);

    pop(stack, 0);

    print_stack(stack);
    delete_stack(stack);
    return 0;
}
