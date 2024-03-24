//
// Created by varev on 24.03.2024.
//
#include "../includes/Reader.h"
#include <stdio.h>
#include <string.h>

int compare_significance(Node* node, char* operand) {
    char signify = significance(node->data->value), signify2 = significance(operand);

    if (signify > signify2)
        return 1;
    if (signify == signify2)
        return 0;
    return -1;
}

void append_negations(Stack* main, Stack* operators) {
    Node* node;
    while(operators->first != NULL && *operators->first->data->value == 'N') {
        node = pop(operators, FIRST);
        push(main, node, LAST);
    }
    node = NULL;
}

void append_operators(Stack* main, Stack* operators, char* operator) {
    if (compare_significance(operators->last, operator) == 0)
        append_stack(main, operators);
    else if (compare_significance(operators->first, operator) != -1)
        push(main, pop(operators,FIRST), LAST);
}

int is_countable(char* text) {
    return stricmp(text, "MAX") == 0 || stricmp(text, "MIN") == 0;
}

int is_function(char* text) {
    return is_countable(text) || stricmp(text, "IF") == 0;
}


void handle_divider(Stack* main, Stack* operators, Token* token) {
    if (token && token->type != OPERATOR) {
        push(main, init_node(token, NULL), LAST);
        append_negations(main, operators);
    }
    token = NULL;
}

Stack* read_input(Tag endTag, int* count) {
    Stack* main = init_stack(NULL), * operators = init_stack(NULL);
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
            if (operators->first != NULL) append_operators(main, operators, &input);
            (*count)++;
        } else if (input >= '0' && input <= '9') {
            if (token == NULL)
                token = init_token_with_value(NUMBER, &input);
            else
                append_to_token(token, &input);
        } else if (input == '(') {
            append_stack(main, read_input(CLOSE, count));
        } else if (token == NULL && significance(&input)) {
            token = init_token_with_value(OPERATOR, &input);

            if (operators->first != NULL && *operators->first->data->value != 'N')
                append_operators(main, operators, &input);

            push(operators, init_node(token, NULL), FIRST);
        } else if (input >= 'A' && input <= 'Z') {
            if (token == NULL) token = init_token_with_value(FUNCTION, &input);
            else append_to_token(token, &input);

            if (!is_function(token->value)) continue;
            scanf("%c%c", &input, &input);
            int counter = 1;
            append_stack(main, read_input(CLOSE, &counter));
            append_counter(token, &counter);
        } else if (input == endTag) {
            append_stack(main, operators);
            break;
        }
    }
    return main;
}

