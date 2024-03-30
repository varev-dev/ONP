//
// Created by varev on 23.03.2024.
//

#ifndef ONPINC_READER_H
#define ONPINC_READER_H
#include "Stack.h"

typedef enum Tag {
    DIVIDER = ' ',
    SEPARATOR = ',',
    OPEN = '(',
    CLOSE = ')',
    END = '.'
} Tag;

Stack* read_input(Stack* main, Tag endTag, int* count);

#endif //ONPINC_READER_H
