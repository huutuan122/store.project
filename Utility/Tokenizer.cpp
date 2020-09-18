#include "Tokenizer.h"
#include <string>
#include <vector>
#include "Integer.h"
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> Tokenizer::split(string haystack, string seperator)
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

vector<int> Tokenizer::convertToInt(string haystack, string seperator)
{
    vector<string> tokens = Tokenizer::split(haystack, seperator);
    vector<int> temp;
    int number;
    for (auto i : tokens)
    {
        bool isValid = Integer::tryParse(i, number);
        if (isValid == 1)
            temp.push_back(number);
    }
    return temp;
}

int Tokenizer::smallestNum(vector<int> a)
{
    auto b = a;
    sort(b.begin(), b.end());
    return b[0];
}

vector<int> Tokenizer::threeBiggestNum(vector<int> a)
{
    vector<int> b;
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < 3; i++)
        b.push_back(a[i]);
    return b;
}
