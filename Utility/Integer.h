#include <string>
#include <vector>
using namespace std;
#ifndef _INTEGER_H_
#define _INTEGER_H_

class Integer
{
public:
    static int Parse(string value);
    static bool tryParse(string value, int &number);
    static bool isPrime(int number);
    static bool isPerfect(int number);
    static string toString(vector<int> a, string seperator);
};

#endif