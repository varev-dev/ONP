//
// Created by varev on 20.03.2024.
//
#include "../includes/Node.h"
#include <malloc.h>

Node* init_node(Token* data, Node* next) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}

void delete_node(Node* node) {
    Token* token = node->data;
    delete_token(token);
    node->next = NULL;
    node->data = NULL;
    free(node);
}