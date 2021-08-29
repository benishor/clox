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
    printf("%g", AS_NUMBER(value));
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
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", c, offset);
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

