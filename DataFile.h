#ifndef DATAFILE_H
#define DATAFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "AuxiliaryMethods.h"


using namespace std;

class DataFile {
    const string FILENAME;
protected:
    void addToVector(vector<string> &fields,string fieldData);
    string childNodeName;
    string parentNodeName;
    vector <string> secondChildNodesNames;
    void addSecondChildNodesNames(string name);
public:

    vector<vector<string>> loadData();
    void saveData(vector<vector<string>> &sample);
    void addData(vector<string> &data);
    bool deleteData (vector<string> &data);
    bool editData (vector<string> &editedElem, int indexingElement);
    DataFile(string filename);
};

#endif
