#include "_str_cpp_.h"
#include <iostream>
#include <algorithm> //for sort()

#define NPOS std::string::npos

using namespace std;

bool compare (const string& str1, const string& str2);

bool compare (const string& str1, const string& str2) {
    return str1.length() > str2.length();  
}

//Дає кількість лексем у рядку, відповідно до вектора роздільників 
int countOfLexems(string str, StringVector delimiters){
    int counter = 0;  //загальна кількість лексем (з роздільниками)
    
    //sort delimiters. the longer - first
    sort(delimiters.begin(), delimiters.end(), compare); 
 
    while (str.length()>0){
        //1. пошук найближчого роздільника
        int delim_len =  0;     //довжина найближчого роздільника
        int delim_pos = -1;     //позиція найближчого роздільника
                                //(-1)- не знайдено жодного розд.

        //перебираємо роздільники
        for (int i=0; i<delimiters.size(); i++){ 
            //Порожні роздільники не розглядаємо
            if (delimiters[i].length()==0) continue;
            
            //шукаємо черговий роздільник
            int p = str.find(delimiters[i]);
            
            //якщо черговий у списку роздільник присутній в рядку
            if (p!=NPOS) { 
                if (delim_pos==-1) {    //перший знайдений роздільник
                        delim_pos = p;
                        delim_len = delimiters[i].length();
                } 
                else {                  //не перший знайдений роздільник
                    if (p < delim_pos) {
                        delim_pos = p;
                        delim_len = delimiters[i].length();
                    }
                }
            }
        }
        
        //2. виділення чергової лексеми в окрему змінну
        string lex;                 //чергова виділена лексема
        
        //є принаймні 1 роздільник
        if (delim_pos != -1) { 
            //роздільник може бути на початку рядка
            if (delim_pos==0) {
                lex = str.substr(0, delim_len);
                str.erase(0,delim_len);
                counter++;
            } 
            //роздільник не на початку рядка, значить перед ним - слово
            else {
                lex = str.substr(0, delim_pos);
                str.erase(0,lex.length());
                counter++;
            }
        } 
        //роздільників нема - весь рядок одне слово (або порожній)
        else { 
            lex = str; 
            if (str.length()>0) counter++;
            str = "";
        }
//        cout << "lex=" << lex << endl;
    }
    
    return counter;
};


//Дає потрібну(index)лексему з рядка, відповідно до вектора роздільників 
string getLexemeByIndex(string str, StringVector delimiters, int index){
    int counter = -1;  //номер поточної лексеми (з роздільниками)
    
    //sort delimiters. the longer - first
    sort(delimiters.begin(), delimiters.end(), compare); 
    
    while (str.length()>0){
        //1. пошук найближчого роздільника
        int delim_len =  0;     //довжина найближчого роздільника
        int delim_pos = -1;     //позиція найближчого роздільника
                                //(-1)- не знайдено жодного розд.

        //перебираємо роздільники
        for (int i=0; i<delimiters.size(); i++){ 
            //Порожні роздільники не розглядаємо
            if (delimiters[i].length()==0) continue;

            //шукаємо черговий роздільник
            int p = str.find(delimiters[i]);
            
            //якщо черговий у списку роздільник присутній в рядку
            if (p!=NPOS) { 
                if (delim_pos==-1) {    //перший знайдений роздільник
                        delim_pos = p;
                        delim_len = delimiters[i].length();
                } 
                else {                  //не перший знайдений роздільник
                    if (p < delim_pos) {
                        delim_pos = p;
                        delim_len = delimiters[i].length();
                    }
                }
            }
        }

        
        //2. виділення чергової лексеми в окрему змінну
        string lex;                 //чергова виділена лексема
        
        //якщо є принаймні 1 роздільник
        if (delim_pos != -1) { 
            //роздільник може бути на початку рядка
            if (delim_pos==0) {
                lex = str.substr(0, delim_len);
                str.erase(0,delim_len);
                counter++;
            } 
            //роздільник не на початку рядка, значить перед ним - слово
            else {
                lex = str.substr(0, delim_pos);
                str.erase(0,lex.length());
                counter++;
            }
        } 
        //якщо роздільників нема - весь рядок одне слово (або порожній)
        else { 
            lex = str; 
            if (str.length()>0) counter++;
            str = "";
        }
        
        if (counter==index) return lex;
    }
    
    return string("");
};
