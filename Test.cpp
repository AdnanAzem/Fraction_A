#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace ariel;


TEST_CASE("Divide by zero should throw an exception") {
    CHECK_THROWS_AS(Fraction(3, 0), std::invalid_argument);
    CHECK_THROWS(Fraction(5,0));

    // Positive Fraction
    Fraction a(2,5);
    Fraction b(0,1);
    CHECK_THROWS(a/b);

    // Negative Fraction
    Fraction c(-2,5);
    CHECK_THROWS(c/b);
}

TEST_CASE("Fraction with large numbers") {
    // Positive Fraction
    Fraction frac(123456789, 987654321);
    CHECK(frac.toString() == "123456789/987654321");

    // Negative Fraction
    Fraction frac1(-123456789, 987654321);
    CHECK(frac1.toString() == "-123456789/987654321");
}

TEST_CASE("Negative fraction") {
    Fraction frac(-3, 4);
    CHECK(frac.getNumerator() == -3);
    CHECK(frac.getDenominator() == 4);
    CHECK(frac.toString() == "-3/4");
}

TEST_CASE("Simplify fraction") {
    // Positive Fraction
    Fraction frac1(6, 8);
    frac1.reduce();
    CHECK(frac1.toString() == "3/4");

    Fraction frac2(4,5);
    frac2.reduce();
    CHECK(frac2.toString() == "4/5");

    // Negative Fraction
    Fraction frac3(-6, 8);
    frac3.reduce();
    CHECK(frac3.toString() == "-3/4");

    Fraction frac4(-4,5);
    frac4.reduce();
    CHECK(frac4.toString() == "-4,5");

}

TEST_CASE("Recurring decimal fraction") {
    Fraction frac(1, 3);
    CHECK(frac.getNumerator() == 1);
    CHECK(frac.getDenominator() == 3);
    CHECK(frac.toString() == "1/3");

    Fraction frac1(-1, 3);
    CHECK(frac1.getNumerator() == -1);
    CHECK(frac1.getDenominator() == 3);
    CHECK(frac1.toString() == "-1/3");
}

TEST_CASE("Denominator is not 0"){
    Fraction a(1,2);
    Fraction b(1,4);

    CHECK_NOTHROW(a+b);
    CHECK_NOTHROW(a-b);
    CHECK_NOTHROW(a*b);
    CHECK_NOTHROW(a/b);

    CHECK(a>b);
    CHECK_FALSE(a<b);
    CHECK(a>=b);
    CHECK_FALSE(a<=b);
    CHECK_FALSE(a==b);

    CHECK_NOTHROW(a++);
    CHECK_NOTHROW(++a);
    CHECK_NOTHROW(a--);
    CHECK_NOTHROW(--a);

    CHECK_NOTHROW(b++);
    CHECK_NOTHROW(++b);
    CHECK_NOTHROW(b--);
    CHECK_NOTHROW(--b);
}

TEST_CASE("Denominator is 0 throws error"){
    Fraction a(1,0);
    Fraction b(5,2);

    CHECK_THROWS(a+b);
    CHECK_THROWS(a-b);
    CHECK_THROWS(a*b);
    CHECK_THROWS(a/b);

    CHECK_THROWS(a++);
    CHECK_THROWS(a--);
    CHECK_THROWS(++a);
    CHECK_THROWS(--a);

    CHECK_NOTHROW(b++);
    CHECK_NOTHROW(b--);
    CHECK_NOTHROW(++b);
    CHECK_NOTHROW(--b);
}

TEST_CASE("Compromise after arithmetic"){
    Fraction a(1,2);
    Fraction b(1,3);
    Fraction c(5,6);
    Fraction d(1,6);
    Fraction e(1,6);
    Fraction f(3,2);

    CHECK(a+b == c);
    CHECK(a-b == d);
    CHECK(a*b == e);
    CHECK(a/b == f);

}

TEST_CASE("Compromise of (1,2)"){
    Fraction a(1,2);
    Fraction b(2,4);
    Fraction c(3,6);

    CHECK(a == b);
    CHECK(a == c);
    CHECK(b == c);
}

TEST_CASE("Negative Fraction"){
    Fraction a(-1,2);
    Fraction b(1,2);
    Fraction c(0,1);
    Fraction d(-1,2);


    CHECK(a+b == c);
    CHECK(a == d);
    CHECK(a < b);
    CHECK(a <= b);
    CHECK_FALSE(a > b);
    CHECK_FALSE(a >= b);
}



