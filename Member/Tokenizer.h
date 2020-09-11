#include <string>
#include <vector>
using namespace std;

#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

class TokenizerStr
{
public: // Methods
    static vector<string> split(string haystack, string seperator){
        string _haystack = haystack;
        vector<string> temp;
        int startPosition = 0;
        int foundPosition = haystack.find(seperator, startPosition);
        temp.push_back(haystack.substr(startPosition, foundPosition - startPosition));
        while (foundPosition != string::npos)
        {
            startPosition = foundPosition + seperator.size();
            foundPosition = haystack.find(seperator, startPosition);
            temp.push_back(haystack.substr(startPosition, foundPosition - startPosition));
        }
        return temp;
    }
};

#endif