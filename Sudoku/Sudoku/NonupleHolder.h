//
//  NonupleHolder.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 17/02/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_NonupleHolder_h
#define Sudoku_NonupleHolder_h

#include "TripleHolder.h"

class NonupleHolder {
protected:
    Cell &s1_, &s2_, &s3_, &s4_, &s5_, &s6_, &s7_, &s8_, &s9_;
public:
    NonupleHolder();
    NonupleHolder(TripleHolder & s1, TripleHolder & s2, TripleHolder & s3);
    NonupleHolder(Cell &sCell1, Cell & sCell2, Cell & sCell3, Cell & sCell4, Cell & sCell5, Cell & sCell6, Cell & sCell7, Cell & sCell8, Cell & sCell9);
    
    virtual Cell & Get1();
    virtual Cell & Get2();
    virtual Cell & Get3();
    virtual Cell & Get4();
    virtual Cell & Get5();
    virtual Cell & Get6();
    virtual Cell & Get7();
    virtual Cell & Get8();
    virtual Cell & Get9();
};

#endif
