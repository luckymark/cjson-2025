#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "parse.h"

TEST_CASE("parse null") {
    JsonValue value;
    bool result = parse_json("null", &value);
    CHECK(result);
    CHECK(value.type == JSON_NULL);
}

TEST_CASE("parse true"){
    JsonValue value;
    bool result = parse_json("true", &value);
    CHECK(result);
    CHECK(value.type == JSON_TRUE);
}

TEST_CASE("parse false") {
    JsonValue value;
    bool result = parse_json("false", &value);
    CHECK(result);
    CHECK(value.type == JSON_FALSE);
}

TEST_CASE("parse \"hello\"") {
    JsonValue value;
    auto result = parse_json("\"hello\"", &value);
    CHECK(result);
    CHECK(value.type == JSON_STRING);
    CHECK(strcmp(value.value,"hello")==0 );
}

TEST_CASE("parse \"_world\""){
    JsonValue value;
    auto result = parse_json("\"_world\"", &value);
    CHECK(result);
    CHECK(value.type == JSON_STRING);
    CHECK(strcmp(value.value,"_world")==0);
}
TEST_CASE("parse \"_world"){
    JsonValue value;
    auto result = parse_json("\"_world", &value);
    CHECK(!result);
}