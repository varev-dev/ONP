//
// Created by varev on 20.03.2024.
//

#ifndef ONPINC_TOKEN_H
#define ONPINC_TOKEN_H

typedef enum Type {
    NUMBER = 0,
    OPERAND = 1,
    FUNCTION = 2
} Type;

typedef struct Token {
    Type type;
    char *value;
} Token;

Token* init_token(Type type, char *value);
void delete_token(Token* token);

#endif //ONPINC_TOKEN_H
