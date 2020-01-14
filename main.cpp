#include <iostream>
#include <vector>
#include "FinancialOrganizer.h"


using namespace std;

int main() {
    vector<User> users;
//    User tempUser(1, "ala", "ala1","Alicja","Z Krainy Czarow");
//    users.push_back(tempUser);
//    tempUser.edit(2, "tomek", "tomek1","Tomasz","Wilmowski");
//    users.push_back(tempUser);
    UsersDataFile usersDataFile("users.xml");
//    usersDataFile.saveData(users);
    users=usersDataFile.loadData();
    return 0;
}

