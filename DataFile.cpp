#include "DataFile.h"

DataFile::DataFile(string filename):FILENAME(filename) {
    parentNodeName="";
    childNodeName="";
}

void DataFile::addSecondChildNodesNames(string name) {
    secondChildNodesNames.push_back(name);
}

void DataFile::addToVector(vector<string> &fields,string fieldData) {
    fields.push_back(fieldData);
}

vector<vector<string>> DataFile::loadData() {
    CMarkup xml;
    xml.Load(FILENAME);
    vector<vector<string>> data;
    while ( xml.FindChildElem(childNodeName) ) {
        vector<string> fields;
        xml.IntoElem();
        for(int i=0; i<secondChildNodesNames.size(); i++) {
            xml.FindChildElem(secondChildNodesNames[i]);
            string field= xml.GetChildData();
            fields.push_back(field);
        }
        data.push_back(fields);
        xml.OutOfElem();
    }
    return data;
}

void DataFile::saveData(vector<vector<string>> &data) {
    if(secondChildNodesNames.size()==data[0].size()) {
        CMarkup xml;
        xml.AddElem(parentNodeName);
        for(int i=0; i<data.size(); i++)  {
            xml.AddChildElem(childNodeName);
            xml.IntoElem();
            for(int j=0; j<data[0].size(); j++)  {
                xml.AddChildElem(secondChildNodesNames[j],data[i][j]);
            }
            xml.OutOfElem();
        }
        xml.Save(FILENAME);
    }
}

void DataFile::addData(vector<string> &data) {
    CMarkup xml;
    xml.Load(FILENAME);
    int iter=0;
    while ( xml.FindChildElem(childNodeName) ) {
        iter++;
    }
    xml.AddChildElem(childNodeName);
    xml.IntoElem();
    for(int j=0; j<data.size(); j++)  {
        xml.AddChildElem(secondChildNodesNames[j],data[j]);
    }
    xml.OutOfElem();
    xml.Save(FILENAME);
}

void DataFile::deleteData (vector<string> &data) {
}

void DataFile::editData (vector<string> &data) {
}


