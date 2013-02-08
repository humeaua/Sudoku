//
//  TripleHolder.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_TripleHolder_h
#define Sudoku_TripleHolder_h

#include <vector>
#include "Cell.h"
#include "ValueEliminator.h"

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
    
    virtual void flagValues(ValueEliminator & sValueEliminator) const;
    virtual bool isValuePresent(unsigned int iValue) const;
    virtual std::vector<int> indexEmpty();

};

#endif
