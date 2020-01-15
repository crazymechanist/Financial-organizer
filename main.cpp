#include <iostream>
#include <vector>
#include "FinancialOrganizer.h"


using namespace std;

//int main() {
//    FinancialOrganizer financialOrganizer;
//    while(1) {
//        financialOrganizer.mainMenu();
//    }
//    return 0;
//}
//
int main() {
    User user(3,"Korwin","Mikke","J","Krol");
    vector<User> users;
    UsersDataFile usersDataFile("users.xml");
//    usersDataFile.addData(user);
//   usersDataFile.deleteData(user);
//    usersDataFile.loadData();
   usersDataFile.editData(user);
    return 0;
}
