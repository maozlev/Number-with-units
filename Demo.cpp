#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unistd.h>
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

#include "NumberWithUnits.hpp"
using namespace ariel;

int i_equal_9(){
    std::cout << BOLDRED << "we getting closer, we need to drop 2.5 tons from our ship! !!!!" << RESET << std::endl;
    printf("you need to write 2.5 tons in kg..... \n");
    int count = 3;
    NumberWithUnits b{2.5, "ton"};
    NumberWithUnits a{3, "kg"};  
    string s, s1;
    while(b!=a){
        if(count == 0){
            cout<<"the spaceship crashed everyone dead"<<endl;
            return 1;
        }
    cout<<"you have "<<count<<" tries"<<endl;
    cout<<"insert num"<<endl;
    cin>>s;
    cout<<"insert kind"<<endl;
    cin>>s1;
    istringstream sample_input{s+"["+s1+"]"};
    sample_input>>a; 
    count--;
    }
    return 0;
}
int i_equal_8(){
    std::cout << BOLDRED << "Oh NO Darth Vader wants to destroy our ship !!!!" << RESET << std::endl;
    printf("you need solve his problem and he let us continue \n");
    std::cout << BOLDRED << "How much seconds in 1.5 hour?" << RESET << std::endl;
    int count = 3;
    NumberWithUnits b{1.5, "hour"};
    NumberWithUnits a{3, "sec"};  
    string s, s1;
    while(b!=a){
        if(count == 0){
            std::cout << BOLDRED << "everyone dead" << RESET << std::endl;
            return 1;
        }
        cout<<"you have "<<count<<" tries"<<endl;
        cout<<"insert num"<<endl;
        cin>>s;
        cout<<"insert kind"<<endl;
        cin>>s1;
        string s2 = s+"["+s1+"]";
        // cout<<s2<<endl;
        istringstream sample_input{s2};
        sample_input>>a; 
        // cout<<a<<endl;
        count--;
        }

    std::cout << BOLDRED << "this basterd wants money!!" << RESET << std::endl;
    sleep(1);
    std::cout << BOLDRED << "he wants 50 USD in ILS!!! " << RESET << std::endl;
    printf("you need put the exact sum! \n");
    count = 3;
    NumberWithUnits c{50, "USD"};
    NumberWithUnits d{3, "ILS"};  
    string s4, s5;
    while(c!=d){
        if(count == 0){
            std::cout << BOLDRED << "everyone dead" << RESET << std::endl;
            return 1;
        }
        cout<<"you have "<<count<<" tries"<<endl;
        cout<<"insert num"<<endl;
        cin>>s4;
        cout<<"insert kind"<<endl;
        cin>>s5;
        string s6 = s4+"["+s5+"]";
        // cout<<s2<<endl;
        istringstream sample_input{s6};
        sample_input>>d; 
        // cout<<a<<endl;
        count--;
        }

    return 0;
}

int i_equal_7(){
    std::cout << BOLDRED << "Danger!!!!!! we need to set the timer of our oxigen !!!!" << RESET << std::endl;
    printf("you need to write 1 hour in sec to stay alive!!\n");
    int count = 3;
    NumberWithUnits b{1, "hour"};
    NumberWithUnits a{3, "sec"};  
    string s, s1;
    while(b!=a){
        if(count == 0){
            std::cout << BOLDRED << "everyone dead without oxigen" << RESET << std::endl;
            return 1;
        }
    cout<<"you have "<<count<<" tries"<<endl;
    cout<<"insert num"<<endl;
    cin>>s;
    cout<<"insert kind"<<endl;
    cin>>s1;
    string s2 = s+"["+s1+"]";
    // cout<<s2<<endl;
    istringstream sample_input{s2};
    sample_input>>a; 
    // cout<<a<<endl;
    count--;
    }
    return 0;
}
int i_equal_5(){
    std::cout << BOLDRED << "Danger!!!!!! an astroid infront of us in 300 m !!!!" << RESET << std::endl;
    printf("you need to write 300 meter in km to stay alive!!\n");
    int count = 3;
    NumberWithUnits b{0.3, "km"};
    NumberWithUnits a{3, "km"};  
    string s, s1;
    while(b!=a){
        if(count == 0){
            std::cout << BOLDRED << "the spaceship crashed everyone dead" << RESET << std::endl;
            return 1;
        }
    cout<<"you have "<<count<<" tries"<<endl;
    cout<<"insert num"<<endl;
    cin>>s;
    cout<<"insert kind"<<endl;
    cin>>s1;
    string s2 = s+"["+s1+"]";
    // cout<<s2<<endl;
    istringstream sample_input{s2};
    sample_input>>a; 
    // cout<<a<<endl;
    count--;
    }
    return 0;
}

int i_equal_3(){

    std::cout << BOLDRED << "quick! we are 3 meter from land!" << RESET << std::endl;
    printf("you need to write 3 meter in cm \n");
    int count = 3;
    NumberWithUnits b{3, "m"};
    NumberWithUnits a{3, "cm"};  
    string s, s1;
    while(b!=a){
        if(count == 0){
            std::cout << BOLDRED << "the spaceship crashed everyone dead" << RESET << std::endl;
            return 1;
        }
    cout<<"you have "<<count<<" tries"<<endl;
    cout<<"insert num"<<endl;
    cin>>s;
    cout<<"insert kind"<<endl;
    cin>>s1;
    string s2 = s+"["+s1+"]";
    // cout<<s2<<endl;
    istringstream sample_input{s2};
    sample_input>>a; 
    count--;
    }
    return 0;
}

