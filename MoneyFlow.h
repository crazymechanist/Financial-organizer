#ifndef MONEYFLOW_H
#define MONEYFLOW_H

#include <iostream>
#include "Date.h"

class MoneyFlow {
    int id;
protected:
    float amountOfMoney;
    string description;
    Date date;
public:
    MoneyFlow(int=0,string="",float=0,string="Today");
    int getId(int id);
    int getAmountOfMoney();
    string getDescription();
    void setId(int id);
    void setAmountOfMoney(float amountOfMoney);
    void setDescription(string description);
    void printMoneyFlow();
};

#endif
