#pragma once

typedef enum {
    JSON_NULL
} JsonType;

typedef struct {
    JsonType type;
} JsonValue;

bool parse_json(const char* json, JsonValue* value);