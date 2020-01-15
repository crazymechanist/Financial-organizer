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

void UsersDataFile::saveData(vector <User> &users) {
    vector <vector<string>> data;
    for(int i=0; i<users.size(); i++) {
        vector<string> fields;
        addToVector(fields,AuxiliaryMethods::intToStringConv(users[i].getId()));
        addToVector(fields,users[i].getLogin());
        addToVector(fields,users[i].getPassword());
        addToVector(fields,users[i].getName());
        addToVector(fields,users[i].getSurname());
        data.push_back(fields);
    }
    DataFile::saveData(data);
}

void UsersDataFile::addData(User &user) {
    vector<string> data;
    addToVector(data,AuxiliaryMethods::intToStringConv(user.getId()));
    addToVector(data,user.getLogin());
    addToVector(data,user.getPassword());
    addToVector(data,user.getName());
    addToVector(data,user.getSurname());

    DataFile::addData(data);
}


