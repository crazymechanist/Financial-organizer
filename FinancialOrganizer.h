#ifndef FINANCIALORGANIZER_H
#define FINANCIALORGANIZER_H

#include <iostream>
#include "UserManager.h"



using namespace std;

class FinancialOrganizer{
    UserManager userManager;
public:

    void registerUser();
    void logOutUser();
    void logInUser();
    void  changePasswordOfLogInUser();
    void  mainMenu();
    void showLogInUserMenu();
    void showNonLogInUserMenu();


};

#endif
