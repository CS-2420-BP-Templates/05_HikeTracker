

#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Collection.h"




using namespace std;

// -------------------------
// ADD + SIZE TESTS
// -------------------------
TEST_CASE("Collection adds items correctly", "[Collection]")
{
    Collection<string, 10> c;

    c.add("A");
    c.add("B");
    c.add("C");

    REQUIRE(c.getSize() == 3);
    REQUIRE(c[0] == "A");
    REQUIRE(c[1] == "B");
    REQUIRE(c[2] == "C");
}

// -------------------------
// OPERATOR[] TEST
// -------------------------
TEST_CASE("Collection operator[] access works", "[Collection]")
{
    Collection<int, 5> c;

    c.add(10);
    c.add(20);

    REQUIRE(c[0] == 10);
    REQUIRE(c[1] == 20);
}

// -------------------------
// REMOVE TEST (SHIFTING)
// -------------------------
TEST_CASE("Collection removeAt shifts elements correctly", "[Collection]")
{
    Collection<string, 10> c;

    c.add("A");
    c.add("B");
    c.add("C");
    c.add("D");

    c.removeAt(1); // remove "B"

    REQUIRE(c.getSize() == 3);
    REQUIRE(c[0] == "A");
    REQUIRE(c[1] == "C");
    REQUIRE(c[2] == "D");
}

// -------------------------
// EXCEPTION: OUT OF RANGE (operator[])
// -------------------------
TEST_CASE("operator[] throws out_of_range for invalid index", "[Collection]")
{
    Collection<int, 5> c;

    c.add(1);

    REQUIRE_THROWS_AS(c[5], std::out_of_range);
    REQUIRE_THROWS_AS(c[-1], std::out_of_range);
}

// -------------------------
// EXCEPTION: REMOVE EMPTY
// -------------------------
TEST_CASE("removeAt throws underflow_error when empty", "[Collection]")
{
    Collection<int, 5> c;

    REQUIRE_THROWS_AS(c.removeAt(0), std::underflow_error);
}

// -------------------------
// EXCEPTION: INVALID INDEX REMOVE
// -------------------------
TEST_CASE("removeAt throws out_of_range for invalid index", "[Collection]")
{
    Collection<int, 5> c;

    c.add(10);

    REQUIRE_THROWS_AS(c.removeAt(5), std::out_of_range);
}

// -------------------------
// EXCEPTION: OVERFLOW
// -------------------------
TEST_CASE("add throws overflow_error when full", "[Collection]")
{
    Collection<int, 2> c;

    c.add(1);
    c.add(2);

    REQUIRE_THROWS_AS(c.add(3), std::overflow_error);
}

// -------------------------
// TEMPLATE FLEXIBILITY TEST
// -------------------------
TEST_CASE("Collection works with multiple types", "[Collection]")
{
    Collection<int, 5> ints;
    Collection<string, 5> strings;

    ints.add(100);
    strings.add("hello");

    REQUIRE(ints[0] == 100);
    REQUIRE(strings[0] == "hello");
}