//
// Created by varev on 24.03.2024.
//
#include "../includes/Reader.h"
#include <stdio.h>

int compare_significance(Node* node, char* operand) {
    return significance(node->data->value) > significance(operand);
}

void append_negations(Stack* main, Stack* operands) {
    Node* node;
    while(operands->first != NULL && *operands->first->data->value == 'N') {
        node = pop(operands, FIRST);
        push(main, node, LAST);
    }
    node = NULL;
}

/**
 * @todo operand comparison & appending to top of the stack
 */
Stack* read_input(Tag endTag) {
    Stack* main = init_stack(NULL), * operands = init_stack(NULL);
    Token* token = NULL;
    char input = '\0';

    while (input != endTag) {
        print_stack(main);
        scanf("%c", &input);
        if (input == DIVIDER) {
            push(main, init_node(token, NULL), LAST);
            if (token->type != OPERAND) append_negations(main, operands);
            token = NULL;
        } else if (input >= '0' && input <= '9') {
            if (token == NULL) token = init_token_with_value(NUMBER, &input);
            else append_to_token(token, &input);
        } else if (significance(&input)) {
            token = init_token_with_value(OPERAND, &input);

            if (operands->first == NULL) {
                push(operands, init_node(token, NULL), FIRST);
                continue;
            }

            if (compare_significance(operands->first, &input)) {
                Node* node = pop(operands,FIRST);
                push(main, node, LAST);
            }
        }
    }

    return main;
}

