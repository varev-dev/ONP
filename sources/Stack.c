//
// Created by varev on 20.03.2024.
//
#include <stdio.h>
#include "../includes/Stack.h"

Stack* init_stack(Node* node) {
    Stack* stack = malloc(sizeof(Stack));
    stack->first = node;
    stack->last = node;
    return stack;
}

Node* pop(Stack* stack, ActionType type) {
    Node* node = stack->first;

    if (node == NULL || node->next == NULL || type == FIRST) {
        stack->first = NULL;
        if (node != NULL) {
            stack->first = node->next;
            node->next = NULL;
        }
        return node;
    }

    while (node->next->next != NULL) {
        node = node->next;
    }

    stack->last = node;
    node->next = NULL;

    return node->next;
}

void push(Stack* stack, Node* node, ActionType type) {
    if (stack->first == NULL) {
        stack->first = node;
        stack->last = node;
        return;
    }
    if (type == FIRST) {
        node->next = stack->first;
        stack->first = node;
        return;
    }

    stack->last->next = node;
    stack->last = node;
}

/**
 * @todo consider adding first node to main & not iterate over whole stack
 */
void append_stack(Stack* main, Stack* append) {
    Node* node;
    while (append->first != NULL) {
        node = pop(append, FIRST);
        push(main, node, LAST);
    }
    node = NULL;
}

void print_stack(Stack* stack) {
    Node* node = stack->first;

    while (node != NULL) {
        print_node(node);
        node = node->next;
    }

    printf("\n");
}

void delete_stack(Stack* stack) {
    Node* node = stack->first;

    while (node != NULL) {
        stack->first = node->next;
        delete_node(node);
        node = stack->first;
    }
}