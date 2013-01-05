//
//  ColumnHolder.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_ColumnHolder_h
#define Sudoku_ColumnHolder_h

#include "TripleHolder.h"

class ColumnHolder : public TripleHolder {
    
public:
    ColumnHolder(const Cell & sTop, const Cell & sCenter, const Cell & sBottom);
    
    const Cell & T() const;
    const Cell & C() const;
    const Cell & B() const;
};

#endif
