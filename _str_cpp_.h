#ifndef __STR_CPP_h__
#define __STR_CPP_h__

#include <string>
#include <vector>

using namespace std;

typedef vector<string> StringVector;

int    countOfLexems   (string str, StringVector delimiters);
string getLexemeByIndex(string str, StringVector delimiters, int index);

#endif  //__STR_CPP_h__

