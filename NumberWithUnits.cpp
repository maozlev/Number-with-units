#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include<string>


#include <algorithm> 
#include <queue>
#include <utility>

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

    bool NumberWithUnits::is_exist(const std::string &a){
        bool flag = false;
        for (auto& t:compares[a]){
                if(a.compare(t.first) !=0 ){
                    flag = true;
                }
        }
        return flag;
    }

    bool NumberWithUnits::have_connection(const std::string &a, const std::string &b){
        bool flag = false;
        for (auto t:compares[a]){
                if(b == t.first){
                    flag = true;
                }
        }
        for (auto t:compares[b]){
                if(a == t.first){
                    flag = true;
                }
        }
    return flag;
    }
    double NumberWithUnits::convertor(const NumberWithUnits& a, const NumberWithUnits& b){
       return b.unit * compares[b.des][a.des];
    } 

    bool operator==(const NumberWithUnits& a, const NumberWithUnits& b) {
        double epsilon = 0.0001; 
        if(!(NumberWithUnits::have_connection(a.des,b.des))){
            throw invalid_argument{"Units do not match - ["+b.des+"] cannot be converted to ["+a.des+"]"};
            return false;
        }
        double convert = NumberWithUnits::convertor(a,b);
        // cout<<(a.unit - convert)<<endl;
        return ((a.unit - convert) < epsilon && (a.unit - convert)> (-epsilon));   
    }

    bool operator!=(const NumberWithUnits& a, const NumberWithUnits& b) {
        return (!(a==b));
    }

    NumberWithUnits NumberWithUnits::operator-(){
        if(!NumberWithUnits::is_exist(this->des)){
            throw invalid_argument{"Units do not match - ["+this->des+"]"};
        }
        NumberWithUnits t(-this->unit, this->des);
        return t;
    }

    NumberWithUnits NumberWithUnits::operator+(){
        if(!NumberWithUnits::is_exist(this->des)){
            throw invalid_argument{"Units do not match - ["+this->des+"]"};
        }
        NumberWithUnits t(this->unit, this->des);
        return t;
    }

    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits& a){
        if(!(NumberWithUnits::have_connection(this->des ,a.des))){
            throw invalid_argument{"Units do not match - ["+this->des+"] cannot be converted to ["+a.des+"]"};
            }
        NumberWithUnits tmp(this->unit, this->des);
        double convert = NumberWithUnits::convertor(tmp,a);

        return NumberWithUnits (this->unit + convert, this->des);   
    }

    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits& a){
        if(!(NumberWithUnits::have_connection(this->des ,a.des))){
            throw invalid_argument{"Units do not match - ["+this->des+"] cannot be converted to ["+a.des+"]"};
            }
        NumberWithUnits tmp(this->unit, this->des);
        double convert = NumberWithUnits::convertor(tmp,a);

        return NumberWithUnits (this->unit - convert, this->des);   
    }

    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& a){
        if(!(NumberWithUnits::have_connection(this->des, a.des))){
            throw("Units do not match - ["+this->des+"] cannot be converted to ["+a.des+"]");
        }
        NumberWithUnits tmp1(this->unit, this->des);
        double convert = NumberWithUnits::convertor(tmp1,a);
        this->unit += convert;
        return *this;
    }

    NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& a){
        if(!(NumberWithUnits::have_connection(this->des, a.des))){
            throw("Units do not match - ["+this->des+"] cannot be converted to ["+a.des+"]");
        }
        NumberWithUnits tmp1(this->unit, this->des);
        double convert = NumberWithUnits::convertor(tmp1,a);
        this->unit -= convert;
        return *this;
    }

    NumberWithUnits& NumberWithUnits::operator++() {
        if(!NumberWithUnits::is_exist(this->des)){
            throw invalid_argument{"Units do not match - ["+this->des+"]"};
        }
        ++this->unit;
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator++(int) { 
        if(!NumberWithUnits::is_exist(this->des)){
            throw invalid_argument{"Units do not match - ["+this->des+"]"};
        }
        NumberWithUnits t((this->unit)++, this->des);
        return t;
    }

    NumberWithUnits& NumberWithUnits::operator--() {
        if(!NumberWithUnits::is_exist(this->des)){
            throw invalid_argument{"Units do not match - ["+this->des+"]"};
        }
        --this->unit;
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator--(int) { 
        if(!NumberWithUnits::is_exist(this->des)){
            throw invalid_argument{"Units do not match - ["+this->des+"]"};
        }
        NumberWithUnits t((this->unit)--, this->des);
        return t;
    }
    
    NumberWithUnits operator*(const NumberWithUnits& a,const double& n){
        NumberWithUnits n2(a.unit*n, a.des);
        return n2;
    }

    NumberWithUnits operator*(const double& n,const NumberWithUnits& a){
        return a*n;  
    }   

    NumberWithUnits& NumberWithUnits::operator*=(double n) {
        this->unit *= n;
        return *this;
    }

    bool operator>(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a.des,b.des))){
            throw invalid_argument{"Units do not match - ["+b.des+"] cannot be converted to ["+a.des+"]"};
            return false;
        }
        double convert = NumberWithUnits::convertor(a,b);
        return (a.unit-convert>0);
    }

    bool operator>=(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a.des,b.des))){
            throw invalid_argument{"Units do not match - ["+b.des+"] cannot be converted to ["+a.des+"]"};
            return false;
        }
        double convert = NumberWithUnits::convertor(a,b);
        return (a.unit-convert>=0);
    }

    bool operator<(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a.des,b.des))){
            throw invalid_argument{"Units do not match - ["+b.des+"] cannot be converted to ["+a.des+"]"};
            return false;
        }
        double convert = NumberWithUnits::convertor(a,b);
        return (a.unit-convert<0);
    }    
    
    bool operator<=(const NumberWithUnits& a, const NumberWithUnits& b){
        if(!(NumberWithUnits::have_connection(a.des,b.des))){
            throw invalid_argument{"Units do not match - ["+b.des+"] cannot be converted to ["+a.des+"]"};
            return false;
        }
        double convert = NumberWithUnits::convertor(a,b);
        return (a.unit-convert<=0);
    }

    istream& operator>> (istream& is, NumberWithUnits& a) {

        if(!NumberWithUnits::is_exist(a.des)){
            throw invalid_argument{"Units do not match - ["+a.des+"]"};
        }
        
        char c = 0;
        double t = 0;
        string st;
        
        is >> t; //unit
        is >> skipws >> c; // des
        if(c != '['){
            is.setstate(ios::failbit); // should start with [
        }

        getline(is,st,']'); // get until ]
        // cout<<st.c_str()<<endl;
        // cout<<st.find_first_not_of(' ')<<endl; // how much spaces I have
        string str2 = st.c_str() + st.find_first_not_of(' '); 
        // cout<<str2<<endl;
        // cout<<endl;
        unsigned int space_first_location = str2.find_first_of(' ');
        // cout<<space_first_location<<endl;
        // cout<<str2.size()<<endl;
        if(str2.size() > space_first_location && space_first_location > 0){
            str2.resize(space_first_location); // need more space (in memory)
        }
        if(!NumberWithUnits::is_exist(str2)){
            throw invalid_argument{"Units do not match - ["+str2+"]"};
        }
        a.unit = t;
        a.des = str2; // fixed description
        return is;
    }
    


    
    ostream& operator<< (ostream& os, const NumberWithUnits& a) {
        if(!NumberWithUnits::is_exist(a.des)){
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


