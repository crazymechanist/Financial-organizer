#include <iostream>
#include "FinancialOrganizer.h"
#include "ExpensesDataFile.h"
#include "DataFile.h"
#include "MoneyFlow.h"


using namespace std;

//int main() {
//    FinancialOrganizer financialOrganizer;
//
//    while(1) {
//        financialOrganizer.mainMenu();
//    }
//
//    return 0;
//}

int main() {
    MoneyFlow moneyFlow1("Bla bla",100.23,"2000-11-11");
    moneyFlow1.printMoneyFlow();
    MoneyFlow moneyFlow2("Bla bla2",200.23,"2000-11-11");
    moneyFlow2.printMoneyFlow();
    MoneyFlow moneyFlow3("Bla bla3",300.23);
    moneyFlow3.printMoneyFlow();
    return 0;
}
