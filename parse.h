#pragma once

typedef enum {
    JSON_NULL,
    JSON_TRUE,
    JSON_FALSE,
    JSON_STRING,
} JsonType;

typedef struct {
    JsonType type;
    char* value;
} JsonValue;
bool parse_json(const char *json, JsonValue *value);
