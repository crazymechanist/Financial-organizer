#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <vector>
#include "MoneyFlow.h"
#include "AuxiliaryMethods.h"

using namespace std;

class Expense:public MoneyFlow {
    void chooseDescrition();
public:
    void editExpense();
    Expense(int=0,int=0,string="Przychod",float = 0.0,string="Today");
    Expense& operator = (const MoneyFlow &moneyFlow) ;
    static vector<Expense> convMoneyFlowsToExpenses(const vector<MoneyFlow> &moneyFlows);
    static vector<MoneyFlow> convExpensesToMoneyFlows(const vector<Expense> &expenses);
};

#endif
