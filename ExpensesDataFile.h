#ifndef EXPENSESDATAFILE_H
#define EXPENSESDATAFILE_H

#include <iostream>
#include "DataFile.h"


using namespace std;

class ExpensesDataFile:public DataFile {

public:
    ExpensesDataFile(string ExpensesDataFileName);
    void loadData();
    void saveData();
};

#endif
