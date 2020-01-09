#include <iostream>
#include <vector>
#include "FinancialOrganizer.h"
#include "ExpensesDataFile.h"
#include "DataFile.h"
#include "MoneyFlow.h"
#include "Income.h"



using namespace std;


int main() {
    Income income(2);
    income.printMoneyFlow();
    income.editIncome();
    income.printMoneyFlow();

//    DataFile dataFile("ALA.xml");
//    vector<DataFile::Abecadlo> abcs;
//    int j=10;
//    for(int i=0; i<10; i++) {
//        DataFile::Abecadlo abc1;
//        abc1.a=j++;
//        abc1.b=j++;
//        abc1.c=j++;
//        abcs.push_back(abc1);
//    }
//    dataFile.metaSaveData(abcs);

    return 0;
}