void i_equal_1(){
    cout << GREEN << "well done capitan!!! we have landed safely!" << RESET << std::endl;
    cout<<"credits:"<<endl;
    cout<<""<<endl;
    sleep(2);
    cout<<""<<endl;
    std::cout << BLUE << "Maoz Lev - author" << RESET << std::endl;
    cout<<""<<endl;
    sleep(2);
    cout<<""<<endl;
    cout<<"thank you for watching"<<endl;
    cout<<""<<endl;
    sleep(2);
    cout<<""<<endl;
    cout<<"Bye Bye"<<endl;
    sleep(2);
    return;
}

void start_game(){
    cout<<"we about to landing in 10 sec!!"<< endl;
    for (int i = 10; i > 0; i--){
        if (i % 16 == 0 && i != 0){
            cout << "\n ";
            
        }
        printf("\033[38;5;%dm %3d\033[m", i, i);
        printf("\n");
        sleep(1);

        if(i == 9){
            if(i_equal_9()==1){
                return;
            }
        }

        if(i == 8){
            if(i_equal_8()==1){
                return;
            }
        }

        if(i == 7){
            if(i_equal_7()==1){
                return;
            }
        }

        if(i == 5){
            if(i_equal_5()==1){
                return;
            }
        }

        if(i == 3){
            if(i_equal_3()==1){
                return;
            }
        }

        if(i == 1){
            i_equal_1();
        }
    }
}

int main() {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    cout<<""<<endl;
    cout<<GREEN <<"*         *******   *******   *********           "<< RESET << endl;
    cout<<GREEN <<"*         *     *   *             *               "<< RESET << endl;
    cout<<GREEN <<"*         *     *   *             *               "<< RESET << endl;
    cout<<GREEN <<"*         *     *   *             *               "<< RESET << endl;
    cout<<GREEN <<"*         *     *   *******       *               "<< RESET << endl;
    cout<<GREEN <<"*         *     *         *       *               "<< RESET << endl;
    cout<<GREEN <<"*         *     *         *       *               "<< RESET << endl;
    cout<<GREEN <<"*         *     *         *       *               "<< RESET << endl;
    cout<<GREEN <<"*******   *******   *******       *               "<< RESET << endl;
    // sleep(2);
    cout<<""<<endl;
    cout<<YELLOW<<"               ***         *       *               "<< RESET << endl;
    cout<<YELLOW<<"                *          **      *               "<< RESET << endl;
    cout<<YELLOW<<"                *          * *     *               "<< RESET << endl;
    cout<<YELLOW<<"                *          *  *    *               "<< RESET << endl;
    cout<<YELLOW<<"                *          *   *   *               "<< RESET << endl;
    cout<<YELLOW<<"                *          *    *  *               "<< RESET << endl;
    cout<<YELLOW<<"                *          *     * *               "<< RESET << endl;
    cout<<YELLOW<<"                *          *      **               "<< RESET << endl;
    cout<<YELLOW<<"               ***         *       *               "<< RESET << endl;
    // sleep(2);
    cout<<""<<endl;
    cout<<CYAN<<"*******   *******     * *     *******   *******   "<< RESET << endl;
    cout<<CYAN<<"*         *     *    *   *    *         *         "<< RESET << endl;
    cout<<CYAN<<"*         *     *   *     *   *         *         "<< RESET << endl;
    cout<<CYAN<<"*         *******   *     *   *         *         "<< RESET << endl;
    cout<<CYAN<<"*******   *         *******   *         *******   "<< RESET << endl;
    cout<<CYAN<<"      *   *         *     *   *         *         "<< RESET << endl;
    cout<<CYAN<<"      *   *         *     *   *         *         "<< RESET << endl;
    cout<<CYAN<<"      *   *         *     *   *         *         "<< RESET << endl;
    cout<<CYAN<<"*******   *         *     *   *******   *******   "<< RESET << endl;
    // sleep(2);
    cout<<""<<endl;

    cout<<BOLDGREEN<<"hello and wellcome abbord!"<< RESET << endl;
    cout<<""<<endl;
    cout<<"are you ready? we going to land on the moon!"<< endl;
    cout<<""<<endl;
    cout<<"please say yes"<< endl;
    string s;
    cin>>s;
    while(s!="yes"){
        cin>>s;
    }
    cout<<""<<endl;
    cout<<"see? is over there! have a look in the window.."<< endl;
    cout<<""<< endl;
    cout<<"_________________________________"<< endl;
    cout<<"|      *         *      *       |"<< endl;
    cout<<"|    *   *         *    *  *    |"<< endl;
    cout<<"|            *   *           *  |"<< endl;
    cout<<"|                  *   *        |"<< endl;
    cout<<"|     * *      ->*<-    *       |"<< endl;
    cout<<"_________________________________"<< endl;
    // sleep(5);
    cout<<""<<endl;
    cout<<"we need you as a capitan please be our commander!"<< endl;
    cout<<"please say yes"<< endl;
    string s1;
    cin>>s1;
    while(s1!="yes"){
        cin>>s;
    }
    cout<<"I have to warn you - the engineer who built this spaceship is British. Their units are very strange I'll explain:\n"<< endl;
    // sleep(2);
    cout<<"there is a table for all usefull units:"<< endl;
    // sleep(2);
    NumberWithUnits::print_table();
    cout<<"did you get it?"<< endl;
    string s2;
    cin>>s2;
    while(s2!="yes"){
        cin>>s;
    }
    start_game();
    
    return 0;
}