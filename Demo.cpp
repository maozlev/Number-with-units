#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <string>
#include <iomanip>
#include <ctime> 
#include <cfloat>


#include "NumberWithUnits.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;
using namespace ariel;

static string answer;
static int point=0;

int level1(string level){
    int grade1 = 0;
    level = "LEVEL"+ level;
    unsigned int microseconds=105000;
    sleep(1);
    cout<<endl;

    cout<<"answer the questions as fastest as you can!"<<endl;
    time_t start = time(0);
    char* date_time = ctime(&start);

    string q = "QUESTION 1";
    sleep(1);
    cout<<endl;
    cout<<WHITE<<q;
    cout<<endl;
    NumberWithUnits d = NumberWithUnits{206,"cm"};
    cout<<endl;
    cout << BOLDBLUE  << "Deni Avdija is 2.06 m tall" << endl;
    sleep(1);
    cout << BOLDBLUE  << "how much in cm???" << endl;
    cout<<endl;
    cin>>answer;
    istringstream iss{answer+" [ cm ]"};
    NumberWithUnits d1{20,"m"};
    iss>>d1;
    if(d == d1){
        sleep(1);
        cout<<GREEN<<"good job!"<<endl;
        sleep(1);
        cout<<GREEN<<"prays for poor Deni....."<<endl;
        sleep(1);
        cout<<GREEN<<"You have "<<++point<<" point!"<<endl;
    }else{
        cout<<RED<<"his tall is 206 cm dude..."<<endl;
        cout<<RED<<"no point for you"<<endl;
    }
    q = "QUESTION 2";
    sleep(1);
    cout<<endl;
    cout<<WHITE<<q;
    cout<<endl;
    level = "  *****TRUE/FALSE*****  ";

    sleep(1);
    cout<<endl;
    microseconds+=5555;
    for(unsigned int i = 0 ;i < 7; i++){
        cout<<YELLOW<<level;
        fflush(stdout);
        usleep(microseconds);
    }
    cout<<endl;
    NumberWithUnits tt = NumberWithUnits{1,"hour"};
    cout << BOLDBLUE  << "true / false: " << endl;
    sleep(1);
    cout << BOLDBLUE  << "3600 seconds equals to hour?? " << endl;
    cout<<endl;
    cin>>answer;
    if(answer == "true"){
        if((tt == NumberWithUnits(3600, "sec"))){
            sleep(1);
            cout<<GREEN<<"good job!"<<endl;
            sleep(1);
            cout<<GREEN<<"tick tack the clock ticking..."<<endl;
            sleep(1);
            cout<<GREEN<<"You have "<<++point<<" points!"<<endl;
        }
    }else{
        cout<<RED<<"do the math..."<<endl;
        sleep(1);
        cout<<RED<<"no point for you"<<endl;
        sleep(1);
        cout<<RED<<"current points: "<<point<<endl;
        sleep(1);
    }

    q = "QUESTION 3";
    sleep(1);
    cout<<endl;
    cout<<WHITE<<q;
    cout<<endl;
    level = "  *****TRAVEL TIME*****  ";

    sleep(1);
    cout<<endl;
    for(unsigned int i = 0 ;i < 7; i++){
        cout<<YELLOW<<level;
        fflush(stdout);
        usleep(microseconds);
    }
    cout<<endl;
    NumberWithUnits USD1 = NumberWithUnits{1,"USD"};
    NumberWithUnits EURO1 = NumberWithUnits{1,"EUR"};
    NumberWithUnits ILS1 = NumberWithUnits{1,"ILS"};
    cout << BOLDBLUE  << "corona virus over and we going to the USA" << endl;
    sleep(2);
    cout << BOLDRED  << "But, there is a catch" << endl;
    sleep(2);
    cout << BOLDBLUE  << "our flight from paris so we need to know how much USD equals to 1 EURO" << endl;
    sleep(4);
    cout<<YELLOW<<"table of units: "<<endl;
    cout<<endl;
    sleep(3);
    NumberWithUnits::print_table();
    cout<<endl;
    cin>>answer;
    double c = std::stod(answer);
    NumberWithUnits t{c,"EUR"};
    if(t == USD1){
        sleep(1);
        cout<<GREEN<<"good job!"<<endl;
        sleep(1);
        cout<<GREEN<<"Corona isnt over but its good to know things like that..."<<endl;
        sleep(1);
        cout<<GREEN<<"You have "<<++point<<" points!"<<endl;
    }else{
        cout<<RED<<"no flight for you..."<<endl;
        sleep(1);
        cout<<RED<<"no point for you"<<endl;
        sleep(1);
        cout<<RED<<"current points: "<<point<<endl;
        sleep(1);
    }

    q = "QUESTION 4";
    sleep(1);
    cout<<endl;
    cout<<WHITE<<q;
    cout<<endl;
    level = "  ***MATH Practice***  ";

    for(unsigned int i = 0 ;i < 6; i++){
        cout<<YELLOW<<level;
        fflush(stdout);
        usleep(microseconds);
    }

    sleep(1);
    cout<<YELLOW<<level;
    cout<<endl;
    NumberWithUnits mm1 = NumberWithUnits{1,"mm"};
    NumberWithUnits cm1 = NumberWithUnits{1,"cm"};
    NumberWithUnits m1 = NumberWithUnits{1,"m"};
    NumberWithUnits km1 = NumberWithUnits{1,"km"};
    // NumberWithUnits USD1 = NumberWithUnits{1,"USD"};
    // NumberWithUnits ILS1 = NumberWithUnits{1,"ILS"};
    NumberWithUnits POUND1 = NumberWithUnits{1,"POUND"};
    // NumberWithUnits EURO1 = NumberWithUnits{1,"EURO"};
    
    cout << BOLDGREEN  << "lets think that you are at the math olimpic" << endl;
    sleep(2);
    cout << BOLDRED  << "your job is to calculate paths" << endl;
    sleep(2);
    cout << BOLDGREEN  << "you need to do calculation with several units:" << endl;
    sleep(1);
    cout << BOLDGREEN  << "mm" << endl;
    cout << BOLDGREEN  << "cm" << endl;
    cout << BOLDGREEN  << "m" << endl;
    cout << BOLDGREEN  << "km" << endl;
    sleep(2);
    cout<<YELLOW<<"calculate 1:"<<endl;
    cout<<YELLOW<<"write the answer in m"<<endl;
    cout<<BLUE<<"30cm + 1m + 3km = "<<endl;
    t = m1 + cm1*30;
    t+= km1*3;
    sleep(3);
    cout<<endl;
    cin>>answer;
    c = std::stod(answer);
    NumberWithUnits t1{c,"m"};
    if(t == t1){
        sleep(1);
        cout<<GREEN<<"good job!"<<endl;
        sleep(1);
        cout<<GREEN<<"You have "<<++point<<" points!"<<endl;
        cout<<GREEN<<"next caculation:"<<endl;
        sleep(1);
        }else{
        cout<<RED<<"wrong answer."<<endl;
        sleep(1);
        cout<<RED<<"no point for you"<<endl;
        sleep(1);
        cout<<RED<<"next caculate: "<<endl;
        sleep(1);
    }
    cout<<YELLOW<<"calculate 2:"<<endl;
    cout<<YELLOW<<"write the answer in mm"<<endl;
    cout<<BLUE<<"44cm + 1m + 222mm = "<<endl;
    t = mm1*222 + m1;
    t+= cm1*44;
    sleep(3);
    cout<<endl;
    cout<<GREEN<<"if you need the convert table insert Y"<<endl;
    cin>>answer;
    if(answer == "Y"){
        NumberWithUnits::print_table();
    }
    cout<<YELLOW<<"write the answer in mm"<<endl;
    cout<<BLUE<<"44cm + 1m + 222mm = "<<endl;
    // cout<<t<<endl;
    cin>>answer;
    c = std::stod(answer);
    NumberWithUnits t3{c,"mm"};
    if(t == t3){
        sleep(1);
        cout<<GREEN<<"good job!"<<endl;
        sleep(1);
        cout<<GREEN<<"You have "<<++point<<" points!"<<endl;
        cout<<GREEN<<"next caculation:"<<endl;
        sleep(1);
        }else{
        cout<<RED<<"wrong answer."<<endl;
        sleep(1);
        cout<<RED<<"no point for you"<<endl;
        sleep(1);
        cout<<RED<<"next caculate: "<<endl;
        sleep(1);
    }
    cout<<YELLOW<<"calculate 3:"<<endl;
    cout<<YELLOW<<"write the answer in ILS"<<endl;
    cout<<BLUE<<"44 POUND + 1 USD  + 20 EURO +3 ILS = "<<endl;
    NumberWithUnits m = ILS1;
    m = ILS1*3 + POUND1*44;
    m+= USD1;
    m+= EURO1*20;
    sleep(3);
    cout<<endl;
    cout<<GREEN<<"if you need the convert table insert Y"<<endl;
    cin>>answer;
    if(answer == "Y"){
        NumberWithUnits::print_table();
        cout<<YELLOW<<"write the answer in ILS"<<endl;
        cout<<BLUE<<"44 POUND + 1 USD  + 20 EURO +3 ILS = "<<endl;
    }
    // cout<<m<<endl;
    
    cin>>answer;
    c = std::stod(answer);
    NumberWithUnits t2{c,"ILS"};
    if(m == t2){
        sleep(1);
        cout<<GREEN<<"good job!"<<endl;
        sleep(1);
        point++;
        sleep(1);
        }else{
        cout<<RED<<"wrong answer."<<endl;
        sleep(1);
        cout<<RED<<"no point for you"<<endl;
        sleep(1);
    }

    time_t end = time(0);
    time_t grade = end-start;
    cout<<GREEN<<"youre time is: "<<grade<<endl;
    if (point > 5){
        cout<<BLUE<<"Grade 100"<<endl;
        cout<<BLUE<<"Points:"<<point<<endl;
        cout<<"Welldone!!"<<endl;
        
    }
    if (point > 2 && point < 6){
        cout<<BLUE<<"Points:"<<point<<endl;
        cout<<BLUE<<"Grade 75"<<endl;
        cout<<"You have a potencial!!"<<endl;
        cout<<"keep try!"<<endl;
        
    }
    if (point<3){
            cout<<BLUE<<"Grade 60"<<endl;
        cout<<BLUE<<"Points:"<<point<<endl;
        cout<<"try again!!"<<endl;
        cout<<"never give up"<<endl;
        
    }

    cout<<"oh 16 points! thank you very much :)"<<endl;
    
    return 0;
}





 
int main(){

    ifstream units_file{"units_for_demo.txt"};
    NumberWithUnits::read_units(units_file);
    
    // cout<<endl;
    // cout << BOLDYELLOW << "Hello!! and Welcome to the Show...................." << endl;
    // sleep(1);
    // cout<<endl;
    // cout << BOLDRED << "Convert me!!!" << endl;
    // sleep(3);
    // while(true){
    //     cout<<endl;
    //     cout << BOLDBLUE  << "Select a level between 1-3" << endl;
    //     cout<<endl;
    //     cin>>answer;
    //     if(answer == "1" || answer == "2" || answer == "3"){
    //         break;
    //     }
    // }
    // unsigned int microseconds=105000;
    // cout<<BOLDBLUE <<"level selected = "+answer<<endl;
    // sleep(1);
    // cout<<endl;
    // cout <<YELLOW<< "Let the game begin! " << endl << "Loading ";
    // cout<<endl;
    // for(unsigned int i = 0 ;i < 10; i++){
    //     cout << "------" ;
    //     fflush(stdout);
    //     usleep(microseconds);
    // }
    // cout << "->Done" <<endl;
    // level1(answer);

    NumberWithUnits::print_table();
    return 0;
}

