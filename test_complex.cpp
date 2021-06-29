#include "catch.hpp"

#include "complex.hpp"

// TODO


// Note this test will fail to compile if you do not have the
// correct member function declarations.
TEST_CASE("Test const correctness of Complex", "[complex]") {

  const Complex z(-1.,-1.);

  REQUIRE(z.real() == -1.);
  REQUIRE(z.imag() == -1.);
}
TEST_CASE("Test default", "[complex]") {

    const Complex z;

    REQUIRE(z.real() == 0);
    REQUIRE(z.imag() == 0);
}
TEST_CASE("Test mul", "[complex]") {

    const Complex z1(1., 1.);//z1 = 1+j
    const Complex z2(1., 2.);//z2 = 1+2j

    Complex z1z2 = mul(z1, z2);//(1+j)(1+2j) = -1+3j
    REQUIRE(z1z2.real() == -1.);//
    REQUIRE(z1z2.imag() == 3.);
}

TEST_CASE("Test addition", "[complex]") {

    const Complex z1(1., 1.);//z1 = 1+j
    const Complex z2(1., 2.);//z2 = 1+2j

    Complex z = add(z1, z2);//(1+j)+(1+2j) = 2+3j
    REQUIRE(z.real() == 2.); 
    REQUIRE(z.imag() == 3.);
}

TEST_CASE("Test negative", "[complex]") {
    const Complex z(1., 1.);
    Complex x = neg(z);
    REQUIRE(x.real() == -1.);
    REQUIRE(x.imag() == -1.);

}
