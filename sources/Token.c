//
// Created by varev on 20.03.2024.
//
#include <malloc.h>
#include "../includes/Token.h"

Token* init_token(Type type, char *value) {
    Token* token = (Token*) malloc(sizeof(Token));
    token->type = type;
    token->value = value;
    return token;
}

void delete_token(Token* token) {
    char* value = token->value;
    token->value = NULL;
    free(value);
    free(token);
}