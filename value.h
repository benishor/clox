//
// Created by Adrian on 28.08.2021.
//

#ifndef CLOX_VALUE_H
#define CLOX_VALUE_H

#include "common.h"
#include <stdint.h>

typedef double Value;

typedef struct {
    uint32_t capacity;
    uint32_t count;
    Value *values;

} ValueArray;

void initValueArray(ValueArray *array);

void writeValueArray(ValueArray *array, Value value);

void freeValueArray(ValueArray *array);

#endif //CLOX_VALUE_H
