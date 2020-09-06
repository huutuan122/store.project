#include <string>
#include <vector>
using namespace std;


#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

class Tokenizer
{
public: // Methods
    static vector<string> split(string haystack, string seperator);
};

#endif