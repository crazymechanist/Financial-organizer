#include <iostream>
#include <vector>
#include "FinancialOrganizer.h"
#include "ExpensesDataFile.h"

using namespace std;

int main() {
    MoneyFlowManager moneyFlowManager;
//    ifstream in("in.txt");
//    streambuf *cinbuf = cin.rdbuf(); //save old buf
//    cin.rdbuf(in.rdbuf()); //redirect cin to in.txt!
//    for(int i=0; i<5; i++) {
//        moneyFlowManager.addExpense();
//    }
//    cin.rdbuf(cinbuf); //reset to standard input again
//    moneyFlowManager.saveData();
    moneyFlowManager.loadData();
    return 0;
}

