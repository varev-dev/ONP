//
// Created by varev on 20.03.2024.
//

#ifndef ONPINC_STACK_H
#define ONPINC_STACK_H
#include <malloc.h>
#include "Node.h"

typedef struct Stack {
    Node* first;
    Node* last;
} Stack;

typedef enum ActionType {
    FIRST = 0,
    LAST
} ActionType;

Stack* init_stack(Node* node);
Node* pop(Stack* stack, ActionType type);
void push(Stack* stack, Node* node, ActionType type);
void append_stack(Stack* main, Stack* append);
void print_stack(Stack* stack);
void delete_stack(Stack* stack);

#endif //ONPINC_STACK_H
