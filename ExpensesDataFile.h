#ifndef EXPENSESDATAFILE_H
#define EXPENSESDATAFILE_H

#include <iostream>
#include "DataFile.h"
#include "Expense.h"


using namespace std;

class ExpensesDataFile:public DataFile {
    void addToVector(vector<string> &fields,string fieldData);
public:
    ExpensesDataFile(string ExpensesDataFileName);
    vector<Expense> loadData();
    void saveData(vector <Expense> &expenses);
};

#endif
