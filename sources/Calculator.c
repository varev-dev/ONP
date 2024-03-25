//
// Created by varev on 25.03.2024.
//
#include "../includes/Calculator.h"

Status function_parser(Stack* stack, Token* function) {
    return OK;
}

Status operator_parser(Stack* stack, Token* function) {
    return OK;
}

void calculate(Stack* stack) {
    Stack* localStack = init_stack(NULL);
    Node* node;
    Status status = OK;

    while (stack->first->next != NULL) {
        node = pop(stack, FIRST);

        switch (node->data->type) {
            case NUMBER:
                push(localStack, node, FIRST);
                break;
            case FUNCTION:
                function_parser(localStack, node->data);
                break;
            case OPERATOR:
                status = operator_parser(localStack, node->data);

                if (status == ERROR) {
                    // @todo error code if denominator is zero
                    return;
                }
                break;
            default:
                break;
        }
    }

}