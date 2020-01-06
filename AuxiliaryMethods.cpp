#include "AuxiliaryMethods.h"

int AuxiliaryMethods::loadInteger()
{
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

int AuxiliaryMethods::stringToIntConv (string number) {
    int numberInt;
    stringstream myStream(number);
    myStream >> numberInt;
    return numberInt;
}

string AuxiliaryMethods::intToStringConv(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::loadLine() {
    string input = "";
    getline(cin, input);
    return input;
}

int AuxiliaryMethods::coutAStringOccurInBString(string lookForString, string baseString){
    int occurenceAmount=0;
    size_t position = baseString.find(lookForString);
    while (position!=string::npos) {
        position = baseString.find(lookForString,position+1);
        occurenceAmount++;
    }
    return occurenceAmount;
}

vector<string> AuxiliaryMethods::parsingString(string baseString, string delimiter) {
    vector<string> substrings;
    size_t position = baseString.find(delimiter);
    while (position!=string::npos) {
        string mySubstring="";
        mySubstring=baseString.substr(0,position);
        baseString.erase(0,position+1);
        substrings.push_back(mySubstring);
        position = baseString.find(delimiter);
    }
    substrings.push_back(baseString);
    return substrings;
}

vector<int> AuxiliaryMethods::stringArrToIntArrConv (vector<string> numbers) {
    vector<int> intNumbers;
    for(int i=0;i<numbers.size(); i++) {
        intNumbers.push_back(stringToIntConv(numbers[i]));
    }
    return intNumbers;
}

char AuxiliaryMethods::loadChar(){
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}


