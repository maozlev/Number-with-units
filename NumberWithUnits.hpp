#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>

namespace ariel{
    
    class  NumberWithUnits {

        private:

            double unit;
            std::string des; // description 

        public:

            NumberWithUnits(double a, std::string s){
                if(!is_exist(s)){
                    throw("erorr");
                }
                this->unit = a;
                this->des = s; 
                
            }

            ~NumberWithUnits(){}

            static void read_units(std::ifstream& units_file);

            //Unary operators******************************************************

            NumberWithUnits operator-();
            NumberWithUnits operator+();
            
            //operations on 2 objects**********************************************  
            
            NumberWithUnits operator-(const NumberWithUnits& a);
            NumberWithUnits operator+(const NumberWithUnits& a);
            
            NumberWithUnits& operator-=(const NumberWithUnits& a);
            NumberWithUnits& operator+=(const NumberWithUnits& a);


            //operations on 1 objects**********************************************

            NumberWithUnits& operator++();
            NumberWithUnits& operator--();
            NumberWithUnits operator++(int);
            NumberWithUnits operator--(int);

            NumberWithUnits& operator*=(double n);

            friend NumberWithUnits operator*(const NumberWithUnits& a, const double& n);
            friend NumberWithUnits operator*(const double& n, const NumberWithUnits& a);

            
            // Comparisons on 2 objects*********************************************

            friend bool operator>(const NumberWithUnits& a, const NumberWithUnits& b);
            friend bool operator>=(const NumberWithUnits& a, const NumberWithUnits& b);
            friend bool operator<(const NumberWithUnits& a, const NumberWithUnits& b);
            friend bool operator<=(const NumberWithUnits& a, const NumberWithUnits& b);
            friend bool operator==(const NumberWithUnits& a, const NumberWithUnits& b);
            friend bool operator!=(const NumberWithUnits& a, const NumberWithUnits& b);

            // input output ********************************************************

            friend std::ostream& operator<< (std::ostream& os, const NumberWithUnits& a);
            friend std::istream& operator>> (std::istream& is,  NumberWithUnits& a);

            // added functions

            static bool is_exist(const std::string &a);
            static bool have_connection(const std::string &a, const std::string &b);
            static double convertor(const NumberWithUnits& a, const NumberWithUnits& b);
            static void print_table();
    };
};

