#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <windows.h>
#include <vector>

using namespace std;

class AuxiliaryMethods {
public:
static int loadInteger();
static char loadChar();
static string loadLine();
static int stringToIntConv (string number);
static string intToStringConv(int number);
static int coutAStringOccurInBString(string lookForString, string BaseString);
static vector<string> parsingString(string baseString, string delimiter);
static vector<int> stringArrToIntArrConv (vector<string> numbers);

};

#endif
