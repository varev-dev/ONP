//
// Created by varev on 20.03.2024.
//
#include "../includes/Node.h"
#include <malloc.h>
#include <stdio.h>

Node* init_node(Token* data, Node* next) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}

void print_node(Node* node) {
    FunctionIndex index;
    switch (node->data->type) {
        case NUMBER:
            printf("%d ", node->data->value);
            break;
        case OPERATOR:
            putchar(node->data->value);
            putchar(' ');
            break;
        case FUNCTION:
            index = node->data->value % 10;
            if (index == IF) {
                printf("IF ");
                break;
            }
            if (index == MIN)
                printf("MIN");
            else if (index == MAX)
                printf("MAX");
            printf("%d ", node->data->value / 10);
            break;
        default:
            break;
    }
}

void delete_node(Node* node) {
    if (node == NULL)
        return;
    Token* token = node->data;
    delete_token(token);
    node->next = NULL;
    node->data = NULL;
    free(node);
}