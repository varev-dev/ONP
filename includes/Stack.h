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

typedef enum PopType {
    FIRST = 0,
    LAST = 1
} PopType;

Stack* init_stack(Node* node);
Node* pop(Stack* stack, PopType type);
void push(Stack* stack, Node* node);
void print_stack(Stack* stack);
void delete_stack(Stack* stack);

#endif //ONPINC_STACK_H
