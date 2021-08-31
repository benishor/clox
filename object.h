//
// Created by benny on 30/08/2021.
//

#ifndef CLOX_OBJECT_H
#define CLOX_OBJECT_H

#include "common.h"
#include "value.h"

#define OBJ_TYPE(value) (AS_OBJ(value)->type)
#define IS_STRING(value) (isObjType(value, OBJ_STRING))

#define AS_STRING(value) ((ObjString*) AS_OBJ(value))
#define AS_CSTRING(value) (AS_STRING(value)->chars)

typedef enum {
    OBJ_STRING,
} ObjType;

struct Obj {
    ObjType type;
    Obj *next;
};

struct ObjString {
    Obj obj;
    uint32_t length;
    char *chars;
    uint32_t hash;
};

ObjString *takeString(char *chars, int length);
ObjString *copyString(const char *chars, int length);

static inline bool isObjType(Value value, ObjType type) {
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

void printObject(Value value);

#endif //CLOX_OBJECT_H
