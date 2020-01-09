#include "MoneyFlow.h"

MoneyFlow::MoneyFlow(int id,string destription,float amountOfMoney,string date):date(date) {
    setAmountOfMoney(amountOfMoney);
    setDescription(destription);
    setId(id);
}


int MoneyFlow::getAmountOfMoney() {
    return amountOfMoney;
}

string MoneyFlow::getDescription() {
    return description;
}

void MoneyFlow::setAmountOfMoney(float amountOfMoney) {
    if(amountOfMoney>0) {
        this->amountOfMoney=amountOfMoney;
    } else {
        this->amountOfMoney=0;
    }

}

void MoneyFlow::setDescription(string description) {
    this->description=description;
}

void MoneyFlow::setId(int id) {
    this->id=id;
}

void MoneyFlow::printMoneyFlow() {
    cout<<"Data powstania przeplywu pienieznego: "<<date.getDate()<<endl;
    cout<<"Kwota przeplywu pienieznego: "<<amountOfMoney<<endl;
    cout<<"Opis: "<<description<<endl;
}