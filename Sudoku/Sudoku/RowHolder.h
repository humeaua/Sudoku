//
//  RowHolder.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_RowHolder_h
#define Sudoku_RowHolder_h

#include "TripleHolder.h"

class RowHolder : public TripleHolder{
    
public:
    RowHolder(Cell & sG, Cell & sC, Cell & sD);
    
    virtual Cell & G();
    virtual Cell & D();
    virtual Cell & C();
    virtual bool isConsistent();
};

#endif
