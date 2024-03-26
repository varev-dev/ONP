//
// Created by varev on 25.03.2024.
//
#include <stdio.h>
#include "../includes/Calculator.h"

Status divide(int* numerator, const int* denominator) {
    if (*denominator == 0)
        return ERROR;
    *numerator /= *denominator;
    return OK;
}

Status condition(Stack* stack) {
    Node* lower = pop(stack, FIRST), * greater = pop(stack, FIRST),
            *compare = pop(stack, FIRST);
    int result = compare->data->value > 0;
    delete_node(compare);
    compare = result ? greater : lower;
    result ? greater = NULL : (lower = NULL);
    push(stack, compare, FIRST);
    delete_node(lower);
    delete_node(greater);
    return OK;
}

Node* max(Stack* stack, int* amount) {
    Node* result = pop(stack, FIRST);
    while (*amount > 0) {
        Node* temp = pop(stack, FIRST);
        if (result->data->value >= temp->data->value) delete_node(temp);
        else {
            delete_node(result);
            result = temp;
            temp = NULL;
        }
        (*amount)--;
    }
    return result;
}

Node* min(Stack* stack, int* amount) {
    Node* result = pop(stack, FIRST);
    while (*amount > 0) {
        Node* temp = pop(stack, FIRST);
        if (result->data->value <= temp->data->value)
            delete_node(temp);
        else {
            delete_node(result);
            result = temp;
            temp = NULL;
        }
        (*amount)--;
    }
    return result;
}

void function_execute(Stack* stack, Token* function) {
    FunctionIndex index = function->value % 10;
    if (index == IF) {
        condition(stack);
        return;
    }

    int counter = function->value / 10 - 1;
    Node* result = index == MAX ? max(stack, &counter) : min(stack, &counter);
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
        case '+': stack->first->data->value += value;
            return OK;
        case '-': stack->first->data->value -= value;
            return OK;
        case '*': stack->first->data->value *= value;
            return OK;
        case '/':
            return divide(&stack->first->data->value, &value);
        default:
            return ERROR;
    }
}

void handle_node(Stack* main, Stack* local, Node* node) {
    Status status = OK;
    switch (node->data->type) {
        case NUMBER:
            push(local, node, FIRST);
            break;
        case FUNCTION:
        case OPERATOR:
            print_node(node);
            print_stack(local);

            if (node->data->type == FUNCTION) function_execute(local, node->data);
            else status = operator_execute(local, node->data);

            if (status == ERROR) {
                printf("ERROR\n");
                delete_stack(local);
                delete_stack(main);
                return;
            }
            break;
        default:
            break;
    }
}

void calculate(Stack* stack) {
    Stack* localStack = init_stack(NULL);
    Node* node;

    while (stack->first != NULL) {
        node = pop(stack, FIRST);
        handle_node(stack, localStack, node);
    }

    print_stack(localStack);
    delete_stack(localStack);
    delete_stack(stack);
}