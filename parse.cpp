#include "parse.h"

#include <cstring>

static bool parse_bool(const char *json, JsonValue *value) {
    if (strcmp(json, "true") == 0) {
        value->type = JSON_TRUE;
        return true;
    }

    if (strcmp(json, "false") == 0) {
        value->type = JSON_FALSE;
        return true;
    }
    return false;
}

bool parse_json(const char *json, JsonValue *value) {


    if (json == nullptr || value == nullptr) {
        return false;

    }

    if (strcmp(json, "null") == 0) {
        value->type = JSON_NULL;
        return true;
    }

    size_t size = strlen(json);
    if (*json == '\"' && json[size - 1] == '\"') {
        value->type = JSON_STRING;

        value->value = (char*)malloc(size-1);
        strncpy(value->value, json + 1, size - 2);

        value->value[strlen(value->value)] = '\0';
        return true;
    }

    return parse_bool(json, value);
}
