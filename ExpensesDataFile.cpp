#include "ExpensesDataFile.h"

ExpensesDataFile::ExpensesDataFile(string ExpensesDataFileName):DataFile(ExpensesDataFileName) {
    parentNodeName="expenses";
    childNodeName="expense";
    addSecondChildNodesNames("id");
    addSecondChildNodesNames("description");
    addSecondChildNodesNames("amount");
    addSecondChildNodesNames("date");
}

vector<Expense> ExpensesDataFile::loadData() {
    vector<vector<string>> data;
    vector<Expense> expenses;
    data=DataFile::loadData();
    for(int i=0; i<data.size(); i++) {
        Expense tempExpense;
        tempExpense.setId(AuxiliaryMethods::stringToIntConv(data[i][0]));
        tempExpense.setDescription(data[i][1]);
        tempExpense.setAmountOfMoney(AuxiliaryMethods::stringToFloatConv(data[i][2]));
        tempExpense.setDate(data[i][3]);
        expenses.push_back(tempExpense);
    }
    return expenses;
}

void ExpensesDataFile::addToVector(vector<string> &fields,string fieldData) {
    fields.push_back(fieldData);
}

void ExpensesDataFile::saveData(vector <Expense> &expenses) {
    vector <vector<string>> data;
    for(int i=0; i<expenses.size(); i++) {
        vector<string> fields;
        addToVector(fields,AuxiliaryMethods::intToStringConv(expenses[i].getId()));
        addToVector(fields,expenses[i].getDescription());
        addToVector(fields,AuxiliaryMethods::floatToStringConv(expenses[i].getAmountOfMoney()));
        addToVector(fields,expenses[i].getDate());
        data.push_back(fields);
    }
    DataFile::saveData(data);
}


