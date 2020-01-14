#ifndef USERSDATAFILE_H
#define USERSDATAFILE_H

#include <iostream>
#include "DataFile.h"
#include "User.h"


using namespace std;

class UsersDataFile:public DataFile {
public:
    UsersDataFile(string UsersDataFileName);
    vector<User> loadData();
    void saveData(vector <User> &expenses);
};

#endif
