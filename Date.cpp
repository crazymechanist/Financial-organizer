#include "Date.h"


Date::Date(string date):MIN_POSSIBLE_YEAR(MIN) {
    if (date=="today" || date=="Today"|| date=="TODAY") {
        setTodayDate();
    } else {
        setDate(date);
    }
}

Date::Date(int year,int month,int day):MIN_POSSIBLE_YEAR(MIN) {
    vector<int>dateArr;
    dateArr.push_back(year);
    dateArr.push_back(month);
    dateArr.push_back(day);
    if(areValuesCorrect(dateArr)) {
        this->year=year;
        this->month=month;
        this->day=day;
    }
}

bool Date::operator> (const Date &d1) const {
    int lesserFac = d1.convertDateToInt();
    int greaterFac  = convertDateToInt();
    if (greaterFac>lesserFac)
        return true;
    else
        return false;
}

bool Date::operator< (const Date &d1) const {
    int greaterFac  = d1.convertDateToInt();
    int lesserFac = convertDateToInt();
    if (greaterFac>lesserFac)
        return true;
    else
        return false;
}

bool Date::operator>= (const Date &d1) const {
    int lesserFac = d1.convertDateToInt();
    int greaterFac  = convertDateToInt();
    if (greaterFac>=lesserFac)
        return true;
    else
        return false;
}

bool Date::operator<= (const Date &d1) const {
    int greaterFac  = d1.convertDateToInt();
    int lesserFac = convertDateToInt();
    if (greaterFac>=lesserFac)
        return true;
    else
        return false;
}

bool Date::operator== (const Date &d1) const {
    int greaterFac  = d1.convertDateToInt();
    int lesserFac = convertDateToInt();
    if (greaterFac==lesserFac)
        return true;
    else
        return false;
}

Date& Date::operator- (int daysDisp) const {
    int days=convertDateToDays()-daysDisp;
    Date newDate(2000);
    if (!newDate.setDate(days)) {
        cout<<"Nie udalo sie";
    }
    return newDate;
}

Date& Date::operator+ (int daysDisp) const {
    int days=convertDateToDays()+daysDisp;
    Date newDate(2000);
    if (!newDate.setDate(days)) {
        cout<<"Nie udalo sie";
    }
    return newDate;
}

Date& Date::operator-- (int) {
    Date oldDate=*this;
    --*this;
    return oldDate;
}

Date& Date::operator++ () {
    int days=convertDateToDays()+1;
    if (!setDate(days)) {
        cout<<"Nie udalo sie";
    }
    return *this;
}

Date& Date::operator++ (int) {
    Date oldDate=*this;
    ++*this;
    return oldDate;
}

Date& Date::operator-- () {
    int days=convertDateToDays()+1;
    if (!setDate(days)) {
        cout<<"Nie udalo sie";
    }
    return *this;
}

Date& Date::operator= (const Date &d1){
    year=d1.year;
    month=d1.month;
    day=d1.day;
    return *this;
}



int Date::convertDateToInt() const {
    return (year*100+month)*100+day;
}

string Date::getDate() const {
    string date="";
    date=AuxiliaryMethods::intToStringConv(year)+"-";
    date+=AuxiliaryMethods::intToStringConv(month)+"-"+AuxiliaryMethods::intToStringConv(day);
    return date;
}

bool Date::setDate(string date) {
    if(isDateSyntaxCorrrect(date)) {
        vector<int> dateArr=parsingDate(date);
        if(areValuesCorrect(dateArr) ) {
            this->year=dateArr[0];
            this->month=dateArr[1];
            this->day=dateArr[2];
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool Date::setDate() {
    string date=AuxiliaryMethods::loadLine();
    //string date="2000-01-31";  //do debugowania sprawdzani pisowni
    if(isDateSyntaxCorrrect(date)) {
        vector<int> dateArr=parsingDate(date);
        if(areValuesCorrect(dateArr) ) {
            this->year=dateArr[0];
            this->month=dateArr[1];
            this->day=dateArr[2];
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool Date::setDate(int days) {
    if(days<0){
        return false;
    }
    int month=1;
    int year=MIN_POSSIBLE_YEAR;
    bool continueLoop=true;
    while(continueLoop) {
        int daysInYear=0;
        if(isTheYearLeaf(year)) {
            daysInYear=366;
        } else {
            daysInYear=365;
        }
        if(days>daysInYear) {
            days-=daysInYear;
            year++;
        } else {
            continueLoop=false;
        }
    }
    continueLoop=true;
    while(continueLoop) {
        int daysInMonth=howManyDaysInMonth(month,year);
        if(days>daysInMonth) {
            days-=daysInMonth;
            month++;
        } else {
            continueLoop=false;
        }
    }

    this->year=year;
    this->month=month;
    this->day=days;
    return true;
}

vector<int> Date::parsingDate(string date) {
    string delimeter = "-";
    vector<string> dateArr=AuxiliaryMethods::parsingString(date,delimeter);
    vector<int> dateArrInt=AuxiliaryMethods::stringArrToIntArrConv(dateArr);
    return dateArrInt;
}

bool Date::isDateSyntaxCorrrect(const  string date) {
    int sizeOfDate = date.size();

    if (sizeOfDate > 10)
        return false;
    if (sizeOfDate < 8)
        return false;
    if (AuxiliaryMethods::coutAStringOccurInBString("-",date)  !=2)
        return false;

    return true;
}

bool Date::isTheYearLeaf(int year) const {
    if (year%400==0)
        return true;
    else if (year % 100==0)
        return false;
    else if (year % 4 ==0)
        return true;
    else
        return false;
}

bool Date::areValuesCorrect(vector<int> date) {
    int year = date[0],month=date[1],day=date[2];

    if(year<MIN_POSSIBLE_YEAR || year>2100)
        return false;
    if(month<1 || month>12)
        return false;
    if(day<1 || day>howManyDaysInMonth(month,year))
        return false;
    return true;
}

int Date::howManyDaysInMonth(int month,int year) const {
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        if (isTheYearLeaf(year))
            return 29;
        else
            return 28;
        break;
    default:
        return 0;
    }
}

void Date::setTodayDate() {
    time_t   now = time(0);
    tm *ltm = localtime(&now);
    int year=1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    this->year=year;
    this->month=month;
    this->day=day;
    //cout<<year<<"-"<<month<<"-"<<day;
}

int Date::convertDateToDays() const  {
    int days=0;
    for(int iterYear = MIN_POSSIBLE_YEAR+1; iterYear<=year; iterYear++) {
        if(isTheYearLeaf(iterYear-1)) {
            days+=366;
        } else {
            days+=365;
        }
    }
    for(int iterMonth = 2; iterMonth<=month; iterMonth++) {
        days+=howManyDaysInMonth(iterMonth-1, year);
    }
    days+=day;

    return days;
}

//void setDate

//int Date::getDay(){
//    return day;
//}
//
//int Date::getMonth(){
//return month;
//}
//
//int Date::getYear(){
//return year;
//}
//


