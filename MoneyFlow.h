#ifndef MONEYFLOW_H
#define MONEYFLOW_H

#include <iostream>
#include "Date.h"

class MoneyFlow {
    float amountOfMoney;
    string description;
    Date date;
public:
    MoneyFlow(string,float=0,string="Today");
    int getAmountOfMoney();
    string getDescription();
    void setAmountOfMoney(float amountOfMoney);
    void setDescription(string description);
    void printMoneyFlow();
};

#endif
