//
// Created by Adrian on 28.08.2021.
//

#ifndef CLOX_VALUE_H
#define CLOX_VALUE_H

#include "common.h"
#include <stdint.h>

typedef enum {
    VAL_BOOL,
    VAL_NIL,
    VAL_NUMBER,
} ValueType;

typedef struct {
    ValueType type;
    union {
        bool boolean;
        double number;
    } as;
} Value;

#define IS_BOOL(value) ((value).type == VAL_BOOL)
#define IS_NIL(value) ((value).type == VAL_NIL)
#define IS_NUMBER(value) ((value).type == VAL_NUMBER)

#define AS_BOOL(value) ((value).as.boolean)
#define AS_NUMBER(value) ((value).as.number)

#define BOOL_VAL(value) ((Value){VAL_BOOL, {.boolean = value}})
#define NIL_VAL ((Value){VAL_NIL, {.number = 0}})
#define NUMBER_VAL(value) ((Value){VAL_NUMBER, {.number = value}})

typedef struct {
    uint32_t capacity;
    uint32_t count;
    Value *values;

} ValueArray;

void initValueArray(ValueArray *array);

void writeValueArray(ValueArray *array, Value value);

void freeValueArray(ValueArray *array);

#endif //CLOX_VALUE_H
