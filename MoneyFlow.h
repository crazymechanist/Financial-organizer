#ifndef MONEYFLOW_H
#define MONEYFLOW_H

#include <iostream>
#include "Date.h"

class MoneyFlow {
    int id;
protected:
    int idOfOwnUser;
    float amountOfMoney;
    string description;
    Date date;
public:
    MoneyFlow(int=0,int=0,string="",float=0,string="Today");
    int getId();
    int getIdOfOwnUser();
    float getAmountOfMoney();
    string getDescription();
    void setId(int id);
    void setIdOfOwnUser(int userId);
    void setDate(string date);
    void setAmountOfMoney(float amountOfMoney);
    void setDescription(string description);
    void printMoneyFlow();
    void changeDate();
    void changeAmountOfMoney();
    string getDate();
};

#endif
