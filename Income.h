#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include <vector>
#include "MoneyFlow.h"
#include "AuxiliaryMethods.h"

using namespace std;

class Income:public MoneyFlow {
    void chooseDescrition();
public:
    void editIncome();
    Income(int=0,int=0);
    Income& operator = (const MoneyFlow &moneyFlow) ;
    static vector<Income> convMoneyFlowsToIncomes(const vector<MoneyFlow> &moneyFlows);
    static vector<MoneyFlow> convIncomesToMoneyFlows(const vector<Income> &incomes);
};

#endif
