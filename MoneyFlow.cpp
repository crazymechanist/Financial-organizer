#include "MoneyFlow.h"

MoneyFlow::MoneyFlow(int id,string destription,float amountOfMoney,string date):date(date) {
    setAmountOfMoney(amountOfMoney);
    setDescription(destription);
    setId(id);
}


float MoneyFlow::getAmountOfMoney() {
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

void MoneyFlow::setDate(string myDate) {
    if(date.setDate(myDate)){ }
}

void MoneyFlow::setDescription(string description) {
    this->description=description;
}

void MoneyFlow::setId(int id) {
    this->id=id;
}

int MoneyFlow::getId() {
    return id;
}

void MoneyFlow::printMoneyFlow() {
    cout<<"Data powstania przeplywu pienieznego: "<<date.getDate()<<endl;
    cout<<"Kwota przeplywu pienieznego: "<<amountOfMoney<<endl;
    cout<<"Opis: "<<description<<endl;
}

void MoneyFlow::changeDate() {
    while(1) {
        cout<<endl<<"Czy chcesz zmienic date? ("<<date.getDate()<<") (T/N)"<<endl;
        char choice=AuxiliaryMethods::loadChar();
        switch (choice) {
        case 't':
        case 'T':
            cout<<endl<<"Podaj date w formacie RRRR-MM-DD: ";
            while(!date.setDate(AuxiliaryMethods::loadLine()))     {
                cout<<endl<<"Podaj date w poprawnym formacie RRRR-MM-DD \n(jezeli nie chcesz znianiac daty, pozostawa pole puste):";
            }
            return;
            break;
        case 'N':
        case 'n':
            return;
            break;

        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl;
            system("pause");
            break;
        }
    }
}

string MoneyFlow::getDate() {
    return date.getDate();
}

void MoneyFlow::changeAmountOfMoney() {
    cout<<endl<<"Kwota: ";
    setAmountOfMoney(AuxiliaryMethods::loadFloat());
}
