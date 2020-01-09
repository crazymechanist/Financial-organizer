#ifndef DATAFILE_H
#define DATAFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "AuxiliaryMethods.h"


using namespace std;

class DataFile {
    string childNodeName;
    string parentNodeName;
    vector<string> secondChildNodesNames;
    const string FILENAME;
    void addSecondChildNodesNames(string name);

public:
    void loadData();
    void saveData(vector<string> &sample);
    DataFile(string filename);
};

#endif
