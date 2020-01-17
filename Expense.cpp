#include "Expense.h"

Expense::Expense(int id,int userId): MoneyFlow(id,userId, "Przychod") {

}

void Expense::chooseDescrition() {
    while(1) {
        cout<<"Wybirz rodzaj przychodu pienieznego:"<<endl
            <<"1. Zakupy jedzenie"<<endl
            <<"2. Transport"<<endl
            <<"3. Rachunek za pr¹d"<<endl
            <<"4. Rachunek za mieszkanie"<<endl
            <<"5. Rachunek za telefon"<<endl

            <<"6. Jedzenie w restauracji"<<endl
            <<"9. Inny"<<endl
            <<"Wybor: ";
        char choice=0;
        choice=AuxiliaryMethods::loadChar();
        switch (choice) {
        case '1':
            setDescription("Zakupy jedzenie");
            return;
            break;
        case '2':
            setDescription("Transport");
            return;
            break;
        case '3':
            setDescription("Rachunek za pr¹d");
            return;
            break;
        case '4':
            setDescription("Rachunek za mieszkanie");
            return;
            break;
        case '5':
            setDescription("Rachunek za telefon");
            return;
            break;
        case '6':
            setDescription("Jedzenie w restauracji");
            return;
            break;
        case '9':
            cout<<"Podaj opis: ";
            setDescription(AuxiliaryMethods::loadLine());
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl;
            system("pause");
            cout<<endl;
            break;
        }
    }
}

void Expense::editExpense() {
    chooseDescrition();
    changeAmountOfMoney();
    changeDate();
}
