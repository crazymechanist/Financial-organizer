#ifndef MONEYFLOWMANAGER_H
#define MONEYFLOWMANAGER_H

#include <iostream>
#include "Income.h"
#include <vector>

using namespace std;

class MoneyFlowManager {
    int lastId;
    vector <Income> incomes;
public:
    MoneyFlowManager();
    void addIncome();
    void checkLastId();
};

#endif
