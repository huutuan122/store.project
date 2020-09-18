#include <string>
#include "Integer.h"
#include <cmath>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

int Integer::Parse(string value)
{
    return stoi(value);
}

bool Integer::tryParse(string value, int &number)
{
    // isSuccessfull is used to check if the string is a number or not
    bool isSuccessfull = true;
    try
    {
        number = stoi(value);
    }
    catch (const exception &ex)
    {
        // std::cout <<  ex.what() << endl;
        isSuccessfull = false;
    }
    return isSuccessfull;
}

bool Integer::isPrime(int number)
{
    bool isPrime = true;
    for (int i = 2; i < sqrt(number) + 1; i++)
    {
        if (number % i == 0)
            isPrime = false;
    }
    return isPrime;
}

bool Integer::isPerfect(int number)
{
    bool isPerfect = true;
    int S = 0;
    for (int i = 2; i < sqrt(number) + 1; i++)
    {
        if (number % i == 0)
            S += i;
    }
    if (S == number)
        isPerfect = false;
    return isPerfect;
}

string Integer::toString(vector<int> a, string seperator = " ")
{
    stringstream writer;
    for (int i = 0; i < a.size(); i++)
    {
        writer << a[i] << seperator;
    }
    return writer.str();
}
