#include "parse.h"

#include <cstdlib>
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

static bool is_number(const char json) {
    return (json == '-') || (json >= '0' && json <= '9');
}

static bool parse_number(const char *json, JsonValue *value) {
    char *endptr;
    const double number = strtod(json, &endptr);
    if (*endptr == '\0' && endptr != json) {
        value->type = JSON_NUMBER;
        value->value.number = number;
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

        value->value.str = (char *) malloc(size - 1);
        strncpy(value->value.str, json + 1, size - 2);

        value->value.str[strlen(value->value.str)] = '\0';
        return true;
    }
    if (is_number(*json)) {
        return parse_number(json, value);
    }

    return parse_bool(json, value);
}
