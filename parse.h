#pragma once

typedef enum {
    JSON_NULL,
    JSON_TRUE,
    JSON_FALSE,
    JSON_STRING,
    JSON_NUMBER,
} JsonType;

typedef struct {
    JsonType type;
    union{
        char* str;
        double number;
    } value;

} JsonValue;
bool parse_json(const char *json, JsonValue *value);
