//
// Created by varev on 20.03.2024.
//

#ifndef ONPINC_TOKEN_H
#define ONPINC_TOKEN_H

typedef enum FunctionIndex {
    IF = 0,
    MAX,
    MIN
} FunctionIndex;

typedef enum Type {
    NUMBER,
    OPERATOR,
    FUNCTION
} Type;

typedef struct Token {
    Type type;
    int value;
} Token;

char significance(const char* operator);
Token* init_token_with_value(Type type, const char *value);
void append_to_token(Token* token, const char *value);
void append_counter(Token* token, const int *value);
void delete_token(Token* token);

#endif //ONPINC_TOKEN_H
