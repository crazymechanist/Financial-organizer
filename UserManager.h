#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "UsersDataFile.h"


using namespace std;

class UserManager
{
    int idOfLogInUser;
    vector <User> users;
    UsersDataFile usersDataFile;
    User giveNewUserData();
    int getIdOfNewUser();
    bool isTheUserExist(string login);

    public:
    UserManager();
    int getIdOfLogInUser();
    void registerUser();
    void logOutUser();
    void logInUser();
    void  changePasswordOfLogInUser();
};

#endif
