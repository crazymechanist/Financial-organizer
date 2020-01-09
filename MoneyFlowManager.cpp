#include "MoneyFlowManager.h"

MoneyFlowManager::MoneyFlowManager():lastId(0) {
    checkLastId();
}

void MoneyFlowManager::addIncome() {
    Income tempIncome(lastId);
    incomes.push_back(tempIncome);
}

void MoneyFlowManager::checkLastId() {

}
