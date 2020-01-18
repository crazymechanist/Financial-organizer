#include "MoneyFlowManager.h"

MoneyFlowManager::MoneyFlowManager(int idOfLogInUser):ID_OF_LOG_IN_USER(idOfLogInUser),lastIdIncomes(0), lastIdExpenses(0),
    expensesDataFile("expenses.xml","expenses","expense")
    ,incomesDataFile("incomes.xml","incomes","income") {
    checkLastIds();
    expenses=Expense::convMoneyFlowsToExpenses(expensesDataFile.loadMoneyFlowsOfOneUser(idOfLogInUser));
    incomes=Income::convMoneyFlowsToIncomes(incomesDataFile.loadMoneyFlowsOfOneUser(idOfLogInUser));
    sortExpenses();
    sortIncomes();
}

void MoneyFlowManager::addIncome() {
    Income tempIncome(++lastIdIncomes,ID_OF_LOG_IN_USER);
    tempIncome.editIncome();
    incomesDataFile.addData(tempIncome);
    incomes.push_back(tempIncome);
}

void MoneyFlowManager::addExpense() {
    Expense tempExpense(++lastIdExpenses,ID_OF_LOG_IN_USER);
    tempExpense.editExpense();
    expensesDataFile.addData(tempExpense);
    expenses.push_back(tempExpense);
}

void MoneyFlowManager::checkLastIds() {
    lastIdExpenses=expensesDataFile.getLastMoneyFlowId();
    lastIdIncomes=incomesDataFile.getLastMoneyFlowId();
}

double MoneyFlowManager::sumOfVect(vector<Expense> &vec) {
    double sum=0;
    for(int i=0; i<vec.size(); i++) {
        sum+=AuxiliaryMethods::floatToDouble(vec[i].getAmountOfMoney() );
    }
    return sum;
}

double MoneyFlowManager::sumOfVect(vector<Income> &vec) {
    double sum=0;
    for(int i=0; i<vec.size(); i++) {
        sum+=AuxiliaryMethods::floatToDouble(vec[i].getAmountOfMoney() );
    }
    return sum;
}

double MoneyFlowManager::calculateBottomLine() {
    double sumOfExpenses=sumOfVect(expenses);
    double sumOfIncomes=sumOfVect(incomes);
    return (sumOfIncomes-sumOfExpenses);
}

void MoneyFlowManager::sortIncomes() {
   sort(incomes.begin(),incomes.end(),comparatorIncome);
}

void MoneyFlowManager::sortExpenses() {
    sort(expenses.begin(),expenses.end(),comparatorExpense);
}




