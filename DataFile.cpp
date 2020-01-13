#include "DataFile.h"

DataFile::DataFile(string filename):FILENAME(filename) {
    parentNodeName="";
    childNodeName="";
}

void DataFile::addSecondChildNodesNames(string name) {
    secondChildNodesNames.push_back(name);
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
    if(secondChildNodesNames.size()==data.size()) {
        CMarkup xml;
        xml.AddElem(parentNodeName);
        for(int i=0; i<data.size(); i++)  {
            xml.AddChildElem(childNodeName);
            xml.IntoElem();
            for(int j=0; j<data[j].size(); j++)  {
                xml.AddChildElem(secondChildNodesNames[j],data[i][j]);
            }
            xml.OutOfElem();
        }
        xml.Save(FILENAME);
    }
}



