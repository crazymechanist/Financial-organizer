#ifndef USERSDATAFILE_H
#define USERSDATAFILE_H

#include <iostream>
#include "DataFile.h"
#include "User.h"


using namespace std;

class UsersDataFile:public DataFile {
    vector <string> dataToVector(User &user);
public:
    UsersDataFile(string UsersDataFileName);
    vector<User> loadData();
    void saveData(vector <User> &expenses);
    void addData(User &user);
    bool deleteData (User &user);
    bool editData (User &editedUser);
};

#endif
