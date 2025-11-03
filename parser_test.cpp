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
    CHECK(strcmp(value.value.str,"hello")==0 );
}

TEST_CASE("parse \"_world\""){
    JsonValue value;
    auto result = parse_json("\"_world\"", &value);
    CHECK(result);
    CHECK(value.type == JSON_STRING);
    CHECK(strcmp(value.value.str,"_world")==0);
}

TEST_CASE("parse \"_world"){
    JsonValue value;
    auto result = parse_json("\"_world", &value);
    CHECK(!result);
}

TEST_CASE("parse 1.2") {
    JsonValue value;
    auto result = parse_json("1.2", &value);
    CHECK(result);
    CHECK(value.type == JSON_NUMBER);
    CHECK(value.value.number==1.2 );
}

TEST_CASE("parse -10e6") {
    JsonValue value;
    auto result = parse_json("-10e6", &value);
    CHECK(result);
    CHECK(value.type == JSON_NUMBER);
    CHECK(value.value.number==-10e6);
}
