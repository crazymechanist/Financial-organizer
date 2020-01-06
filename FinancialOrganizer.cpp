#include "FinancialOrganizer.h"

void FinancialOrganizer::registerUser() {
    userManager.registerUser();
}

void FinancialOrganizer::logOutUser() {
    userManager.logOutUser();
}
void FinancialOrganizer::logInUser() {
    userManager.logInUser();
}

void  FinancialOrganizer::changePasswordOfLogInUser() {
    userManager.changePasswordOfLogInUser();
}

void  FinancialOrganizer::mainMenu() {
    char choice=0;
    if (userManager.getIdOfLogInUser() == 0) {
        showNonLogInUserMenu();
        choice=AuxiliaryMethods::loadChar();
        switch (choice) {
        case '1':
            system("cls");
            registerUser();
            break;
        case '2':
            system("cls");
            logInUser();
            break;
        case '9':
            system("cls");
            exit(0);
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl;
            system("pause");
            break;
        }
    } else {
        showLogInUserMenu();
        choice=AuxiliaryMethods::loadChar();
        switch (choice) {
        case '8':
            system("cls");
            changePasswordOfLogInUser();
            break;
        case '9':
            system("cls");
            logOutUser();
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl;
            system("pause");
            break;
        }
    }
    system("cls");
}

void  FinancialOrganizer::showLogInUserMenu() {
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "8. Zmien haslo" << endl;
    cout << "9. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
}

void  FinancialOrganizer::showNonLogInUserMenu() {
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
}


