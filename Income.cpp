#include "Income.h"

Income::Income(int id):MoneyFlow(id, "Przychod") {

}

void Income::chooseDescrition() {
    while(1) {
        cout<<"Wybirz rodzaj przychodu pienieznego:"<<endl
            <<"1. Wyplata"<<endl
            <<"2. Odsetki z lokaty"<<endl
            <<"3. Sprzedaz na allegro"<<endl
            <<"9. Inny"<<endl
            <<"Wybor: ";
        char choice=0;
        choice=AuxiliaryMethods::loadChar();
        switch (choice) {
        case '1':
            setDescription("Wyplata");
            return;
            break;
        case '2':
            setDescription("Odsetki z lokaty");
            return;
            break;
        case '3':
            setDescription("Sprzedaz na allegro");
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

void Income::chooseDate() {
    while(1) {
        cout<<endl<<"Czy chcesz zmienic date? ("<<date.getDate()<<") (T/N)"<<endl;
        char choice=AuxiliaryMethods::loadChar();
        switch (choice) {
        case 'T':
            cout<<endl<<"Podaj date w formacie RRRR-MM-DD: ";
            while(!date.setDate(AuxiliaryMethods::loadLine()))        {
                cout<<endl<<"Podaj date w poprawnym formacie RRRR-MM-DD:";
            }
            return;
            break;
        case 'N':
            return;
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl;
            system("pause");
            break;
        }
    }
}

void Income::editIncome() {
    chooseDescrition();

    cout<<endl<<"Kwota: ";
    setAmountOfMoney(AuxiliaryMethods::loadFloat());

    chooseDate();
}
