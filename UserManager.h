#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "AuxiliaryMethods.h"


using namespace std;

class UserManager
{
    int idOfLogInUser;
    vector <User> users;
//    PlikZUzytkownikami plikZUzytkownikami;

    User giveNewUserData();
    int getIdOfNewUser();
    bool isTheUserExist(string login);

    public:
//    UserManager(string nazwaPlikuZUzytkownikami): plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
//    uzytkownicy=plikZUzytkownikami.wczytajUzytkownikowZPliku();
//    idZalogowanegoUzytkownika=0;
//    }
    void registerUser();
    void logOutUser();
    void logInUser();
    void  changePasswordOfLogInUser();
//    void wypiszWszystkichUzytkownkow();


//    int zwrocIdZalogowanegoUzytkownika();
};

#endif
