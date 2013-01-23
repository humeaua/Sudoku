//
//  TripleHolder.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_TripleHolder_h
#define Sudoku_TripleHolder_h

#include "Cell.h"

class TripleHolder {
protected:
    Cell &sLeft_;
    Cell &sCenter_;
    Cell &sRight_;
public:
    TripleHolder(Cell & sLeft, Cell & sCenter, Cell & sRight);
    
    virtual Cell & GetLeft();
    virtual Cell & GetCenter();
    virtual Cell & GetRight();
};

#endif
