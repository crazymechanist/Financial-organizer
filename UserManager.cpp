#include "UserManager.h"

UserManager::UserManager():usersDataFile("users.xml") {
    users=usersDataFile.loadData();
    idOfLogInUser=0;
}

void UserManager::registerUser() {
    cout<<"REJESTRACJA UZYTKOWNIKA\n________________________\n\n";
    int id=getIdOfNewUser();
    string login="", password="", name="", surname="";
    cout<<"Podaj login: ";
    login=AuxiliaryMethods::loadLine();
    cout<<"Podaj haslo: ";
    password=AuxiliaryMethods::loadLine();
    cout<<"Podaj imie uzytkownika: ";
    name=AuxiliaryMethods::loadLine();
    cout<<"Podaj nazisko uzytkownika: ";
    surname=AuxiliaryMethods::loadLine();
    User user(id,login,password,name,surname);
    users.push_back(user);
    usersDataFile.addData(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
    system("cls");
}

int UserManager::getIdOfNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isTheUserExist(string login) {
    for (int i=0; i<users.size(); i++) {
        if(users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::logOutUser() {
    idOfLogInUser =0;
}

void UserManager::logInUser() {
    cout<<"LOGOWANIE UZYTKOWNIKA\n________________________\n\n";
    string login = "", password = "";
    int iter=0;

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    while (iter != users.size()) {
        if (users[iter].getLogin() == login)        {
            for (int numberOfTrials = 3; numberOfTrials > 0; numberOfTrials--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfTrials << ": ";
                password = AuxiliaryMethods::loadLine();

                if (users[iter].getPassword() == password) {
                    cout << endl << "Logowanie pomyslne. Witaj " <<users[iter].getName()<<" "
                         <<users[iter].getSurname()<<endl;
                    system("pause");
                    system("cls");
                    idOfLogInUser = users[iter].getId();
                    iter = users.size();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            iter = users.size();
        }
        iter++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    system("cls");
    return;
}

void UserManager::changePasswordOfLogInUser() {
    cout<<"ZMIANA HASLA ZALOGOWANEGO UZYTKOWNIKA\n________________________\n\n";
    string newPassword = "";
    int iter=0;
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    while (iter != users.size()) {
        if (users[iter].getId()== idOfLogInUser) {
            users[iter].setPassword(newPassword);
            cout << "Haslo konta "<<users[iter].getName()<<" "<< users[iter].getSurname()<<" zostalo zmienione." << endl << endl;
            system("pause");
            system("cls");
            iter= users.size();
        }
        iter++;
    }
//    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

int UserManager::getIdOfLogInUser() {
    return idOfLogInUser;
}





