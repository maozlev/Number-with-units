#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>

#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel{

    static map <string , map<string , double>> compares;
    
    // from stackoverflow
    void NumberWithUnits::read_units(std::ifstream& units_file){
        double a=0, b=0;
        string type1, type2, trash;
        while(units_file >> a >> type1 >> trash >> b >> type2){
            compares[type1][type2] = b;
            compares[type2][type1] = 1/b;
            for (auto& t:compares[type2]){
                double tmp1 = b*t.second;
                compares[type1][t.first] = tmp1;
                compares[t.first][type1] = 1/tmp1;
                }
            for (auto& t:compares[type1]){
                double tmp2 = (1/b)*t.second;
                compares[type2][t.first] = tmp2;
                compares[t.first][type2] = 1/tmp2;
                }
            }
        }

    bool NumberWithUnits::have_connection(const NumberWithUnits& a, const NumberWithUnits& b){
        double val = compares[a.des][b.des];
        if(val == 0){
            return false;
        }
        return true;
    }

    bool operator==(const NumberWithUnits& a, const NumberWithUnits& b) {
        if(!(NumberWithUnits::have_connection(a,b))){
            throw("illegle values");
        }
        double convert = b.unit * compares[b.des][a.des];
        return (a.unit- convert == 0);   
    }
    
    bool operator!=(const NumberWithUnits& a, const NumberWithUnits& b) {
        return (!(a==b));
    }

    NumberWithUnits operator-(const NumberWithUnits& a){
        return NumberWithUnits (-a.unit, a.des);
    }
    NumberWithUnits operator+(const NumberWithUnits& a){
        return NumberWithUnits (a.unit, a.des);
    }

    NumberWithUnits operator+(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw("illegle values");
        }
        double convert = b.unit * compares[b.des][a.des];
        return NumberWithUnits (a.unit + convert, a.des);   
    }

    NumberWithUnits operator-(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw("illegle values");
        }
        double convert = b.unit * compares[b.des][a.des];
        return NumberWithUnits (a.unit - convert, a.des);   
    }

    NumberWithUnits operator+(const NumberWithUnits& a, double n){
        return NumberWithUnits (a.unit + n, a.des);   
    }

    NumberWithUnits operator-(const NumberWithUnits& a, double n){
        return NumberWithUnits (a.unit - n, a.des);   
    }

    NumberWithUnits operator+=(NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw("illegle values");
        }
        double convert = b.unit * compares[b.des][a.des];
        a.unit = (a.unit + convert);
        return a;
    }

    NumberWithUnits operator-=(NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw("illegle values");
        }
        double convert = b.unit * compares[b.des][a.des];
        a.unit = (a.unit - convert);
        return a;
    }

    NumberWithUnits operator++(NumberWithUnits& a){
        return NumberWithUnits (++a.unit, a.des);
    }

    NumberWithUnits operator++(NumberWithUnits& a, int){
        return NumberWithUnits (a.unit++, a.des);
    }
    
    NumberWithUnits operator--(NumberWithUnits& a){
         return NumberWithUnits (--a.unit, a.des);
    }

    NumberWithUnits operator--(NumberWithUnits& a, int){
         return NumberWithUnits (a.unit--, a.des);
    }

    NumberWithUnits operator*(NumberWithUnits& a, double n){
        return NumberWithUnits (a.unit * n, a.des);
    }

    NumberWithUnits operator*(double n, NumberWithUnits& a){
        return NumberWithUnits (n * a.unit, a.des);
    }

    NumberWithUnits operator*=(NumberWithUnits& a, double n){
        a.unit *= n;
        return a;
    }

    NumberWithUnits operator*=(double n, NumberWithUnits& a){
        a.unit *= n;
        return a;
    }

    bool operator>(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw("illegle values");
        }
        double convert = b.unit * compares[b.des][a.des];
        return (a.unit-convert>0);
    }

    bool operator>=(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw("illegle values");
        }
        double convert = b.unit * compares[b.des][a.des];
        return (a.unit-convert>=0);
    }

    bool operator<(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw("illegle values");
        }
        double convert = b.unit * compares[b.des][a.des];
        return (a.unit-convert<0);
    }    
    
    bool operator<=(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw("illegle values");
        }
        double convert = b.unit * compares[b.des][a.des];
        return (a.unit-convert<=0);
    }

    istream& operator>> (istream& is, const NumberWithUnits& a){
        string s;
        NumberWithUnits b = a;
        is >> b.unit >> s >> b.des;
        return is;
    }
    ostream& operator<< (ostream& os, const NumberWithUnits& n) {
        return (os << n.unit << '['<< n.des << ']');
    }

}
