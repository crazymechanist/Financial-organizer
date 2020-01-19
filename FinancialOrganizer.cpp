#include "FinancialOrganizer.h"

FinancialOrganizer::FinancialOrganizer() {
    moneyFlowManager=NULL;
}

FinancialOrganizer::~FinancialOrganizer() {
    delete moneyFlowManager;
    moneyFlowManager=NULL;
}

void FinancialOrganizer::registerUser() {
    userManager.registerUser();
}

void FinancialOrganizer::addExpense() {
    moneyFlowManager->addExpense();
}

void FinancialOrganizer::addIncome() {
    moneyFlowManager->addIncome();
}

void FinancialOrganizer::printBalanceOfCurrentMonth() {
    cout << "Przeplywy z obecnego miesiaca" << endl;
    cout << "---------------------------" << endl<< endl;
    Date date("Today");
    Date firstDate=date.firstDayOfCurrMonth();
    Date secondDate=date.lastDayOfCurrMonth();
    moneyFlowManager->printBalanceOfAnyPeriod(firstDate,secondDate);
}

void FinancialOrganizer::printBalanceOfLastMonth() {
    cout << "Przeplywy z zeszlego miesiaca" << endl;
    cout << "---------------------------" << endl<< endl;
    Date date("Today");
    Date firstDate=date.firstDayOfLastMonth();
    Date secondDate=date.lastDayOfLastMonth();
    moneyFlowManager->printBalanceOfAnyPeriod(firstDate,secondDate);
}

void FinancialOrganizer::printBalanceOfAnyPeriod() {
    cout << "Przeplywy z dowolnego okresu" << endl;
    cout << "---------------------------" << endl<< endl;
    Date firstDate("Today");
    firstDate=firstDate.firstDayOfCurrMonth();
    Date secondDate("Today");
    secondDate=secondDate.lastDayOfCurrMonth();
    cout<<"Poczatkowa data: "<<firstDate.getDate()<<"\n";
    firstDate.changeDate();
    cout<<"\nKoncowa data: "<<secondDate.getDate()<<"\n";
    secondDate.changeDate();
    moneyFlowManager->printBalanceOfAnyPeriod(firstDate,secondDate);
}

void FinancialOrganizer::logOutUser() {
    userManager.logOutUser();
    delete moneyFlowManager;
    moneyFlowManager = NULL;
}
void FinancialOrganizer::logInUser() {
    userManager.logInUser();
    int userID=userManager.getIdOfLogInUser();
    if (userID != 0) {
        moneyFlowManager = new MoneyFlowManager(userID);
    }
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
        case '1':
            system("cls");
            addExpense();
            break;
        case '2':
            system("cls");
            addIncome();
            break;
        case '3':
            system("cls");
            printBalanceOfCurrentMonth();
            break;
        case '4':
            system("cls");
            printBalanceOfLastMonth();
            break;
        case '5':
            system("cls");
            printBalanceOfAnyPeriod();
            break;
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
    cout << "1. Dodaj wydatek" << endl;
    cout << "2. Dodaj przychod" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
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


