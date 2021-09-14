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
    OP_POP,
    OP_DEFINE_GLOBAL,
    OP_GET_LOCAL,
    OP_SET_LOCAL,
    OP_GET_GLOBAL,
    OP_SET_GLOBAL,
    OP_PRINT,
    OP_JUMP_IF_FALSE,
    OP_JUMP,
    OP_LOOP,
    OP_CALL,
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
