#include "MoneyFlowManager.h"

MoneyFlowManager::MoneyFlowManager(int idOfLogInUser):ID_OF_LOG_IN_USER(idOfLogInUser),lastIdIncomes(0), lastIdExpenses(0),expensesDataFile("expenses.xml","expenses","expense") {
    checkLastIds();
    expenses=Expense::convMoneyFlowsToExpenses(expensesDataFile.loadMoneyFlowsOfOneUser(idOfLogInUser));
}

void MoneyFlowManager::addIncome() {
    lastIdIncomes++;
    Income tempIncome(lastIdIncomes);
    tempIncome.editIncome();
    incomes.push_back(tempIncome);
}

void MoneyFlowManager::addExpense() {
    lastIdExpenses++;
    Expense tempExpense(lastIdExpenses);
    tempExpense.editExpense();
    expenses.push_back(tempExpense);
}

void MoneyFlowManager::checkLastIds() {
//oddeleguj do pliku
}

void MoneyFlowManager::tempSave() {
    vector<MoneyFlow>moneyFlows=(Expense::convExpensesToMoneyFlows(expenses));
    expensesDataFile.saveData(moneyFlows);
}





