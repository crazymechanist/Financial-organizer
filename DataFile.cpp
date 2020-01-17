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

vector<vector<string>> DataFile::loadCertainData(int fieldNumber, string fieldContents) {
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
        if (fieldNumber>0&&fieldNumber<=fields.size()) {
            if(fieldContents==fields[fieldNumber-1]) {
                data.push_back(fields);
            }
        }
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

bool DataFile::deleteData (vector<string> &deletedElem) {
    CMarkup oldXml,newXml;
    bool isTheOperationGood=false;
    oldXml.Load(FILENAME);
    newXml.AddElem(parentNodeName);
    while ( oldXml.FindChildElem(childNodeName) ) {
        vector<string> elem;
        oldXml.IntoElem();
        for(int i=0; i<secondChildNodesNames.size(); i++) {
            oldXml.FindChildElem(secondChildNodesNames[i]);
            string field= oldXml.GetChildData();
            elem.push_back(field);
        }
        oldXml.OutOfElem();
        if(elem==deletedElem) {
            isTheOperationGood=true;
        } else {
            newXml.AddChildElem(childNodeName);
            newXml.IntoElem();
            for(int i=0; i<secondChildNodesNames.size(); i++)  {
                newXml.AddChildElem(secondChildNodesNames[i],elem[i]);
            }
            newXml.OutOfElem();
        }
    }
    newXml.Save(FILENAME);
    return isTheOperationGood;
}

bool DataFile::editData (vector<string> &editedElem, int indexingElement) {
    if(editedElem.size()-1>=indexingElement) {
        CMarkup oldXml,newXml;
        bool isTheOperationGood=false;
        oldXml.Load(FILENAME);
        newXml.AddElem(parentNodeName);
        while ( oldXml.FindChildElem(childNodeName) ) {
            vector<string> elem;
            oldXml.IntoElem();
            for(int i=0; i<secondChildNodesNames.size(); i++) {
                oldXml.FindChildElem(secondChildNodesNames[i]);
                string field= oldXml.GetChildData();
                elem.push_back(field);
            }
            oldXml.OutOfElem();
            if(elem[indexingElement]==editedElem[indexingElement]) {
                newXml.AddChildElem(childNodeName);
                newXml.IntoElem();
                for(int i=0; i<secondChildNodesNames.size(); i++)  {
                    newXml.AddChildElem(secondChildNodesNames[i],editedElem[i]);
                }
                newXml.OutOfElem();
                isTheOperationGood=true;
            } else {
                newXml.AddChildElem(childNodeName);
                newXml.IntoElem();
                for(int i=0; i<secondChildNodesNames.size(); i++)  {
                    newXml.AddChildElem(secondChildNodesNames[i],elem[i]);
                }
                newXml.OutOfElem();
            }
        }
        newXml.Save(FILENAME);
        return isTheOperationGood;
    } else {
        return false;
    }

}


