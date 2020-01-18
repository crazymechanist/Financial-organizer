#ifndef MONEYFLOW_H
#define MONEYFLOW_H

#include <iostream>
#include "Date.h"

class MoneyFlow {

protected:
    int id;
    int idOfOwnUser;
    float amountOfMoney;
    string description;
    Date date;
public:
    MoneyFlow(int=0,int=0,string="",float=0,string="Today");
    int getId() const;
    int getIdOfOwnUser() const;
    float getAmountOfMoney() const;
    string getDescription() const;
    void setId(int id);
    void setIdOfOwnUser(int userId);
    void setDate(string date);
    void setAmountOfMoney(float amountOfMoney);
    void setDescription(string description);
    void printMoneyFlow();
    void changeDate();
    void changeAmountOfMoney();
    string getDate() const;
};

#endif
