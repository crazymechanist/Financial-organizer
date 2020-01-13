#include "MoneyFlowManager.h"

MoneyFlowManager::MoneyFlowManager():lastIdIncomes(0), lastIdExpenses(0),expensesDataFile("expenses.xml") {
    checkLastIds();
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

void MoneyFlowManager::saveData() {
    expensesDataFile.saveData(expenses);
}

void MoneyFlowManager::loadData() {
    expenses=expensesDataFile.loadData();
}
