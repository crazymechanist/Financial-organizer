#ifndef DATAFILE_H
#define DATAFILE_H

#include <iostream>
#include "Markup.h"


using namespace std;

class DataFile {

    const string FILENAME;

public:

    virtual void loadData()=0;
    virtual void saveData()=0;
    DataFile(string filename):FILENAME(filename) {
//empty constructor body
    }


};

#endif
