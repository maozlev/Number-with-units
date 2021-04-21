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

ifstream units_file1{"units.txt"};

ifstream units_file2{"units_suprise.txt"};


// lets check classic units

TEST_CASE("Good NumberWithUnits code - classic units") {
    NumberWithUnits::read_units(units_file1);
    
    NumberWithUnits km2(2, "km");
    NumberWithUnits km2_min(-2, "km");
    NumberWithUnits m2500(2500, "m");
    NumberWithUnits m500(500, "m");
    NumberWithUnits cm2(2, "cm");
    NumberWithUnits kg2(2, "kg");

    CHECK(+km2 == km2);
    CHECK(-km2 == km2_min);
  
    CHECK(km2 == km2);
    CHECK(km2 + m500 == m2500);
    CHECK(km2 == cm2*100000);

    CHECK(km2 != m2500);
    CHECK(km2 + cm2 != m2500);
    CHECK(km2 != cm2*10000);
    CHECK(km2 != 10000*cm2);

    CHECK(km2 < m2500);
    CHECK(cm2 < km2);
    CHECK(cm2 < m2500);

    CHECK(km2 <= m2500);
    CHECK(cm2 <= cm2);
    
    CHECK(m2500 > cm2);
    CHECK(km2 > m500);
    CHECK(km2 > cm2);

    CHECK(km2 >= km2);
    CHECK(m2500 >= cm2);

    NumberWithUnits km2_000002 = (km2 + cm2);
    NumberWithUnits cm2000002 = (cm2 + km2);
    NumberWithUnits cm2000002b = cm2000002;
    
    CHECK((km2+cm2) == (cm2+km2));
    CHECK(km2_000002 == cm2000002);

    NumberWithUnits km4_000004 = (km2_000002*2);
    NumberWithUnits cm4000004 = (km2_000002*2);
    NumberWithUnits cm3000002 = (2*km2_000002);
    NumberWithUnits cm1(1, "cm");

    km2_000002 += cm2000002;
    CHECK(km2_000002 == km4_000004);
    km2_000002 -= cm2000002;
    CHECK(km2_000002 == cm2000002);
    km2_000002 *= 2;
    CHECK(km2_000002 == km4_000004);

    km2_000002 -= cm2000002;

    cm2000002++;
    km2_000002+=cm1;
    CHECK(km2_000002 == cm2000002);
    
    cm2000002++;

    CHECK(++cm2000002b != cm2000002 );
    CHECK(cm2000002b++ != cm2000002 );
    CHECK(cm2000002b++ == cm2000002 );
    CHECK(++cm2000002b != cm2000002 );    

    CHECK(--cm2000002b != cm2000002 );
    CHECK(cm2000002b-- != cm2000002 );
    CHECK(cm2000002b-- == cm2000002 );
    CHECK(--cm2000002b != cm2000002 );    

    

    istringstream sample_input1{"700 [ kg ]"};
    sample_input1 >> km2;

    CHECK_THROWS(km2 + m2500);
    CHECK(kg2*350 == km2);

    istringstream sample_input2{" 2500   [ m  ] "};
    sample_input2 >> km2;

    CHECK(km2 == m2500);

    ostringstream sample_output3;
    sample_output3 << km2;

    istringstream sample_input4{sample_output3.str()};
    sample_input4 >> m2500;
    CHECK(km2 == m2500);
}

TEST_CASE("Bad NumberWithUnits code") {

    NumberWithUnits::read_units(units_file1);
    
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

//********************************************************************

// test with another txt file with more converts: with units_suprise.txt

// km-> m-> cm-> mm-> mmm

// 1 USD = 1.5 ILS
// 1 USD = 0.5 POUND
// 1 USD = 5.5 YEN
// 1 USD = 1.965 EURO

// euro1 = 1/1.965 dolar


TEST_CASE("Special cases with special units") {
    NumberWithUnits::read_units(units_file2);

    NumberWithUnits km1(1, "km");
    NumberWithUnits m1(1, "m");
    NumberWithUnits cm1(1, "cm");
    NumberWithUnits mm1(1, "mm");
    NumberWithUnits mm9999999(9999999, "mm");
    NumberWithUnits mmm1(1, "mmm");
    NumberWithUnits mmm9999999999(9999999999, "mmm");

    CHECK(mmm1*10000000000 == km1);
    CHECK(mm1*10000000 == km1);

    mmm1+=mmm9999999999;
    mm1+=mm9999999;
    CHECK(mmm1 == km1);
    CHECK(mm1 == km1);

    NumberWithUnits USD1(1, "USD");
    NumberWithUnits ILS1(1, "ILS");
    NumberWithUnits POUND1(1, "POUND");
    NumberWithUnits YEN1(1, "YEN");
    NumberWithUnits EURO1(1, "EURO");
    NumberWithUnits ILSt(1.965*1.5, "ILS");

    // lets convert money

    CHECK(ILS1*3 + POUND1 == USD1*4);
    CHECK(3*ILS1 + POUND1 == 4*USD1);

    CHECK(EURO1 == ILS1 * 1.5544);
    
}
