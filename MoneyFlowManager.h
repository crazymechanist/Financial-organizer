#ifndef MONEYFLOWMANAGER_H
#define MONEYFLOWMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Income.h"
#include "Expense.h"
#include "MoneyFlowDataFile.h"

using namespace std;

class MoneyFlowManager {

    struct ComparatorIncome {
        bool operator() (Income firstIncome,Income secondIncome) {
            return firstIncome.getDate() < secondIncome.getDate();
        }
    } comparatorIncome;

    struct ComparatorExpense {
        bool operator() (Expense firstExpense,Expense secondExpense) {
            return firstExpense.getDate() < secondExpense.getDate();
        }
    } comparatorExpense;

    const int ID_OF_LOG_IN_USER;
    int lastIdIncomes;
    int lastIdExpenses;
    MoneyFlowDatafile expensesDataFile;
    MoneyFlowDatafile incomesDataFile;
    vector <Income> incomes;
    vector <Expense> expenses;
    void checkLastIds();
    double sumOfIncomes(Date &firstDate, Date &lastDate);
    double sumOfExpenses(Date &firstDate, Date &lastDate);
    double calculateBottomLine(Date &firstDate, Date &lastDate);
public:
    MoneyFlowManager(int=0);
    void addIncome();
    void addExpense();
    void sortIncomes();
    void sortExpenses();
    void printBalanceOfAnotherPeriod(Date &firstDay, Date &lastDay);

};

#endif
