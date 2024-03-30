//
// Created by varev on 24.03.2024.
//
#include "../includes/Reader.h"
#include <stdio.h>
#include <string.h>

int compare_significance(Node* node, char* operator) {
    char nodeOperator = (char) node->data->value;
    char signify = significance(&nodeOperator), signify2 = significance(operator);

    if (signify > signify2)
        return 1;
    if (signify == signify2)
        return 0;
    return -1;
}

void append_negations(Stack* main, Stack* operators) {
    Node* node;
    while(operators->first != NULL && operators->first->data->value == 'N') {
        node = pop(operators, FIRST);
        push(main, node, LAST);
    }
    node = NULL;
}

void append_operators(Stack* main, Stack* operators, char* operator) {
    if (compare_significance(operators->last, operator) >= 0)
        append_stack(main, operators);
    else if (compare_significance(operators->first, operator) != -1)
        push(main, pop(operators,FIRST), LAST);
}

int is_countable(const Token* token) {
    if (token->type != FUNCTION)
        return IF;
    return token->value % 10;
}

int is_function_init(const char* character) {
    return *character == 'M' || *character == 'I';
}

int is_number(const char* character) {
    return *character >= '0' && *character <= '9';
}

int is_operator(const char* character) {
    return significance(character);
}

void parse_by_second_char(char* input) {
    scanf("%c", input);
    if (*input == 'F') *input = IF;
    else if (*input == 'A') *input = MAX;
    else *input = MIN;
}

void skip_function_chars(char* input) {
    if (*input != IF)
        scanf("%c", input);
    scanf("%c%c", input, input);
}

void append_function(Stack* main, Token* token) {
    int counter = 1;
    read_input(main, CLOSE, &counter);
    if (is_countable(token)) append_counter(token, &counter);
}

Stack* read_input(Stack* main, Tag endTag, int* count) {
    Stack* operators = init_stack(NULL);
    Token* token = NULL;
    char input = '\0';

    while (1) {
        scanf("%c", &input);

        if (input == DIVIDER) {
            if (token && token->type != OPERATOR) {
                push(main, init_node(token, NULL), LAST);
                append_negations(main, operators);
            }
            token = NULL;
        } else if (input == SEPARATOR) {
            if (operators->first) append_operators(main, operators, &input);
            (*count)++;
        } else if (input == OPEN) {
            read_input(main, CLOSE, count);
            append_negations(main, operators);
        } else if (is_number(&input)) {
            if (token == NULL) token = init_token_with_value(NUMBER, &input);
            else append_to_token(token, &input);
        } else if (is_operator(&input)) {
            token = init_token_with_value(OPERATOR, &input);
            if (operators->first != NULL && operators->first->data->value != 'N')
                append_operators(main, operators, &input);
            push(operators, init_node(token, NULL), FIRST);
        } else if (is_function_init(&input)) {
            parse_by_second_char(&input);
            token = init_token_with_value(FUNCTION, &input);
            skip_function_chars(&input);
            append_function(main, token);
        } else if (input == endTag) {
            append_stack(main, operators);
            break;
        }
    }
    delete_stack(operators);
    delete_token(token);
    return main;
}

