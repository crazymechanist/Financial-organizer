#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include <vector>
#include "MoneyFlow.h"
#include "AuxiliaryMethods.h"

using namespace std;

class Income:public MoneyFlow {
void chooseDescrition();
void chooseDate();
public:
void editIncome();
Income(int=0);
};

#endif