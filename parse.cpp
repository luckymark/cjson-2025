#include "parse.h"

#include <cstring>

bool parse_json(const char *json, JsonValue *value) {
    if (json == nullptr || value == nullptr) {
        return false;
    }
    if (strcmp(json, "null") == 0) {
        value->type = JSON_NULL;
        return true;
    }
    
    return false;
}
