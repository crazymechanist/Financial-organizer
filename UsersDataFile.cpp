#include "UsersDataFile.h"

UsersDataFile::UsersDataFile(string usersDataFileName):DataFile(usersDataFileName) {
    parentNodeName="users";
    childNodeName="user";
    addSecondChildNodesNames("id");
    addSecondChildNodesNames("login");
    addSecondChildNodesNames("password");
    addSecondChildNodesNames("name");
    addSecondChildNodesNames("surname");
}

vector<User> UsersDataFile::loadData() {
    vector<vector<string>> data;
    vector<User> users;
    data=DataFile::loadData();
    for(int i=0; i<data.size(); i++) {
        User tempUser;
        tempUser.setId(AuxiliaryMethods::stringToIntConv(data[i][0]));
        tempUser.setLogin(data[i][1]);
        tempUser.setPassword(data[i][2]);
        tempUser.setName(data[i][3]);
        tempUser.setSurname(data[i][4]);
        users.push_back(tempUser);
    }
    return users;
}

vector <string> UsersDataFile::dataToVector(User &user) {
    vector<string> vec;
    addToVector(vec,AuxiliaryMethods::intToStringConv(user.getId()));
    addToVector(vec,user.getLogin());
    addToVector(vec,user.getPassword());
    addToVector(vec,user.getName());
    addToVector(vec,user.getSurname());
    return vec;
}

void UsersDataFile::saveData(vector <User> &users) {
    vector <vector<string>> data;
    for(int i=0; i<users.size(); i++) {
        vector<string> fields=dataToVector(users[i]);
        data.push_back(fields);
    }
    DataFile::saveData(data);
}

void UsersDataFile::addData(User &user) {
    vector<string> fields=dataToVector(user);
    DataFile::addData(fields);
}

bool UsersDataFile::deleteData(User &user) {
    bool isTheOperationGood=false;
    vector<string> fields=dataToVector(user);
    isTheOperationGood=DataFile::deleteData(fields);
    return isTheOperationGood;
}

bool UsersDataFile::editData (User &editedUser) {
    bool isTheOperationGood=false;
    vector<string> fields=dataToVector(editedUser);
    isTheOperationGood=DataFile::editData(fields,0);
    return isTheOperationGood;
}


