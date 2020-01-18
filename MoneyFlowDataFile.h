#ifndef MONEYFLOWDATAFILE_H
#define MONEYFLOWDATAFILE_H

#include <iostream>
#include "DataFile.h"
#include "Expense.h"
#include "Income.h"


using namespace std;

class MoneyFlowDatafile:public DataFile {
    int lastMoneyFlowId;
    vector <string> dataToVector(MoneyFlow &moneyFlows);
    vector <MoneyFlow> vectToData(vector<vector<string>> &data);
    vector <MoneyFlow> loadAllMoneyFlows();
public:
    MoneyFlowDatafile(string,string="moneyFlows",string="moneyFlow");
    vector<MoneyFlow> loadMoneyFlowsOfOneUser(int userId);
    void saveData(vector <MoneyFlow> &moneyFlows);
    void addData(MoneyFlow &moneyFlow);
    bool deleteData (MoneyFlow &moneyFlow);
    bool editData (MoneyFlow &editedMoneyFlow);
    void loadLastMoneyFlowId();
    int getLastMoneyFlowId();
};

#endif
