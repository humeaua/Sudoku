//
//  LastCellFinder.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 10/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_LastCellFinder_h
#define Sudoku_LastCellFinder_h

#include "TripleHolder.h"
#include <vector>

class LastCellFinder {
protected:
    TripleHolder &s1_, &s2_, &s3_;
public:
    LastCellFinder(TripleHolder & s1, TripleHolder & s2, TripleHolder & s3);
    bool fill();
    
    std::pair<std::vector<unsigned int>, std::vector<unsigned int> > EmptyCells();
};

#endif
