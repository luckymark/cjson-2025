#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "parse.h"

TEST_CASE("parse null") {
    JsonValue value;
    bool result = parse_json("null", &value);
    CHECK(result);
    CHECK(value.type == JSON_NULL);
}
