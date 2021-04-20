#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "doctest.h"
#include "NumberWithUnits.hpp"
using namespace std;
using namespace ariel;

ifstream units_file{"units.txt"};


TEST_CASE("Good NumberWithUnits code") {
    NumberWithUnits::read_units(units_file);

    // *********************** distance case
    NumberWithUnits a(2, "km");
    NumberWithUnits b(2500, "m");
    NumberWithUnits c(2, "cm");
    NumberWithUnits d(2, "kg");
    CHECK_THROWS(c+d);    
    CHECK(a == a);
    CHECK(a != b);
    CHECK(a == c*100000);
    CHECK(a < b);
    CHECK(b > c);
    CHECK(a <= b);
    CHECK(a <= a);
    CHECK(a >= a);
    CHECK(b >= a);

    NumberWithUnits e = (a + c);
    NumberWithUnits f = (c + a);
    
    CHECK((a+c) == (c+a));
    CHECK_FALSE((a + c) == b);

    istringstream sample_input1{"700 [ kg ]"};
    sample_input1 >> a;

    CHECK_THROWS(a + b);

    istringstream sample_input2{" 2500   [ m  ] "};
    sample_input2 >> a;

    CHECK(a == b);

    ostringstream sample_output3;
    sample_output3 << a;

    istringstream sample_input4{sample_output3.str()};
    sample_input4 >> b;
    CHECK(a == b);
}

TEST_CASE("Bad NumberWithUnits code") {

    NumberWithUnits::read_units(units_file);
    
    NumberWithUnits a(2, "hour");
    NumberWithUnits b(2, "kg");
    NumberWithUnits c(2, "USD");;
    NumberWithUnits d(2, "kk");
    bool flag;
    CHECK_THROWS(flag = (a == b));
    CHECK_THROWS(flag = (a == c));
    CHECK_THROWS(flag = (a < b));
    CHECK_THROWS(flag = (a <= c));
    CHECK_THROWS(flag = (a > b));
    CHECK_THROWS(flag = (a >= c));

    CHECK_THROWS(a + b);
    CHECK_THROWS(a += b);
    CHECK_THROWS(a - b);
    CHECK_THROWS(b -= d);
    
   

}
