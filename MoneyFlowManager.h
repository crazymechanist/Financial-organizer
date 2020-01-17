#ifndef MONEYFLOWMANAGER_H
#define MONEYFLOWMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
#include "ExpensesDataFile.h"

using namespace std;

class MoneyFlowManager {
    const int ID_OF_LOG_IN_USER;
    int lastIdIncomes;
    int lastIdExpenses;
    ExpensesDataFile expensesDataFile;
    vector <Income> incomes;
    vector <Expense> expenses;
    void checkLastIds();
public:
    MoneyFlowManager(int=0);
    void addIncome();
    void addExpense();
    void tempSave();
};

#endif
