#include "chunk.h"
#include "memory.h"

void initChunk(Chunk *c) {
    c->count = 0;
    c->capacity = 0;
    c->code = NULL;
    c->lines = NULL;
    initValueArray(&c->constants);
}

void freeChunk(Chunk *c) {
    FREE_ARRAY(uint8_t, c->code, c->capacity);
    FREE_ARRAY(uint32_t, c->lines, c->capacity);
    freeValueArray(&c->constants);
    initChunk(c);
}

void writeChunk(Chunk *c, uint8_t byte, uint32_t line) {
    if (c->count >= c->capacity) {
        uint32_t oldCapacity = c->capacity;
        c->capacity = GROW_CAPACITY(oldCapacity);
        c->code = GROW_ARRAY(uint8_t, c->code, oldCapacity, c->capacity);
        c->lines = GROW_ARRAY(uint32_t, c->lines, oldCapacity, c->capacity);
    }

    c->code[c->count] = byte;
    c->lines[c->count] = line;
    c->count++;
}

uint32_t addConstant(Chunk *c, Value value) {
    writeValueArray(&c->constants, value);
    return c->constants.count - 1;
}
