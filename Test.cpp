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
    NumberWithUnits a(2, "km");
    NumberWithUnits b(2500, "m");
    NumberWithUnits c(2, "kg");
    CHECK(a != b);
    CHECK_FALSE(a > b);
    cout<<(a>b)<<endl;
    // cout<<a++<<endl;
    // cout<<b++<<endl;
    // cout<<a++<<endl;
    // cout<<b++<<endl;
    // cout<<b-c<<endl;
    // cout<<c-b<<endl;
    // cout<<b+a<<endl;
    // cout<<a+a<<endl;
    // cout<<a-b<<endl;
    // a+=b;
    // cout<<a<<endl;
    // a-=b;
    // cout<<a<<endl;
    // cout<<a-1.4333<<endl;
    // CHECK_THROWS(a+c);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
    // CHECK(true == true);
}
