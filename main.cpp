#include <iostream>
#include <vector>
#include "FinancialOrganizer.h"


using namespace std;

int main() {
    FinancialOrganizer financialOrganizer;
    while(1) {
        financialOrganizer.mainMenu();
    }

    return 0;
}

//int main() {
//    User user;
//    vector<User> users;
//    UsersDataFile usersDataFile("users.xml");
//    users=usersDataFile.loadData();
//    usersDataFile.addData(user);
//    return 0;
//}
