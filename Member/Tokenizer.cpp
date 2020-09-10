#include "Tokenizer.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> TokenizerStr::split(string haystack, string seperator)
{
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
