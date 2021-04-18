#include "doctest.h"
#include "NumberWithUnits.hpp"
using namespace ariel;

#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

ifstream units_file{"units.txt"};

TEST_CASE("Good NumberWithUnits code") {
    NumberWithUnits::read_units(units_file);

    // *********************** distance case
    NumberWithUnits a(2, "km");
    NumberWithUnits b(2500, "m");
    NumberWithUnits c(2, "cm");
    NumberWithUnits d;
    
    CHECK(a == a + d);
    CHECK(a == a);
    CHECK(a != b);
    CHECK(a == b-500);
    CHECK(a == c*100000);
    CHECK(a == c+199998);
    CHECK(a < b);
    CHECK(b > c);
    CHECK(a <= b);
    CHECK(a <= a);
    CHECK(a >= a);
    CHECK(b >= a);

    CHECK(a + b == b + a);
    CHECK(a + 0.5 == b);

    istringstream sample_input1{"700 [ kg ]"};
    sample_input1 >> a;

    CHECK_THROWS(a + b);

    istringstream sample_input2{" 2500   [ m  ] "};
    sample_input2 >> a;

    CHECK(a == b);


    
}

TEST_CASE("Bad NumberWithUnits code") {

    NumberWithUnits::read_units(units_file);
    
    NumberWithUnits a(2, "hour");
    NumberWithUnits b(2, "kg");
    NumberWithUnits c;
    
    CHECK_FALSE(a == b);
    CHECK_FALSE(a == c);

    CHECK_THROWS(a + b);
    CHECK_THROWS(a += b);
    CHECK_THROWS(a - b);
    CHECK_THROWS(a -= b);
    
    // CHECK_THROWS(a == c + a);

   
   

}