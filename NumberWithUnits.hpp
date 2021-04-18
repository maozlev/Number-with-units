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
                this->unit = a;
                this->des = s; 
            }
            NumberWithUnits(){
                this->unit = 0;
                this->des = ""; 
            }

            ~NumberWithUnits(){}

            static void read_units(std::ifstream& units_file);

            //Unary operators******************************************************

            friend NumberWithUnits operator-(const NumberWithUnits& a);
            friend NumberWithUnits operator+(const NumberWithUnits& a);
            
            //operations on 2 objects**********************************************  
            
            friend NumberWithUnits operator-(const NumberWithUnits& a, const NumberWithUnits& b);
            friend NumberWithUnits operator+(const NumberWithUnits& a, const NumberWithUnits& b);
            
            friend NumberWithUnits operator-=(NumberWithUnits& a, const NumberWithUnits& b);
            friend NumberWithUnits operator+=(NumberWithUnits& a, const NumberWithUnits& b);


            //operations on 1 objects**********************************************

            friend NumberWithUnits operator-(const NumberWithUnits& a, double n);
            friend NumberWithUnits operator+(const NumberWithUnits& a, double n);

            friend NumberWithUnits operator++(NumberWithUnits& a);
            friend NumberWithUnits operator++(NumberWithUnits& a, int);

            friend NumberWithUnits operator--(NumberWithUnits& a);
            friend NumberWithUnits operator--(NumberWithUnits& a, int);

            friend NumberWithUnits operator*(NumberWithUnits& a, double n);
            friend NumberWithUnits operator*(double n, NumberWithUnits& a);

            friend NumberWithUnits operator*=(NumberWithUnits& a, double n);
            friend NumberWithUnits operator*=(double n, NumberWithUnits& a);

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

            double get_unit(){
                return unit;
            }
            std::string get_des(){
                return des;
            }

            static bool is_exist(const NumberWithUnits& a);
            static bool have_connection(const NumberWithUnits& a, const NumberWithUnits& b);
            static double convertor(const NumberWithUnits& a, const NumberWithUnits& b);
            static void print_table();

    };
};

