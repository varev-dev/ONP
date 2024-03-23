//
// Created by varev on 20.03.2024.
//
#include <malloc.h>
#include "../includes/Token.h"

Token* init_token_with_value(Type type, char *value) {
    Token* token = (Token*) malloc(sizeof(Token));
    token->type = type;
    token->value = value;
    return token;
}

Token* init_token(Type type) {
    Token* token = (Token*) malloc(sizeof(Token));
    token->type = type;
    size_t size = (type == OPERAND ? OPERAND_SIZE : NUMBER_SIZE);
    token->value = malloc((size + 1) * sizeof(char));
    token->value[size] = '\0';
    return token;
}

void delete_token(Token* token) {
    char* value = token->value;
    token->value = NULL;
    free(value);
    free(token);
}