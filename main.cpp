// c++11 syntax is used  
//set "-std=c++0x" or "-std=gnu++0x" for compiler options

#include <cstdlib>
#include <iostream>
#include "_str_cpp_.h"
#include <iomanip>  //для cout << setw(2) << i

using namespace std;

int main(int argc, char *argv[])
{
    system("chcp 1251 > nul");

    string S = "table_iter_t it != table.begin(34234)->4341;";
    
    // c++11 initializer list syntax:  //-std=c++0x or -std=gnu++0x
    StringVector delimiters {"!=", "(", ".", "->", "!", ";", " ", ")", "_"}; 

    cout << S << endl;
    cout << "Разом - " << countOfLexems(S, delimiters) << " лексем" << endl;
    
    for (int i=0,n=countOfLexems(S, delimiters); i<n; i++){
        cout << setw(3) << i << ": " << getLexemeByIndex(S, delimiters, i) << endl; 
//2-й спосіб. В ньому #include <iomanip> не треба
//        cout.width(2);
//        cout << i << ": " << getLexemeByIndex(S, delimiters, i) << endl; 
    }
    
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
