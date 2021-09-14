//
// Created by benny on 30/08/2021.
//

#ifndef CLOX_OBJECT_H
#define CLOX_OBJECT_H

#include "common.h"
#include "value.h"
#include "chunk.h"

#define OBJ_TYPE(value) (AS_OBJ(value)->type)
#define IS_STRING(value) (isObjType(value, OBJ_STRING))
#define IS_FUNCTION(value) (isObjType(value, OBJ_FUNCTION))

#define AS_STRING(value) ((ObjString*) AS_OBJ(value))
#define AS_CSTRING(value) (AS_STRING(value)->chars)
#define AS_FUNCTION(value) ((ObjFunction*) AS_OBJ(value))

typedef enum {
    OBJ_STRING,
    OBJ_FUNCTION,
} ObjType;

struct Obj {
    ObjType type;
    Obj *next;
};

typedef struct {
    Obj obj;
    int arity;
    Chunk chunk;
    ObjString *name;
} ObjFunction;

struct ObjString {
    Obj obj;
    uint32_t length;
    char *chars;
    uint32_t hash;
};

ObjFunction *newFunction();
ObjString *takeString(char *chars, int length);
ObjString *copyString(const char *chars, int length);

static inline bool isObjType(Value value, ObjType type) {
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

void printObject(Value value);

#endif //CLOX_OBJECT_H
