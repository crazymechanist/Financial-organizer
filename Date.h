#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>
#include "AuxiliaryMethods.h"
#define MIN 1980

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
    const int MIN_POSSIBLE_YEAR;

    bool isDateSyntaxCorrrect(string date);
    bool isTheYearLeaf(int year) const;
    bool areValuesCorrect(vector<int> date);
    vector<int> parsingDate(string date);
    int howManyDaysInMonth(int month,int year) const;
    int convertDateToDays() const;
    int convertDateToInt() const;

protected:
    bool setDate(int days);

public:

    Date(int,int=1,int=1);
    Date(string="Today");
    //Date operator < (Date const &anotherDate);
    void setTodayDate();
    bool setDate();
    bool setDate(string date);

    string getDate() const;

    bool operator< (const Date &d1) const;
    bool operator> (const Date &d1) const;
    bool operator<= (const Date &d1) const;
    bool operator>= (const Date &d1) const;
    bool operator== (const Date &d1) const;
    Date& operator--();
    Date& operator--(int);
    Date& operator++();
    Date& operator++(int);
    Date& operator- (int daysDisp) const ;
    Date& operator+ (int daysDisp) const;
    Date& operator= (const Date &d1);
    Date firstDayOfCurrMonth();
    Date lastDayOfCurrMonth();
    Date firstDayOfLastMonth();
    Date lastDayOfLastMonth();
};



#endif
