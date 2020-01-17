#ifndef EXPENSESDATAFILE_H
#define EXPENSESDATAFILE_H

#include <iostream>
#include "DataFile.h"
#include "Expense.h"


using namespace std;

class ExpensesDataFile:public DataFile {
    vector <string> dataToVector(Expense &expense);
    vector <Expense> vectToData(vector<vector<string>> &data);
    vector <Expense> loadAllExpenses();
public:
    ExpensesDataFile(string ExpensesDataFileName);
    vector<Expense> loadExpensesOfOneUser(int userId);
    void saveData(vector <Expense> &expenses);
    void addData(Expense &expense);
    bool deleteData (Expense &expense);
    bool editData (Expense &editedExpense);
};

#endif
