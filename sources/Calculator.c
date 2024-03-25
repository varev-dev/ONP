//
// Created by varev on 25.03.2024.
//
#include <stdio.h>
#include "../includes/Calculator.h"

void function_execute(Stack* stack, Token* function) {
    FunctionIndex index = function->value % 10;
    if (index == IF) {
        Node* lower = pop(stack, FIRST), * greater = pop(stack, FIRST),
            *compare = pop(stack, FIRST);
        int result = compare->data->value > 0;
        delete_node(compare);
        compare = result ? greater : lower;
        result ? greater = NULL : (lower = NULL);
        push(stack, compare, FIRST);
        delete_node(lower);
        delete_node(greater);
        return;
    }

    int counter = function->value / 10 - 1;
    Node* result = pop(stack, FIRST);

    if (index == MAX) {
        while (counter > 0) {
            Node* temp = pop(stack, FIRST);
            if (result->data->value >= temp->data->value) delete_node(temp);
            else {
                delete_node(result);
                result = temp;
                temp = NULL;
            }
            counter--;
        }
    } else {
        while (counter > 0) {
            Node* temp = pop(stack, FIRST);
            if (result->data->value <= temp->data->value) delete_node(temp);
            else {
                delete_node(result);
                result = temp;
                temp = NULL;
            }
            counter--;
        }
    }
    push(stack, result, FIRST);
}

Status operator_execute(Stack* stack, Token* operator) {
    if ((char) operator->value == 'N') {
        stack->first->data->value *= -1;
        return OK;
    }

    Node* b = pop(stack, FIRST);
    int value = b->data->value;
    delete_node(b);
    switch ((char) operator->value) {
        case '+':
            stack->first->data->value += value;
            break;
        case '-':
            stack->first->data->value -= value;
            break;
        case '*':
            stack->first->data->value *= value;
            break;
        case '/':
            if (value == 0)
                return ERROR;
            stack->first->data->value /= value;
            break;
    }
    return OK;
}

void calculate(Stack* stack) {
    Stack* localStack = init_stack(NULL);
    Node* node;
    Status status = OK;

    while (stack->first != NULL) {
        node = pop(stack, FIRST);

        switch (node->data->type) {
            case NUMBER:
                push(localStack, node, FIRST);
                break;
            case FUNCTION:
            case OPERATOR:
                print_node(node);
                print_stack(localStack);

                if (node->data->type == FUNCTION) function_execute(localStack, node->data);
                else status = operator_execute(localStack, node->data);

                if (status == ERROR) {
                    printf("ERROR\n");
                    delete_stack(localStack);
                    delete_stack(stack);
                    return;
                }
                break;
            default:
                break;
        }
    }

    print_stack(localStack);
    delete_stack(localStack);
    delete_stack(stack);
}