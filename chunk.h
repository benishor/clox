//
// Created by Adrian on 28.08.2021.
//

#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H


#include <stdint.h>
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_NEGATE,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NOT,
    OP_PRINT,
    OP_RETURN
} OpCode;

typedef struct {
    uint32_t count;
    uint32_t capacity;
    uint8_t *code;
    uint32_t *lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk *c);
void freeChunk(Chunk *c);
void writeChunk(Chunk *c, uint8_t byte, uint32_t line);
uint32_t addConstant(Chunk *chunk, Value value);


#endif //CLOX_CHUNK_H
