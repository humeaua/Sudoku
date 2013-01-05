//
//  Cell.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 04/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_Cell_h
#define Sudoku_Cell_h

#include <iostream>

class Cell
{
protected:
    unsigned int iValue_;
    bool bIsEmpty_;
public:
    Cell();
    Cell(const unsigned int iValue);
    virtual ~Cell();
    
    virtual bool IsEmpty() const;
    
    virtual Cell & operator=(unsigned int iValue);
    virtual operator unsigned int() const;
    virtual bool operator==( unsigned int iValue) const;
};

#endif
