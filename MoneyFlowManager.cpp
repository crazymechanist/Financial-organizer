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

double MoneyFlowManager::sumOfExpenses(Date &firstDate, Date &lastDate) {
    double sum=0;
    for(vector<Expense>::iterator itr=expenses.begin(); itr != expenses.end(); ++itr) {
        if((itr->getDate()>= firstDate) &&
                (itr->getDate() <= lastDate)) {
            sum+=AuxiliaryMethods::floatToDouble(itr->getAmountOfMoney());
        }
    }
    return sum;
}

double MoneyFlowManager::sumOfIncomes(Date &firstDate, Date &lastDate) {
    double sum=0;
    for(vector<Income>::iterator itr=incomes.begin(); itr != incomes.end(); ++itr) {
        if((itr->getDate()>= firstDate) &&
                (itr->getDate() <= lastDate)) {
            sum+=AuxiliaryMethods::floatToDouble(itr->getAmountOfMoney());
        }
    }
    return sum;
}

double MoneyFlowManager::calculateBottomLine(Date &firstDate, Date &lastDate) {
    double expensesSum=sumOfExpenses(firstDate, lastDate);
    double incomesSum=sumOfIncomes(firstDate, lastDate);
    return (incomesSum-expensesSum);
}

void MoneyFlowManager::sortIncomes() {
    sort(incomes.begin(),incomes.end(),comparatorIncome);
}

void MoneyFlowManager::sortExpenses() {
    sort(expenses.begin(),expenses.end(),comparatorExpense);
}

void MoneyFlowManager::printBalanceOfAnyPeriod(Date &firstDate, Date &lastDate) {
    if(firstDate<lastDate) {
        cout<<"PRZYCHODY: "<<endl
            <<"---------------------------------------";
        for(vector<Income>::iterator itr=incomes.begin(); itr != incomes.end(); ++itr) {
            if((itr->getDate()>= firstDate) &&
                    (itr->getDate() <= lastDate)) {
                cout<<endl;
                itr->printMoneyFlow();
                cout<<endl;
            }
        }
        cout<<"\nWYDATKI: "<<endl
            <<"---------------------------------------";
        for(vector<Expense>::iterator itr=expenses.begin(); itr != expenses.end(); ++itr) {
            if((itr->getDate()>= firstDate) &&
                    (itr->getDate() <= lastDate)) {
                cout<<endl;
                itr->printMoneyFlow();
                cout<<endl;
            }
        }
        cout<<"\n---------------------------------------"<<endl
            <<"SALDO: "<<endl
            <<calculateBottomLine(firstDate,lastDate)<<" PLN"<<endl;
    }
    system("pause");
    system("cls");
}




