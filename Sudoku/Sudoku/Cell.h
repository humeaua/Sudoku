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
    std::size_t iValue_;
    bool bIsEmpty_;
public:
    Cell();
    Cell(const std::size_t iValue);
    virtual ~Cell();
};

#endif
