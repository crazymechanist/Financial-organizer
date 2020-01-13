#ifndef FINANCIALORGANIZER_H
#define FINANCIALORGANIZER_H

#include <iostream>
#include "UserManager.h"
#include "MoneyFlowManager.h"
#include "ExpensesDataFile.h"


using namespace std;

class FinancialOrganizer{
    UserManager userManager;
    MoneyFlowManager *moneyFlowManager;
public:

    void registerUser();
    void logOutUser();
    void logInUser();
    void changePasswordOfLogInUser();
    void mainMenu();
    void showLogInUserMenu();
    void showNonLogInUserMenu();


};

#endif
