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

    bool NumberWithUnits::is_exist(const NumberWithUnits& a){
        bool flag = false;
        for (auto& t:compares[a.des]){
                if(a.des == t.first){
                    flag = true;
                }
        }
        return flag;
    }

    bool NumberWithUnits::have_connection(const NumberWithUnits& a, const NumberWithUnits& b){
        bool flag = false;
        for (auto t:compares[a.des]){
                if(b.des == t.first){
                    flag = true;
                }
        }
        for (auto t:compares[b.des]){
            // cout<<t.first<<endl;
                if(a.des == t.first){
                    flag = true;
                }
        }
    return flag;
    }
    double NumberWithUnits::convertor(const NumberWithUnits& a, const NumberWithUnits& b){
       return b.unit * compares[b.des][a.des];
    } 

    bool operator==(const NumberWithUnits& a, const NumberWithUnits& b) {
        // cout<<(NumberWithUnits::have_connection(a,b))<<endl;
        if(!(NumberWithUnits::have_connection(a,b))){
            throw invalid_argument{"Units do not match - ["+b.des+"] cannot be converted to ["+a.des+"]"};
            return false;
        }
        double convert = NumberWithUnits::convertor(a,b);
        // cout<<(a.unit - convert)<<endl;
        return ((a.unit - convert) < 0.0001 && (a.unit - convert)> (-0.0001));   
    }

    bool operator!=(const NumberWithUnits& a, const NumberWithUnits& b) {
        // cout<<(!(a==b))<<endl;
        // cout<<((a==b))<<endl;
        return (!(a==b));
    }

    NumberWithUnits operator-(const NumberWithUnits& a){
        if(!NumberWithUnits::is_exist(a)){
            throw invalid_argument{"Units do not match - ["+a.des+"]"};
        }
        return NumberWithUnits (-a.unit, a.des);
    }
    NumberWithUnits operator+(const NumberWithUnits& a){
        if(!NumberWithUnits::is_exist(a)){
            throw invalid_argument{"Units do not match - ["+a.des+"]"};
        }
        return NumberWithUnits (a.unit, a.des);
    }

    NumberWithUnits operator+(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw invalid_argument{"Units do not match - ["+b.des+"] cannot be converted to ["+a.des+"]"};
            }
        double convert = NumberWithUnits::convertor(a,b);

        return NumberWithUnits (a.unit + convert, a.des);   
    }

    NumberWithUnits operator-(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw("Units do not match - ["+b.des+"] cannot be converted to ["+a.des+"]");
        }
        double convert = NumberWithUnits::convertor(a,b);
        return NumberWithUnits (a.unit - convert, a.des);   
    }

    NumberWithUnits operator+(const NumberWithUnits& a, double n){
        if(!NumberWithUnits::is_exist(a)){
            throw invalid_argument{"Units do not match - ["+a.des+"]"};
        }
        return NumberWithUnits (a.unit + n, a.des);   
    }

    NumberWithUnits operator-(const NumberWithUnits& a, double n){
        if(!NumberWithUnits::is_exist(a)){
            throw invalid_argument{"Units do not match - ["+a.des+"]"};
        }
        return NumberWithUnits (a.unit - n, a.des);   
    }

    NumberWithUnits operator+=(NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw("Units do not match - ["+b.des+"] cannot be converted to ["+a.des+"]");
        }
        double convert = NumberWithUnits::convertor(a,b);
        a.unit = (a.unit + convert);
        return a;
    }

    NumberWithUnits operator-=(NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw("Units do not match - ["+b.des+"] cannot be converted to ["+a.des+"]");
        }
        double convert = NumberWithUnits::convertor(a,b);
        a.unit = (a.unit - convert);
        return a;
    }

    NumberWithUnits operator++(NumberWithUnits& a){
        if(!NumberWithUnits::is_exist(a)){
            throw invalid_argument{"Units do not match - ["+a.des+"]"};
        }
        return NumberWithUnits (++a.unit, a.des);
    }

    NumberWithUnits operator++(NumberWithUnits& a, int){
        if(!NumberWithUnits::is_exist(a)){
            throw invalid_argument{"Units do not match - ["+a.des+"]"};
        }
        return NumberWithUnits (a.unit++, a.des);
    }
    
    NumberWithUnits operator--(NumberWithUnits& a){
        if(!NumberWithUnits::is_exist(a)){
            throw invalid_argument{"Units do not match - ["+a.des+"]"};
        }
         return NumberWithUnits (--a.unit, a.des);
    }

    NumberWithUnits operator--(NumberWithUnits& a, int){
        if(!NumberWithUnits::is_exist(a)){
            throw invalid_argument{"Units do not match - ["+a.des+"]"};
        }
         return NumberWithUnits (a.unit--, a.des);
    }

    NumberWithUnits operator*(NumberWithUnits& a, double n){
        if(!NumberWithUnits::is_exist(a)){
            throw invalid_argument{"Units do not match - ["+a.des+"]"};
        }
        return NumberWithUnits (a.unit * n, a.des);
    }

    NumberWithUnits operator*(double n, NumberWithUnits& a){
        if(!NumberWithUnits::is_exist(a)){
            throw invalid_argument{"Units do not match - ["+a.des+"]"};
        }
        return NumberWithUnits (n * a.unit, a.des);
    }

    NumberWithUnits operator*=(NumberWithUnits& a, double n){
        if(!NumberWithUnits::is_exist(a)){
            throw invalid_argument{"Units do not match - ["+a.des+"]"};
        }
        a.unit *= n;
        return a;
    }

    NumberWithUnits operator*=(double n, NumberWithUnits& a){
        if(!NumberWithUnits::is_exist(a)){
            throw invalid_argument{"Units do not match - ["+a.des+"]"};
        }
        a.unit *= n;
        return a;
    }

    bool operator>(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw invalid_argument{"Units do not match - ["+b.des+"] cannot be converted to ["+a.des+"]"};
            return false;
        }
        double convert = NumberWithUnits::convertor(a,b);
        return (a.unit-convert>0);
    }

    bool operator>=(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw invalid_argument{"Units do not match - ["+b.des+"] cannot be converted to ["+a.des+"]"};
            return false;
        }
        double convert = NumberWithUnits::convertor(a,b);
        return (a.unit-convert>=0);
    }

    bool operator<(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw invalid_argument{"Units do not match - ["+b.des+"] cannot be converted to ["+a.des+"]"};
            return false;
        }
        double convert = NumberWithUnits::convertor(a,b);
        return (a.unit-convert<0);
    }    
    
    bool operator<=(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a,b))){
            throw invalid_argument{"Units do not match - ["+b.des+"] cannot be converted to ["+a.des+"]"};
            return false;
        }
        double convert = NumberWithUnits::convertor(a,b);
        return (a.unit-convert<=0);
    }

     istream& operator>>(istream& is, NumberWithUnits& a){
         if(!NumberWithUnits::is_exist(a)){
            throw invalid_argument{"Units do not match - ["+a.des+"]"};
        }
        string s;
        is >> a.unit >> s >> a.des;
        return is;
    }

    
    ostream& operator<< (ostream& os, const NumberWithUnits& a) {
        if(!NumberWithUnits::is_exist(a)){
            throw invalid_argument{"Units do not match - ["+a.des+"]"};
        }
        return (os << a.unit << '['<< a.des << ']');
    }

    void NumberWithUnits::print_table(){
        for( auto const & cit : compares ) {
            cout <<" | "<< cit.first <<"  "<<"  "<< " | "<<endl;
            auto const & imap = cit.second;
            for( auto const & cit2 : imap ) {
                cout <<" | "<< cit2.first <<" = "<< cit2.second <<"|"<<endl;
            }
            cout << endl;
        }
    }
}


