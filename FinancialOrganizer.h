#ifndef FINANCIALORGANIZER_H
#define FINANCIALORGANIZER_H

#include <iostream>
#include "UserManager.h"
#include "MoneyFlowManager.h"
#include "ExpensesDataFile.h"


using namespace std;

class FinancialOrganizer {
    UserManager userManager;
    MoneyFlowManager *moneyFlowManager;
    void registerUser();
    void logOutUser();
    void logInUser();
    void changePasswordOfLogInUser();
    void showLogInUserMenu();
    void showNonLogInUserMenu();
    void printBalanceOfCurrentMonth();
    void printBalanceOfLastMonth();
    void printBalanceOfAnyPeriod();
    void addExpense();
    void addIncome();
public:
    void mainMenu();
    FinancialOrganizer();
    ~FinancialOrganizer();
};

#endif
