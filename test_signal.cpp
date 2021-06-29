#include "catch.hpp"
#include "signal.hpp"
// TODO

// Note this test will fail to compile if you do not have the
// correct member function declarations.
TEST_CASE("Test Signal for const correctness", "[signal]") {


    //make the size to be 10
    const Signal<double, 10> s(4);

    for (std::size_t i = 0; i < s.length(); ++i) {
        CHECK(s[i] == 4.0); //check when the length  = 4 
        CHECK(s.at(i) == 4.0);

        REQUIRE_THROWS_AS(s.at(400), std::invalid_argument);
    }
}







