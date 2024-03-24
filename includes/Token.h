//
// Created by varev on 20.03.2024.
//

#ifndef ONPINC_TOKEN_H
#define ONPINC_TOKEN_H

#define OPERAND_SIZE 1
#define NUMBER_SIZE 11

typedef enum Type {
    NUMBER,
    OPERATOR,
    FUNCTION
} Type;

typedef struct Token {
    Type type;
    char *value;
} Token;

char significance(const char* operand);
Token* init_token(Type type);
Token* init_token_with_value(Type type, const char *value);
void append_to_token(Token* token, const char *value);
void append_counter(Token* token, const int *value);
void delete_token(Token* token);

#endif //ONPINC_TOKEN_H
