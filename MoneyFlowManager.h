#ifndef MONEYFLOWMANAGER_H
#define MONEYFLOWMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
#include "ExpensesDataFile.h"

using namespace std;

class MoneyFlowManager {
    int lastIdIncomes;
    int lastIdExpenses;
    ExpensesDataFile expensesDataFile;
    vector <Income> incomes;
    vector <Expense> expenses;
    void checkLastIds();
public:
    MoneyFlowManager();
    void addIncome();
    void addExpense();
    void saveData();
    void loadData();

};

#endif
