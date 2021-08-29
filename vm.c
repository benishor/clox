//
// Created by Adrian on 28.08.2021.
//

#include "vm.h"
#include "debug.h"
#include "compiler.h"
#include <stdio.h>
#include <stdbool.h>

VM vm;

static void resetStack() {
    vm.stackTop = vm.stack;
}

void push(Value value) {
    *vm.stackTop++ = value;
}

Value pop() {
    vm.stackTop--;
    return *vm.stackTop;
}

void initVM() {
    resetStack();
}

void freeVM() {
}

static InterpretResult run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
#define BINARY_OP(op) \
        do { \
        Value b = pop(); \
        Value a = pop(); \
        push(a op b); \
        } while (false)

    for (;;) {

#ifdef DEBUG_TRACE_EXECUTION
        printf("          ");
        for (Value *slot = vm.stack; slot < vm.stackTop; slot++) {
            printf("[ ");
            printValue(*slot);
            printf(" ]");
        }
        printf("\n");
        disassembleInstruction(vm.chunk, (uint32_t) (vm.ip - vm.chunk->code));
#endif

        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                push(constant);
                break;
            }
            case OP_NEGATE: {
                push(-pop());
                break;
            }
            case OP_ADD:
                BINARY_OP(+);
                break;
            case OP_SUBTRACT:
                BINARY_OP(-);
                break;
            case OP_MULTIPLY:
                BINARY_OP(*);
                break;
            case OP_DIVIDE:
                BINARY_OP(/);
                break;
            case OP_RETURN:
                printValue(pop());
                printf("\n");
                return INTERPRET_OK;
        }
    }

#undef BINARY_OP
#undef READ_CONSTANT
#undef READ_BYTE
}

InterpretResult interpret(const char* source) {
    compile(source);
    return INTERPRET_OK;
}