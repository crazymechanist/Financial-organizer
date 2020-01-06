#include <iostream>
#include "Markup.h"
#include "Date.h"
#include "User.h"
#include "UserManager.h"
#include "FinancialOrganizer.h"


using namespace std;

int main() {
    FinancialOrganizer financialOrganizer;
//zapis do pliku i wczytanie
    while(1) {
        financialOrganizer.mainMenu();
    }

    return 0;
}
