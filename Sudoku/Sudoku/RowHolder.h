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
    RowHolder(const Cell & sG, const Cell & sC, const Cell & sD);
    
    virtual const Cell & G() const;
    virtual const Cell & D() const;
    virtual const Cell & C() const;
};

#endif
