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
    Cell sLeft_, sCenter_, sRight_;
public:
    TripleHolder(const Cell & sLeft, const Cell & sCenter, const Cell & sRight);
    
    const Cell & GetLeft() const;
    const Cell & GetCenter() const;
    const Cell & GetRight() const;
};

#endif
