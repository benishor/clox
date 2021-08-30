//
// Created by Adrian on 28.08.2021.
//

#ifndef CLOX_DEBUG_H
#define CLOX_DEBUG_H

#include "chunk.h"

uint32_t disassembleInstruction(Chunk *chunk, uint32_t offset);
void disassembleChunk(Chunk* c, const char* name);
void printValue(Value value);

#endif //CLOX_DEBUG_H
