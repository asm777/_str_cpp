#include "_str_cpp_.h"
#include <iostream>
#include <algorithm> //for sort()

#define NPOS std::string::npos

using namespace std;

bool compare (const string& str1, const string& str2);

bool compare (const string& str1, const string& str2) {
    return str1.length() > str2.length();  
}

//�� ������� ������ � �����, �������� �� ������� ���������� 
int countOfLexems(string str, StringVector delimiters){
    int counter = 0;  //�������� ������� ������ (� ������������)
    
    //sort delimiters. the longer - first
    sort(delimiters.begin(), delimiters.end(), compare); 
 
    while (str.length()>0){
        //1. ����� ����������� ����������
        int delim_len =  0;     //������� ����������� ����������
        int delim_pos = -1;     //������� ����������� ����������
                                //(-1)- �� �������� ������� ����.

        //���������� ����������
        for (int i=0; i<delimiters.size(); i++){ 
            //������ ���������� �� ����������
            if (delimiters[i].length()==0) continue;
            
            //������ �������� ���������
            int p = str.find(delimiters[i]);
            
            //���� �������� � ������ ��������� �������� � �����
            if (p!=NPOS) { 
                if (delim_pos==-1) {    //������ ��������� ���������
                        delim_pos = p;
                        delim_len = delimiters[i].length();
                } 
                else {                  //�� ������ ��������� ���������
                    if (p < delim_pos) {
                        delim_pos = p;
                        delim_len = delimiters[i].length();
                    }
                }
            }
        }
        
        //2. �������� ������� ������� � ������ �����
        string lex;                 //������� ������� �������
        
        //� �������� 1 ���������
        if (delim_pos != -1) { 
            //��������� ���� ���� �� ������� �����
            if (delim_pos==0) {
                lex = str.substr(0, delim_len);
                str.erase(0,delim_len);
                counter++;
            } 
            //��������� �� �� ������� �����, ������� ����� ��� - �����
            else {
                lex = str.substr(0, delim_pos);
                str.erase(0,lex.length());
                counter++;
            }
        } 
        //���������� ���� - ���� ����� ���� ����� (��� �������)
        else { 
            lex = str; 
            if (str.length()>0) counter++;
            str = "";
        }
//        cout << "lex=" << lex << endl;
    }
    
    return counter;
};


//�� �������(index)������� � �����, �������� �� ������� ���������� 
string getLexemeByIndex(string str, StringVector delimiters, int index){
    int counter = -1;  //����� ������� ������� (� ������������)
    
    //sort delimiters. the longer - first
    sort(delimiters.begin(), delimiters.end(), compare); 
    
    while (str.length()>0){
        //1. ����� ����������� ����������
        int delim_len =  0;     //������� ����������� ����������
        int delim_pos = -1;     //������� ����������� ����������
                                //(-1)- �� �������� ������� ����.

        //���������� ����������
        for (int i=0; i<delimiters.size(); i++){ 
            //������ ���������� �� ����������
            if (delimiters[i].length()==0) continue;

            //������ �������� ���������
            int p = str.find(delimiters[i]);
            
            //���� �������� � ������ ��������� �������� � �����
            if (p!=NPOS) { 
                if (delim_pos==-1) {    //������ ��������� ���������
                        delim_pos = p;
                        delim_len = delimiters[i].length();
                } 
                else {                  //�� ������ ��������� ���������
                    if (p < delim_pos) {
                        delim_pos = p;
                        delim_len = delimiters[i].length();
                    }
                }
            }
        }

        
        //2. �������� ������� ������� � ������ �����
        string lex;                 //������� ������� �������
        
        //���� � �������� 1 ���������
        if (delim_pos != -1) { 
            //��������� ���� ���� �� ������� �����
            if (delim_pos==0) {
                lex = str.substr(0, delim_len);
                str.erase(0,delim_len);
                counter++;
            } 
            //��������� �� �� ������� �����, ������� ����� ��� - �����
            else {
                lex = str.substr(0, delim_pos);
                str.erase(0,lex.length());
                counter++;
            }
        } 
        //���� ���������� ���� - ���� ����� ���� ����� (��� �������)
        else { 
            lex = str; 
            if (str.length()>0) counter++;
            str = "";
        }
        
        if (counter==index) return lex;
    }
    
    return string("");
};
