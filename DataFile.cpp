#include "DataFile.h"

DataFile::DataFile(string filename):FILENAME(filename) {
    parentNodeName="AAAA";
    childNodeName="BBB";
    string secondChildNodesNames;
    addSecondChildNodesNames("A");
    addSecondChildNodesNames("B");
    addSecondChildNodesNames("C");
}

void DataFile::addSecondChildNodesNames(string name) {
    secondChildNodesNames.push_back(name);
}

void DataFile::loadData() {
//    CMarkup xml;
//    xml.Load(FILE);
//    while ( xml.FindChildElem("Date") ) {
//        string dateStr = xml.GetChildData();
//        Date tempDate(dateStr);
//        dates.push_back(tempDate);
//        xml.OutOfElem();
//    }
}

void DataFile::saveData(vector<string> &data) {
    CMarkup xml;
    xml.AddElem(parentNodeName);
    for(int i=0; i<data.size(); i++)  {
        xml.AddChildElem(childNodeName);
        xml.IntoElem();
        for(int i=0; i<secondChildNodesNames.size(); i++)  {
            xml.AddChildElem(secondChildNodesNames[i],data[i]);
        }
        xml.OutOfElem();
    }
    xml.Save(FILENAME);
}



