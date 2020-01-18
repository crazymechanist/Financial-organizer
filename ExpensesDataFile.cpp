#include "ExpensesDataFile.h"

ExpensesDataFile::ExpensesDataFile(string ExpensesDataFileName):DataFile(ExpensesDataFileName) {
    parentNodeName="expenses";
    childNodeName="expense";
    addSecondChildNodesNames("id");
    addSecondChildNodesNames("user_id");
    addSecondChildNodesNames("description");
    addSecondChildNodesNames("amount");
    addSecondChildNodesNames("date");
}

vector<Expense> ExpensesDataFile::loadAllExpenses() {
    vector<vector<string>> data;
    vector<Expense> expenses;
    data=DataFile::loadData();
    expenses=vectToData(data);
    return expenses;
}

vector<Expense> ExpensesDataFile::loadExpensesOfOneUser(int userId) {
    vector<vector<string>> data;
    vector<Expense> expenses;
    data=DataFile::loadCertainData(2,AuxiliaryMethods::intToStringConv(userId));
    expenses=vectToData(data);
    return expenses;
}

vector <Expense> ExpensesDataFile::vectToData(vector<vector<string>> &data) {
    vector<Expense> expenses;
    for(int i=0; i<data.size(); i++) {
        Expense tempExpense;
        int j=0;
        tempExpense.setId(AuxiliaryMethods::stringToIntConv(data[i][j++]));
        tempExpense.setIdOfOwnUser(AuxiliaryMethods::stringToIntConv(data[i][j++]));
        tempExpense.setDescription(data[i][j++]);
        tempExpense.setAmountOfMoney(AuxiliaryMethods::stringToFloatConv(data[i][j++]));
        tempExpense.setDate(data[i][j++]);
        expenses.push_back(tempExpense);
    }
    return expenses;
}

vector <string> ExpensesDataFile::dataToVector(Expense &expense) {
    vector<string> vec;
    addToVector(vec,AuxiliaryMethods::intToStringConv(expense.getId()));
    addToVector(vec,AuxiliaryMethods::intToStringConv(expense.getIdOfOwnUser()));
    addToVector(vec,expense.getDescription());
    addToVector(vec,AuxiliaryMethods::floatToStringConv(expense.getAmountOfMoney()));
    addToVector(vec,expense.getDate());
    return vec;
}

void ExpensesDataFile::saveData(vector <Expense> &expenses) {
    vector <vector<string>> data;
    for(int i=0; i<expenses.size(); i++) {
        vector<string> fields=dataToVector(expenses[i]);
        data.push_back(fields);
    }
    DataFile::saveData(data);
}

void ExpensesDataFile::addData(Expense &expense) {
    vector<string> fields=dataToVector(expense);
    DataFile::addData(fields);
}

bool ExpensesDataFile::deleteData (Expense &expense) {
    bool isTheOperationGood=false;
    vector<string> fields=dataToVector(expense);
    isTheOperationGood=DataFile::deleteData(fields);
    return isTheOperationGood;
}

bool ExpensesDataFile::editData (Expense &editedExpense) {
    bool isTheOperationGood=false;
    vector<string> fields=dataToVector(editedExpense);
    isTheOperationGood=DataFile::editData(fields,0);
    return isTheOperationGood;
}
