//
// Created by varev on 20.03.2024.
//

#ifndef ONPINC_NODE_H
#define ONPINC_NODE_H
#include "Token.h"

typedef struct Node {
    Token* data;
    struct Node* next;
} Node;

Node* init_node(Token* data, Node* next);
void print_node(Node* node);
void delete_node(Node* node);

#endif //ONPINC_NODE_H
