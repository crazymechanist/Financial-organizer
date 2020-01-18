
#include <iostream>
#include "Income.h"

class Comparator {
    bool operator() (Income firstIncome,Income secondIncome) {
        return firstIncome.getDate() < secondIncome.getDate();
    }
    friend struct _Iter_comp_iter;
} comparator;
