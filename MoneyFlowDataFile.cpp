#include "MoneyFlowDatafile.h"

MoneyFlowDatafile::MoneyFlowDatafile(string MoneyFlowsDataFileName,string parentNodeName, string childNodeName):DataFile(MoneyFlowsDataFileName) {
    this->parentNodeName=parentNodeName;
    this->childNodeName=childNodeName;
    addSecondChildNodesNames("id");
    addSecondChildNodesNames("userId");
    addSecondChildNodesNames("description");
    addSecondChildNodesNames("amount");
    addSecondChildNodesNames("date");
}

vector<MoneyFlow> MoneyFlowDatafile::loadAllMoneyFlows() {
    vector<vector<string>> data;
    vector<MoneyFlow> moneyFlows;
    data=DataFile::loadData();
    moneyFlows=vectToData(data);
    return moneyFlows;
}

vector<MoneyFlow> MoneyFlowDatafile::loadMoneyFlowsOfOneUser(int userId) {
    vector<vector<string>> data;
    vector<MoneyFlow> moneyFlows;
    data=DataFile::loadCertainData(2,AuxiliaryMethods::intToStringConv(userId));
    moneyFlows=vectToData(data);
    return moneyFlows;
}

vector <MoneyFlow> MoneyFlowDatafile::vectToData(vector<vector<string>> &data) {
    vector<MoneyFlow> moneyFlows;
    for(int i=0; i<data.size(); i++) {
        MoneyFlow tempMoneyFlow;
        int j=0;
        tempMoneyFlow.setId(AuxiliaryMethods::stringToIntConv(data[i][j++]));
        tempMoneyFlow.setIdOfOwnUser(AuxiliaryMethods::stringToIntConv(data[i][j++]));
        tempMoneyFlow.setDescription(data[i][j++]);
        tempMoneyFlow.setAmountOfMoney(AuxiliaryMethods::stringToFloatConv(data[i][j++]));
        tempMoneyFlow.setDate(data[i][j++]);
        moneyFlows.push_back(tempMoneyFlow);
    }
    return moneyFlows;
}

vector <string> MoneyFlowDatafile::dataToVector(MoneyFlow &expense) {
    vector<string> vec;
    addToVector(vec,AuxiliaryMethods::intToStringConv(expense.getId()));
    addToVector(vec,AuxiliaryMethods::intToStringConv(expense.getIdOfOwnUser()));
    addToVector(vec,expense.getDescription());
    addToVector(vec,AuxiliaryMethods::floatToStringConv(expense.getAmountOfMoney()));
    addToVector(vec,expense.getDateSign());
    return vec;
}

void MoneyFlowDatafile::saveData(vector <MoneyFlow> &moneyFlows) {
    vector <vector<string>> data;
    for(int i=0; i<moneyFlows.size(); i++) {
        vector<string> fields=dataToVector(moneyFlows[i]);
        data.push_back(fields);
    }
    DataFile::saveData(data);
}

void MoneyFlowDatafile::addData(MoneyFlow &expense) {
    vector<string> fields=dataToVector(expense);
    DataFile::addData(fields);
}

bool MoneyFlowDatafile::deleteData (MoneyFlow &expense) {
    bool isTheOperationGood=false;
    vector<string> fields=dataToVector(expense);
    isTheOperationGood=DataFile::deleteData(fields);
    return isTheOperationGood;
}

bool MoneyFlowDatafile::editData (MoneyFlow &editedMoneyFlow) {
    bool isTheOperationGood=false;
    vector<string> fields=dataToVector(editedMoneyFlow);
    isTheOperationGood=DataFile::editData(fields,0);
    return isTheOperationGood;
}

int MoneyFlowDatafile::getLastMoneyFlowId() {
    vector<string> fields;
    fields=DataFile::loadCertainFields(0);
    int lastId=0;
    for(int i=0; i<fields.size(); i++) {
        int currId=AuxiliaryMethods::stringToIntConv(fields[i]);
        if(currId>lastId) {
            lastId=currId;
        }
    }
    return lastId;
}

