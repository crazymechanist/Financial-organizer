#include <iostream>
#include <vector>
#include "FinancialOrganizer.h"


using namespace std;

//int main() {
//    FinancialOrganizer financialOrganizer;
//    while(1) {
//        financialOrganizer.mainMenu();
//    }
//    return 0;

//}

int main() {
    MoneyFlowManager moneyFlowManager(1);
    Date fDat("2019-11-11");
    Date sDat("Today");
    Date mDat;
    mDat=sDat.firstDayOfLastMonth();
    cout<<mDat.getDate();
    moneyFlowManager.printBalanceOfAnotherPeriod(fDat,sDat);
    return 0;
}

