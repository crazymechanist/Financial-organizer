#ifndef DATAFILE_H
#define DATAFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Markup.h"
#include "AuxiliaryMethods.h"


using namespace std;

class DataFile {
    const string FILENAME;
    bool isTheFileEmpty();
protected:
    void saveData(vector<vector<string>> &sample);
    void addToVector(vector<string> &fields,string fieldData);
    string childNodeName;
    string parentNodeName;
    vector <string> secondChildNodesNames;
    void addSecondChildNodesNames(string name);
    vector<vector<string>> loadData();
    vector<vector<string>> loadCertainData(int fieldNumber, string fieldContents);
    vector<string> loadCertainFields(int fieldNumber);

    void addData(vector<string> &data);
    bool deleteData (vector<string> &data);
    bool editData (vector<string> &editedElem, int indexingElement);
public:
    DataFile(string filename);
};

#endif
