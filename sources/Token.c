//
// Created by varev on 20.03.2024.
//
#include <malloc.h>
#include <math.h>
#include "../includes/Token.h"

char significance(const char* operator) {
    switch (*operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case 'N':
            return 3;
        default:
            return 0;
    }
}

Token* init_token_with_value(Type type, const char *value) {
    Token* token = (Token*) malloc(sizeof(Token));
    token->type = type;
    token->value = *value - (type == NUMBER ? '0' : 0);
    return token;
}

void append_to_token(Token* token, const char *value) {
    token->value *= 10;
    token->value += *value - '0';
}

void append_counter(Token* token, const int *value) {
    FunctionIndex index = token->value;
    token->value = *value * 10;
    token->value += (int) index;
}

void delete_token(Token* token) {
    free(token);
}