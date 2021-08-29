//
// Created by Adrian on 28.08.2021.
//
#include "debug.h"
#include <stdio.h>

uint32_t simpleInstruction(const char *name, uint32_t offset) {
    printf("%s\n", name);
    return offset + 1;
}

void printValue(Value value) {
    switch (value.type) {
        case VAL_BOOL:
            printf(AS_BOOL(value) ? "true" : "false");
            break;
        case VAL_NIL:
            printf("nil");
            break;
        case VAL_NUMBER:
            printf("%g", AS_NUMBER(value));
            break;
    }
}

uint32_t constantInstruction(const char *name, Chunk *chunk, uint32_t offset) {
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d '", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 2;
}


uint32_t disassembleInstruction(Chunk *c, uint32_t offset) {
    printf("%04d ", offset);

    if (offset > 0 && c->lines[offset] == c->lines[offset - 1]) {
        printf("   | ");
    } else {
        printf("%4d ", c->lines[offset]);
    }

    uint8_t instruction = c->code[offset];
    switch (instruction) {
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        case OP_NEGATE:
            return simpleInstruction("OP_NEGATE", offset);
        case OP_ADD:
            return simpleInstruction("OP_ADD", offset);
        case OP_SUBTRACT:
            return simpleInstruction("OP_SUBTRACT", offset);
        case OP_MULTIPLY:
            return simpleInstruction("OP_MULTIPLY", offset);
        case OP_DIVIDE:
            return simpleInstruction("OP_DIVIDE", offset);
        case OP_NOT:
            return simpleInstruction("OP_NOT", offset);
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", c, offset);
        case OP_NIL:
            return simpleInstruction("OP_NIL", offset);
        case OP_TRUE:
            return simpleInstruction("OP_TRUE", offset);
        case OP_FALSE:
            return simpleInstruction("OP_FALSE", offset);
        case OP_EQUAL:
            return simpleInstruction("OP_EQUAL", offset);
        case OP_GREATER:
            return simpleInstruction("OP_GREATER", offset);
        case OP_LESS:
            return simpleInstruction("OP_LESS", offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }

    return 0;
}

void disassembleChunk(Chunk *c, const char *name) {
    printf("== %s ==\n", name);
    for (uint32_t offset = 0; offset < c->count;) {
        offset = disassembleInstruction(c, offset);
    }
}

